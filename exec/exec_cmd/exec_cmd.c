/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:09:08 by maxcote           #+#    #+#             */
/*   Updated: 2026/04/09 18:09:10 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

// i = 0 >> write, i = 1 >> read
int	*get_pipe(t_exec *exec, int i)
{
	if (i == 0)
	{
		if (exec->inuse == 0)
			return (exec->pipe_a);
		return (exec->pipe_b);
	}
	if (exec->inuse == 0)
		return (exec->pipe_b);
	return (exec->pipe_a);
}

static void	exit_child(t_exec *exec, int exit_code)
{
	close_all_exec(exec);
	cleanup(exec);
	free_env(exec->env);
	close(0);
	close(1);
	exit (exit_code);
}

static void	exec_without_cmd(t_exec *exec, t_cmd *cmd)
{
	if (plug_redirs(cmd) == 1)
		exit_child(exec, 1);
	exit_child(exec, 0);
}

void	exec_cmd(t_exec *exec, t_cmd *cmd, int i)
{
	int	ret;

	setup_signals_exec();
	if (!cmd->args[0])
		exec_without_cmd(exec, cmd);
	if (plug_redirs(cmd) == 1 || ft_dup(exec, cmd, i) == 1)
		exit_child(exec, 1);
	close_all_exec(exec);
	if (is_builtin(cmd->args))
		exit_child(exec, exec_builtin(exec, cmd));
	ret = find_cmd_path(cmd->args, exec->paths, &cmd->path);
	if (ret != 0)
		exit_child(exec, ret);
	execve(cmd->path, cmd->args, exec->envp);
	perror("minishell: execve");
	exit_child(exec, 1);
}
