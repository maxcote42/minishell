/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfeijoei <sfeijoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:33:57 by sfeijoei          #+#    #+#             */
/*   Updated: 2026/04/24 12:30:08 by sfeijoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

bool	is_redir(t_token *token)
{
	if (token->type == REDIR_APPEND || token->type == REDIR_OUT
		|| token->type == REDIR_IN || token->type == HEREDOC
		||token->type == BIDIREC)
		return (true);
	return (false);
}

bool	is_syntax_valid(t_token *head)
{
	if (first_token_error(head) == true)
		return (syntax_error(get_token_str(head->type)));
	while (head)
	{
		if (head->type == BIDIREC)
			return (ft_putstr_fd("minishell: `<>\" not handled\n", 2), false);
		if (head->next == NULL)
		{
			if (head->type == PIPE)
				return (syntax_error("|"));
			if (is_redir(head))
				return (syntax_error("newline"));
			break ;
		}
		if (head->type == PIPE && head->next->type == PIPE)
			return (syntax_error("|"));
		if (is_redir(head) && head->next->type == PIPE)
			return (syntax_error("|"));
		if (is_redir(head) && is_redir(head->next))
			return (syntax_error(get_token_str(head->next->type)));
		if (head->type == AMPERSAND || head->type == AMPERSAND_D)
			return (syntax_error(get_token_str(head->type)));
		head = head->next;
	}
	return (true);
}

static void	init_pipe_cmd(t_token *head, t_exec *pipex, int i)
{
	pipex->cmds[i].args = ft_calloc(count_args(head->next) + 1, sizeof(char *));
	pipex->cmds[i].redirs = ft_calloc
		(count_redirs(head->next), sizeof(t_redir));
}

static void	init_indexes(int *j, int *k, int *i)
{
	*j = -1;
	*k = 0;
	*i = 0;
}

void	parser(t_token *head, t_exec *pipex)
{
	int		i;
	int		j;
	int		k;

	init_parsing(head, pipex);
	init_indexes(&j, &k, &i);
	while (head)
	{
		if (head->type == WORD)
			pipex->cmds[i].args[++j] = ft_strdup(head->text);
		if (head->type == PIPE)
		{
			i++;
			j = -1;
			k = 0;
			init_pipe_cmd(head, pipex, i);
		}
		if (is_redir(head))
		{
			fill_redir_cmd(head, pipex, i, &k);
			head = head->next;
		}
		head = head->next;
	}
}
