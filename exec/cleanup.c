/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:09:29 by maxcote           #+#    #+#             */
/*   Updated: 2026/04/09 18:09:30 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	*free_partial_tab(char **tab, int size)
{
	while (size > 0)
		free(tab[--size]);
	free(tab);
	return (NULL);
}

void	close_all_exec(t_exec *exec)
{
	if (exec->pipe_a[0] >= 0)
	{
		close(exec->pipe_a[0]);
		exec->pipe_a[0] = -1;
	}
	if (exec->pipe_a[1] >= 0)
	{
		close(exec->pipe_a[1]);
		exec->pipe_a[1] = -1;
	}
	if (exec->pipe_b[0] >= 0)
	{
		close(exec->pipe_b[0]);
		exec->pipe_b[0] = -1;
	}
	if (exec->pipe_b[1] >= 0)
	{
		close(exec->pipe_b[1]);
		exec->pipe_b[1] = -1;
	}
}

void	free_redirs(t_redir *redirs, int count)
{
	int	i;

	if (!redirs)
		return ;
	i = 0;
	while (i < count)
	{
		if (redirs[i].type == HEREDOC && redirs[i].fd_heredoc != -1)
		{
			close (redirs[i].fd_heredoc);
			redirs[i].fd_heredoc = -1;
		}
		free(redirs[i].file);
		i++;
	}
	free(redirs);
}

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	free_tab(cmd->args);
	free(cmd->path);
	if (cmd->infile != -1)
	{
		close(cmd->infile);
		cmd->infile = -1;
	}
	if (cmd->outfile != -1)
	{
		close(cmd->outfile);
		cmd->outfile = -1;
	}
	free_redirs(cmd->redirs, cmd->redir_count);
}

void	cleanup(t_exec *exec)
{
	int	i;

	if (!exec)
		return ;
	close_all_exec(exec);
	if (exec->cmds)
	{
		i = 0;
		while (i < exec->cmd_count)
		{
			free_cmd(&exec->cmds[i]);
			i++;
		}
		free(exec->cmds);
	}
	free(exec->pid);
	free_tab(exec->paths);
	free_tab(exec->envp);
	init_struc(exec);
}
