/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:10:14 by maxcote           #+#    #+#             */
/*   Updated: 2026/04/09 18:10:15 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	count_arg(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

// x=0: pour les export
// x=1: pour les unset
int	is_valid_identifier(char *cmd, int x)
{
	int	i;

	if (!cmd)
		return (0);
	if (!ft_isalpha(cmd[0]) && cmd[0] != '_')
		return (0);
	i = 1;
	while (cmd[i])
	{
		if (cmd[i] == '=' && x == 0)
			return (1);
		if (!ft_isalnum(cmd[i]) && cmd[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

char	*get_env_value(t_env *env, char *key)
{
	t_env		*tmp;
	size_t		key_len;

	tmp = env;
	key_len = ft_strlen(key);
	while (tmp)
	{
		if (!ft_strncmp(tmp->value, key, key_len) && tmp->value[key_len] == '=')
			return (tmp->value + key_len + 1);
		tmp = tmp->next;
	}
	return (NULL);
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
