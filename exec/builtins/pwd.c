/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:06:50 by maxcote           #+#    #+#             */
/*   Updated: 2026/04/09 18:06:51 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	exec_pwd(char **cmd)
{
	char	cwd[PATH_MAX];

	if (cmd[1] && cmd[1][0] == '-')
	{
		ft_putstr_fd("minishell: pwd: ", 2);
		write(2, &cmd[1][0], 1);
		if (cmd[1][1])
			write(2, &cmd[1][1], 1);
		ft_putstr_fd(": invalid option\n", 2);
		return (2);
	}
	if (getcwd(cwd, PATH_MAX))
	{
		printf("%s\n", cwd);
		return (0);
	}
	else
	{
		ft_putstr_fd("minishell: pwd: error retrieving current directory: ", 1);
		perror("getcwd: cannot access parent directories:");
		return (1);
	}
}
