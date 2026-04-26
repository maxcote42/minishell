/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:06:37 by maxcote           #+#    #+#             */
/*   Updated: 2026/04/09 18:06:39 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int	is_n_flag(char *cmd)
{
	int	i;

	if (ft_strlen(cmd) < 2)
		return (0);
	if (cmd[0] != '-' || cmd[1] != 'n')
		return (0);
	i = 2;
	while (cmd[i])
	{
		if (cmd[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	exec_echo(char **cmd)
{
	int	i;
	int	n;

	if (!cmd || !cmd[0])
		return (1);
	i = 1;
	n = 0;
	while (cmd[i] && is_n_flag(cmd[i]))
		i++;
	if (i > 1)
		n = 1;
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i], 1);
		if (cmd[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (n == 0)
		write(1, "\n", 1);
	return (0);
}
