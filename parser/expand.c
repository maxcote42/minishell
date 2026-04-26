/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfeijoei <sfeijoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:34:15 by sfeijoei          #+#    #+#             */
/*   Updated: 2026/04/24 22:01:20 by sfeijoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static bool	should_skip_empty_expansion(char *original, char *expanded)
{
	int		i;
	bool	has_dollar;

	if (!original || !expanded || expanded[0] != '\0')
		return (false);
	i = 0;
	has_dollar = false;
	while (original[i])
	{
		if (original[i] == '\'' || original[i] == '"')
			return (false);
		if (original[i] == '$')
			has_dollar = true;
		i++;
	}
	return (has_dollar);
}

void	normal_char(char **result, char c)
{
	char	tmp[2];
	char	*new;

	tmp[0] = c;
	tmp[1] = '\0';
	new = ft_strjoin(*result, tmp);
	free(*result);
	*result = new;
}

static void	handle_quote(char *str, int *i, t_quote_type *quote)
{
	if (str[*i] == '\'' && *quote == NONE)
		*quote = SINGLE;
	else if (str[*i] == '\'' && *quote == SINGLE)
		*quote = NONE;
	else if (str[*i] == '"' && *quote == NONE)
		*quote = DOUBLE;
	else if (str[*i] == '"' && *quote == DOUBLE)
		*quote = NONE;
	(*i)++;
}

static char	*expand_str(char *str, t_exec *pipex)
{
	char			*result;
	t_quote_type	quote;
	int				i;

	result = ft_strdup("");
	quote = NONE;
	i = 0;
	while (str[i])
	{
		if ((str[i] == '\'' && quote != DOUBLE)
			|| (str[i] == '"' && quote != SINGLE))
			handle_quote(str, &i, &quote);
		else if (str[i] == '$' && quote != SINGLE)
			result = handle_dollar(result, str, &i, pipex);
		else
			(normal_char(&result, str[i++]));
	}
	return (result);
}

void	expand(t_exec *pipex)
{
	int		i;
	int		j;
	int		k;
	char	*original;
	char	*expanded;

	i = -1;
	while (++i < pipex->cmd_count)
	{
		j = -1;
		k = 0;
		while (pipex->cmds[i].args && pipex->cmds[i].args[++j])
		{
			original = pipex->cmds[i].args[j];
			expanded = expand_str(original, pipex);
			if (should_skip_empty_expansion(original, expanded))
				free(expanded);
			else
				pipex->cmds[i].args[k++] = expanded;
			free(original);
		}
		if (pipex->cmds[i].args)
			pipex->cmds[i].args[k] = NULL;
	}
}
