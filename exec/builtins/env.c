/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:07:08 by maxcote           #+#    #+#             */
/*   Updated: 2026/04/09 18:07:10 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	exec_env(t_env *envp, char **cmd)
{
	t_env	*tmp;
	int		i;

	i = 1;
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], "env"))
		{
			ft_putstr_fd("env: '", 2);
			ft_putstr_fd(cmd[i], 2);
			ft_putstr_fd("': No such file or directory'\n", 2);
			return (127);
		}
		i++;
	}
	tmp = envp;
	while (tmp)
	{
		ft_putstr_fd(tmp->value, 1);
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
	return (0);
}
