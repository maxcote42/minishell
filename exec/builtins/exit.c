/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:07:16 by maxcote           #+#    #+#             */
/*   Updated: 2026/04/09 18:07:17 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int	is_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	checkoverflow_long(long res, int sign, int digit)
{
	if (res > 922337203685477580)
		return (0);
	if (res == 922337203685477580)
	{
		if (sign == 1 && digit > 7)
			return (0);
		if (sign == -1 && digit > 8)
			return (0);
	}
	return (1);
}

static int	code_atol(char *str, long *res, int sign)
{
	int	i;
	int	digit;

	*res = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		digit = str[i] - '0';
		if (!checkoverflow_long(*res, sign, digit))
			return (0);
		*res = (*res * 10) + digit;
		i++;
	}
	*res = *res * sign;
	return (1);
}

static int	check_code(char *str, long *code)
{
	int	sign;

	if (!is_number(str))
		return (0);
	sign = 1;
	if (str[0] == '-')
		sign = -1;
	if (!code_atol(str, code, sign))
		return (0);
	return (1);
}

int	exec_exit(char **cmd, t_exec *exec)
{
	long	code;

	ft_putstr_fd("exit\n", 1);
	if (!cmd[1])
		code = exec->last_status;
	else if (!check_code(cmd[1], &code))
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		code = 255;
	}
	else if (cmd[2])
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return (1);
	}
	code = (unsigned char)code;
	free_env(exec->env);
	cleanup(exec);
	exit(code);
}
