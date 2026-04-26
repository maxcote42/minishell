/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfeijoei <sfeijoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:09:35 by maxcote           #+#    #+#             */
/*   Updated: 2026/04/24 12:06:22 by sfeijoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	is_builtin(char **cmd)
{
	if (!ft_strcmp(cmd[0], "pwd") || !ft_strcmp(cmd[0], "export")
		|| !ft_strcmp(cmd[0], "unset") || (!ft_strcmp(cmd[0], "env"))
		|| !ft_strcmp(cmd[0], "exit") || !ft_strcmp(cmd[0], "echo")
		|| (!ft_strcmp(cmd[0], "cd")))
		return (1);
	return (0);
}

static void	last_status(int status, int *last_exit)
{
	if (WIFEXITED(status))
		*last_exit = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
			ft_putstr_fd("Quit (core dumped)\n", 2);
		*last_exit = 128 + WTERMSIG(status);
	}
}

static void	wait_all(t_exec *exec)
{
	int	i;
	int	status;
	int	last_exit;
	int	saw_sigint;

	i = 0;
	last_exit = 0;
	saw_sigint = 0;
	while (i < exec->cmd_count)
	{
		if (waitpid(exec->pid[i], &status, 0) == -1)
			perror("minishell: waitpid");
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
			saw_sigint = 1;
		if (i == exec->cmd_count - 1)
			last_status(status, &last_exit);
		i++;
	}
	exec->last_status = last_exit;
	if (saw_sigint)
		write(1, "\n", 1);
}

int	exec_core(t_exec *exec)
{
	if (exec->cmd_count == 1 && is_builtin(exec->cmds[0].args))
		return (exec_builtin(exec, &exec->cmds[0]));
	if (update_env(exec) == -1)
		return (1);
	if (find_env_path(exec) == -1)
		return (1);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (exec_pipeline(exec) == 1)
		return (1);
	wait_all(exec);
	setup_signals();
	return (exec->last_status);
}
