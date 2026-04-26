/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfeijoei <sfeijoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:44:29 by sfeijoei          #+#    #+#             */
/*   Updated: 2026/04/24 11:04:35 by sfeijoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static char	*increment_lvl(char *line)
{
	int		level;
	char	*tmp;
	char	*new;
	char	*numb;

	tmp = ft_strchr(line, '=');
	if (!tmp || !*(tmp + 1))
		level = 0;
	else
		level = ft_atoi(tmp + 1);
	level++;
	numb = ft_itoa(level);
	if (!numb)
		return (NULL);
	new = ft_strjoin("SHLVL=", numb);
	free(numb);
	if (!new)
		return (NULL);
	return (new);
}

t_env	*set_env(char **env)
{
	t_env	*head;
	t_env	*current;
	t_env	*node;
	int		i;

	head = NULL;
	current = NULL;
	i = 0;
	while (env[i])
	{
		node = ft_calloc(1, sizeof(t_env));
		if (!node)
			return (NULL);
		if (!ft_strncmp(env[i], "SHLVL=", 6))
			node->value = increment_lvl(env[i]);
		else
			node->value = ft_strdup(env[i]);
		if (!head)
			head = node;
		else
			current->next = node;
		current = node;
		i++;
	}
	return (head);
}
