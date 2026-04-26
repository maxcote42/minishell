/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfeijoei <sfeijoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:06:05 by maxcote           #+#    #+#             */
/*   Updated: 2026/04/24 11:15:49 by sfeijoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/* 
◦ echo with option -n
◦ cd with only a relative or absolute path
◦ pwd with no options
◦ export with no options
◦ unset with no options
◦ env with no options or arguments
◦ exit with no options */

static int	builtin_core(t_exec *exec, char **cmd, int prev_stdout)
{
	if (!ft_strcmp(cmd[0], "pwd"))
		return (exec_pwd(cmd));
	else if (!ft_strcmp(cmd[0], "export"))
		return (exec_export(&exec->env, cmd));
	else if (!ft_strcmp(cmd[0], "unset"))
		return (exec_unset(&exec->env, cmd));
	else if (!ft_strcmp(cmd[0], "env"))
		return (exec_env(exec->env, cmd));
	else if (!ft_strcmp(cmd[0], "exit"))
	{
		if (prev_stdout != -1)
		{
			if (dup2(prev_stdout, 1) < 0)
				return (perror("minishell: dup2"), 1);
			close (prev_stdout);
		}
		exec_exit(cmd, exec);
	}
	else if (!ft_strcmp(cmd[0], "echo"))
		return (exec_echo(cmd));
	else
		return (exec_cd(cmd, &exec->env));
	return (1);
}

static int	builtin_redir(t_cmd *cmd)
{
	int	prev_stdout;

	if (plug_redirs(cmd) == 1)
		return (-2);
	if (cmd->infile != -1)
	{
		close(cmd->infile);
		cmd->infile = -1;
	}
	prev_stdout = -1;
	if (cmd->outfile != -1)
	{
		prev_stdout = dup(1);
		if (dup2(cmd->outfile, 1) < 0)
			return (perror("minishell: dup2"),
				close(cmd->outfile), cmd->outfile = -1, -2);
		close(cmd->outfile);
		cmd->outfile = -1;
	}
	return (prev_stdout);
}

int	exec_builtin(t_exec *exec, t_cmd *cmd)
{
	int	exit;
	int	prev_stdout;

	prev_stdout = -1;
	if (exec->cmd_count == 1)
	{
		prev_stdout = builtin_redir(cmd);
		if (prev_stdout == -2)
			return (1);
	}
	exit = builtin_core(exec, cmd->args, prev_stdout);
	if (exec->cmd_count == 1 && prev_stdout != -1)
	{
		if (dup2(prev_stdout, 1) < 0)
			return (perror("minishell: dup2"), 1);
		close (prev_stdout);
	}
	return (exit);
}
