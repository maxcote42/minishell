/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:06:44 by maxcote           #+#    #+#             */
/*   Updated: 2026/04/09 18:06:46 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int	solo_export(t_env *envp)
{
	t_env	*tmp;
	int		i;

	tmp = envp;
	while (tmp)
	{
		i = 0;
		ft_putstr_fd("export ", 1);
		while (tmp->value[i] && tmp->value[i] != '=')
			ft_putchar_fd(tmp->value[i++], 1);
		if (tmp->value[i] == '=')
		{
			ft_putstr_fd("=\"", 1);
			i++;
			while (tmp->value[i])
				ft_putchar_fd(tmp->value[i++], 1);
			ft_putstr_fd("\"", 1);
		}
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_strcmp_key(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] != '=' && s2[i] && s2[i] != '=')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if ((s1[i] == '=' || s1[i] == '\0') && (s2[i] == '=' || s2[i] == '\0'))
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	new_export(t_env **envp, char *cmd)
{
	t_env	*tmp;
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (1);
	new->value = ft_strdup(cmd);
	if (!new->value)
	{
		free (new);
		return (1);
	}
	new->next = NULL;
	if (!*envp)
	{
		*envp = new;
		return (0);
	}
	tmp = *envp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}

int	export_core(t_env **envp, char *cmd)
{
	t_env	*tmp;
	char	*new;

	if (!envp)
		return (1);
	tmp = *envp;
	while (tmp)
	{
		if (!ft_strcmp_key(cmd, tmp->value))
		{
			if (!ft_strchr(cmd, '='))
				return (0);
			new = ft_strdup(cmd);
			if (!new)
				return (1);
			free(tmp->value);
			tmp->value = new;
			return (0);
		}
		tmp = tmp->next;
	}
	return (new_export(envp, cmd));
}

int	exec_export(t_env **envp, char **cmd)
{
	int		i;
	int		ret;

	ret = 0;
	if (!cmd[1])
		return (solo_export(*envp));
	i = 1;
	while (cmd[i])
	{
		if (!is_valid_identifier(cmd[i], 0))
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(cmd[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			ret = 1;
		}
		else if (export_core(envp, cmd[i]) == 1)
		{
			ft_putstr_fd("minishell: export: malloc error\n", 2);
			return (1);
		}
		i++;
	}
	return (ret);
}
