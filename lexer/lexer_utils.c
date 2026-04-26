/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfeijoei <sfeijoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 12:06:32 by sfeijoei          #+#    #+#             */
/*   Updated: 2026/04/24 12:30:39 by sfeijoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

bool	is_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (true);
	return (false);
}

void	ft_lstadd_back_token(t_token **lst, t_token *new)
{
	t_token	*current;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
	new->prev = current;
}

bool	is_quote_ok(t_token *head, char *line)
{
	if (head && get_quote_state(line) != NONE)
	{
		ft_putstr_fd
		("minishell: unexpected EOF while looking for matching quote\n", 2);
		free_tokens(head);
		return (false);
	}
	return (true);
}

t_token_type	get_token_type(char *line, int i)
{
	if (line[i] == '|' && line[i + 1] == '|')
		return (DOUBLE_PIPE);
	if (line[i] == '|')
		return (PIPE);
	if (line[i] == '<' && line[i + 1] == '>')
		return (BIDIREC);
	if (line[i] == '<' && line[i + 1] == '<')
		return (HEREDOC);
	if (line[i] == '>' && line[i + 1] == '>')
		return (REDIR_APPEND);
	if (line[i] == '<')
		return (REDIR_IN);
	if (line[i] == '>')
		return (REDIR_OUT);
	if (line[i] == '&' && line[i + 1] == '&')
		return (AMPERSAND_D);
	if (line[i] == '&')
		return (AMPERSAND);
	return (WORD);
}
