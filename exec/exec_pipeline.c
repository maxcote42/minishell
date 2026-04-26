/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:09:42 by maxcote           #+#    #+#             */
/*   Updated: 2026/04/09 18:09:43 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	new_pipe(t_exec *exec, int i)
{
	int	*pipe_write;

	if (i == 0)
		pipe_write = exec->pipe_a;
	else
		pipe_write = exec->pipe_b;
	if (pipe(pipe_write) == -1)
	{
		perror("minishell: pipe");
		close_all_exec(exec);
		return (1);
	}
	return (0);
}

// 0 : on ferme pipe b, 1 : on ferme pipe a
void	close_pipe(t_exec *exec, int i)
{
	if (i == 0)
	{
		if (exec->pipe_a[0] != -1)
			close (exec->pipe_a[0]);
		if (exec->pipe_a[1] != -1)
			close (exec->pipe_a[1]);
		exec->pipe_a[0] = -1;
		exec->pipe_a[1] = -1;
	}
	else
	{
		if (exec->pipe_b[0] != -1)
			close (exec->pipe_b[0]);
		if (exec->pipe_b[1] != -1)
			close (exec->pipe_b[1]);
		exec->pipe_b[0] = -1;
		exec->pipe_b[1] = -1;
	}
}

static int	fork_exec(t_exec *exec, int i)
{
	exec->pid[i] = fork();
	if (exec->pid[i] < 0)
	{
		perror("minishell: fork");
		return (1);
	}
	if (exec->pid[i] == 0)
		exec_cmd(exec, &exec->cmds[i], i);
	return (0);
}

int	exec_pipeline(t_exec *exec)
{
	int	i;

	i = 0;
	exec->inuse = 0;
	exec->pid = malloc(sizeof(pid_t) * exec->cmd_count);
	if (!exec->pid)
		return (1);
	while (i < exec->cmd_count)
	{
		if (i < exec->cmd_count - 1)
		{
			if (new_pipe(exec, exec->inuse) == 1)
				return (1);
		}
		if (fork_exec(exec, i) == 1)
		{
			close_all_exec(exec);
			return (1);
		}
		if (i > 0)
			close_pipe(exec, !exec->inuse);
		exec->inuse = !exec->inuse;
		i++;
	}
	return (0);
}
