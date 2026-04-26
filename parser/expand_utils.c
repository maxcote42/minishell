/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfeijoei <sfeijoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:40:26 by sfeijoei          #+#    #+#             */
/*   Updated: 2026/04/18 13:45:39 by sfeijoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	get_var_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (i);
}

char	*expand_dollar_question(char *result, t_exec *pipex)
{
	char	*status_str;
	char	*tmp;

	status_str = ft_itoa(pipex->last_status);
	tmp = ft_strjoin(result, status_str);
	free(result);
	free(status_str);
	return (tmp);
}

char	*expand_var(char *result, char *str, int *i, t_exec *pipex)
{
	char	*var_name;
	char	*var_val;
	char	*tmp;
	int		len;

	len = get_var_len(str + *i);
	var_name = ft_substr(str, *i, len);
	var_val = get_env_value(pipex->env, var_name);
	free(var_name);
	if (var_val)
		tmp = ft_strjoin(result, var_val);
	else
		tmp = ft_strdup(result);
	free(result);
	*i += len;
	return (tmp);
}

char	*handle_dollar(char *result, char *str, int *i, t_exec *pipex)
{
	char	*tmp;

	(*i)++;
	if (str[*i] == '?')
	{
		result = expand_dollar_question(result, pipex);
		(*i)++;
	}
	else if (ft_isalpha(str[*i]) || str[*i] == '_')
		result = expand_var(result, str, i, pipex);
	else
	{
		tmp = ft_strjoin(result, "$");
		free(result);
		result = tmp;
	}
	return (result);
}
