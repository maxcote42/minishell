/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:16:33 by maxcote           #+#    #+#             */
/*   Updated: 2026/04/14 18:16:35 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	ft_dup(t_exec *exec, t_cmd *cmd, int i)
{
	int	infile;
	int	outfile;

	infile = cmd->infile;
	outfile = cmd->outfile;
	if (infile == -1 && i > 0)
		infile = get_pipe(exec, 1)[0];
	if (outfile == -1 && (i < (exec->cmd_count - 1)))
		outfile = get_pipe(exec, 0)[1];
	if (infile != -1)
	{
		if (dup2(infile, 0) < 0)
			return (perror("minishell: dup2"), 1);
	}
	if (outfile != -1)
	{
		if (dup2(outfile, 1) < 0)
			return (perror("minishell: dup2"), 1);
	}
	return (0);
}

static int	open_redir(t_redir *redir)
{
	int	fd;

	if (redir->type == REDIR_IN)
		fd = open(redir->file, O_RDONLY);
	else if (redir->type == REDIR_OUT)
		fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(redir->file, 2);
		ft_putstr_fd(": ", 2);
		perror("");
	}
	return (fd);
}

static void	new_redir(t_cmd *cmd, int fd, t_token_type type)
{
	if (type == REDIR_IN || type == HEREDOC)
	{
		if (cmd->infile != -1)
			close(cmd->infile);
		cmd->infile = fd;
	}
	else
	{
		if (cmd->outfile != -1)
			close(cmd->outfile);
		cmd->outfile = fd;
	}
}

static void	close_redir(t_cmd *cmd)
{
	if (cmd->outfile != -1)
	{
		close(cmd->outfile);
		cmd->outfile = -1;
	}
	if (cmd->infile != -1)
	{
		close(cmd->infile);
		cmd->infile = -1;
	}
}

int	plug_redirs(t_cmd *cmd)
{
	int	i;
	int	fd;

	i = -1;
	while (++i < cmd->redir_count)
	{
		if (cmd->redirs[i].type == HEREDOC)
		{
			fd = cmd->redirs[i].fd_heredoc;
			cmd->redirs[i].fd_heredoc = -1;
		}
		else
			fd = open_redir(&cmd->redirs[i]);
		if (fd == -1)
			return (close_redir(cmd), 1);
		new_redir(cmd, fd, cmd->redirs[i].type);
	}
	return (0);
}
