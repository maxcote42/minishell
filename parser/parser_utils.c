/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfeijoei <sfeijoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 21:27:12 by sfeijoei          #+#    #+#             */
/*   Updated: 2026/04/24 13:34:21 by sfeijoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	count_redirs(t_token *head)
{
	int	redirs_count;

	redirs_count = 0;
	while (head)
	{
		if (head->type == PIPE)
			break ;
		if (head->type == REDIR_APPEND || head->type == REDIR_OUT
			|| head->type == REDIR_IN || head->type == HEREDOC)
			redirs_count++;
		head = head->next;
	}
	return (redirs_count);
}

int	count_args(t_token *head)
{
	int	count;

	count = 0;
	while (head)
	{
		if (head->type == PIPE)
			break ;
		if (head->type == WORD)
			count++;
		head = head->next;
	}
	return (count);
}

void	init_parsing(t_token *head, t_exec *pipex)
{
	int	i;

	i = 0;
	pipex->cmd_count = count_cmd(head);
	pipex->cmds = ft_calloc(pipex->cmd_count, sizeof(t_cmd));
	while (i < pipex->cmd_count)
	{
		init_cmd(&pipex->cmds[i]);
		i++;
	}
	pipex->cmds[0].args = ft_calloc(count_args(head) + 1, sizeof(char *));
	pipex->cmds[0].redirs = ft_calloc(count_redirs(head), sizeof(t_redir));
}

void	fill_redir_cmd(t_token *head, t_exec *pipex, int i, int *k)
{
	pipex->cmds[i].redirs[*k].type = head->type;
	if (head->type == HEREDOC)
	{
		pipex->cmds[i].redirs[*k].heredoc_expand = !has_quotes
			(head->next->text);
		pipex->cmds[i].redirs[*k].file = strip_quotes(head->next->text);
	}
	else
		pipex->cmds[i].redirs[*k].file = ft_strdup(head->next->text);
	pipex->cmds[i].redirs[*k].fd_heredoc = -1;
	pipex->cmds[i].redir_count++;
	(*k)++;
}

bool	first_token_error(t_token *head)
{
	if (head->type == PIPE || head->type == DOUBLE_PIPE
		|| head->type == AMPERSAND || head->type == AMPERSAND_D
		|| head->type == BIDIREC)
		return (true);
	return (false);
}
