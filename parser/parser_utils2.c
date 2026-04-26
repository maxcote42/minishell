/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfeijoei <sfeijoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:17:13 by sfeijoei          #+#    #+#             */
/*   Updated: 2026/04/24 12:24:17 by sfeijoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*get_token_str(int type)
{
	if (type == PIPE)
		return ("|");
	if (type == DOUBLE_PIPE)
		return ("||");
	if (type == AMPERSAND)
		return ("&");
	if (type == AMPERSAND_D)
		return ("&&");
	if (type == REDIR_IN)
		return ("<");
	if (type == REDIR_OUT)
		return (">");
	if (type == REDIR_APPEND)
		return (">>");
	if (type == HEREDOC)
		return ("<<");
	return ("newline");
}

bool	syntax_error(char *token)
{
	char	*msg;
	char	*tmp;

	tmp = ft_strjoin("minishell: syntax error near unexpected token `", token);
	msg = ft_strjoin(tmp, "'\n");
	free(tmp);
	if (!msg)
		return (false);
	ft_putstr_fd(msg, 2);
	free(msg);
	return (false);
}

int	has_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

char	*strip_quotes(char *str)
{
	char	*clean;
	int		i;
	int		j;

	clean = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!clean)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '"')
			clean[j++] = str[i];
		i++;
	}
	return (clean);
}

int	count_cmd(t_token *head)
{
	t_token	*current;
	int		cmd_count;

	cmd_count = 0;
	current = head;
	while (current)
	{
		if (current->type == PIPE)
			cmd_count++;
		current = current->next;
	}
	return (cmd_count + 1);
}
