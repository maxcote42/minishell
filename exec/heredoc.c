/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfeijoei <sfeijoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:10:00 by maxcote           #+#    #+#             */
/*   Updated: 2026/04/25 14:20:26 by sfeijoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	heredoc_child_process(t_exec *exec, int *pipe_fd, char *delimiter,
		int do_expand)
{
	struct termios	saved_term;
	int				has_term;
	int				status;

	setup_signals_heredoc();
	g_signal = 0;
	close(pipe_fd[0]);
	has_term = (tcgetattr(STDERR_FILENO, &saved_term) == 0);
	status = save_heredoc(pipe_fd[1], delimiter, do_expand, exec);
	if (has_term)
		tcsetattr(STDERR_FILENO, TCSANOW, &saved_term);
	close(pipe_fd[1]);
	free_env(exec->env);
	cleanup(exec);
	if (status == 130)
		exit(130);
	if (status != 0)
		exit(1);
	exit(0);
}

static int	create_heredoc(t_exec *exec, char *delimiter, int do_expand)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		setup_signals();
		return (-1);
	}
	if (pid == 0)
		heredoc_child_process(exec, pipe_fd, delimiter, do_expand);
	close(pipe_fd[1]);
	return (wait_heredoc_child(pid, pipe_fd[0]));
}

int	handle_heredoc(t_exec *exec)
{
	int	i;
	int	j;

	i = 0;
	while (i < exec->cmd_count)
	{
		j = 0;
		while (j < exec->cmds[i].redir_count)
		{
			if (exec->cmds[i].redirs[j].type == HEREDOC)
			{
				if (exec->cmds[i].redirs[j].fd_heredoc != -1)
					close (exec->cmds[i].redirs[j].fd_heredoc);
				exec->cmds[i].redirs[j].fd_heredoc
					= create_heredoc(exec, exec->cmds[i].redirs[j].file,
						exec->cmds[i].redirs[j].heredoc_expand);
				if (exec->cmds[i].redirs[j].fd_heredoc == -1)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
