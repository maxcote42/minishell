/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfeijoei <sfeijoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 00:48:35 by sfeijoei          #+#    #+#             */
/*   Updated: 2026/04/24 12:20:29 by sfeijoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	get_text_len(char *line, int i)
{
	t_quote_type	quote;
	int				j;

	j = i;
	quote = NONE;
	while (line[j] != '\0')
	{
		if (line[j] == '\'' && quote == NONE)
			quote = SINGLE;
		else if (line[j] == '\"' && quote == NONE)
			quote = DOUBLE;
		else if (line[j] == '\'' && quote == SINGLE)
			quote = NONE;
		else if (line[j] == '\"' && quote == DOUBLE)
			quote = NONE;
		else if ((line[j] == ' ' || line[j] == '|'
				|| line[j] == '<' || line[j] == '>') && quote == NONE)
			break ;
		j++;
	}
	return (j - i);
}

t_quote_type	get_quote_state(char *str)
{
	t_quote_type	state;
	int				i;

	state = NONE;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' && state == NONE)
			state = SINGLE;
		else if (str[i] == '\'' && state == SINGLE)
			state = NONE;
		else if (str[i] == '"' && state == NONE)
			state = DOUBLE;
		else if (str[i] == '"' && state == DOUBLE)
			state = NONE;
		i++;
	}
	return (state);
}

static void	fill_word_token(t_token *token, char *line, int *i)
{
	int	len;

	len = get_text_len(line, *i);
	token->text = ft_substr(line, *i, len);
	token->type = WORD;
	token->quote = get_quote_state(token->text);
	*i += len;
}

static void	fill_other_token(t_token *token, char *line, int *i)
{
	token->type = get_token_type(line, *i);
	if (token->type == HEREDOC || token->type == REDIR_APPEND
		|| token->type == DOUBLE_PIPE || token->type == AMPERSAND_D
		|| token->type == BIDIREC)
	{
		token->text = ft_substr(line, *i, 2);
		*i += 2;
	}
	else
	{
		token->text = ft_substr(line, *i, 1);
		*i += 1;
	}
}

t_token	*tokenize(char *line)
{
	t_token	*head;
	t_token	*token;
	int		i;

	head = NULL;
	i = 0;
	while (line[i] != '\0')
	{
		while (line[i] != '\0' && is_separator(line[i]) == true)
			i++;
		if (line[i] == '\0')
			break ;
		token = ft_calloc(1, sizeof(t_token));
		if (get_token_type(line, i) == WORD)
			fill_word_token(token, line, &i);
		else
			fill_other_token(token, line, &i);
		ft_lstadd_back_token(&head, token);
	}
	if (is_quote_ok(head, line) == false)
		return (NULL);
	return (head);
}
