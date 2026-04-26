/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:06:21 by maxcote           #+#    #+#             */
/*   Updated: 2026/04/14 18:06:23 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static int	fill_envp(t_env *env, char **envp)
{
	int	i;

	i = 0;
	while (env)
	{
		envp[i] = ft_strdup(env->value);
		if (!envp[i])
			return (free_partial_tab(envp, i), 1);
		env = env->next;
		i++;
	}
	envp[i] = NULL;
	return (0);
}

int	update_env(t_exec *exec)
{
	int		i;
	t_env	*tmp;

	if (!exec)
		return (1);
	if (exec->envp)
		free_tab(exec->envp);
	tmp = exec->env;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	exec->envp = malloc(sizeof(char *) * (i + 1));
	if (!exec->envp)
		return (perror("minishell"), 1);
	if (fill_envp(exec->env, exec->envp))
		return (perror("minishell"), 1);
	return (0);
}

int	find_env_path(t_exec *exec)
{
	char	*path;

	if (!exec || !exec->env)
		return (0);
	path = get_env_value(exec->env, "PATH");
	if (!path)
		return (0);
	if (exec->paths)
	{
		free_tab(exec->paths);
		exec->paths = NULL;
	}
	exec->paths = ft_split(path, ':');
	if (!exec->paths)
	{
		ft_putstr_fd("minishell: error: malloc failed\n", 2);
		return (-1);
	}
	return (0);
}
