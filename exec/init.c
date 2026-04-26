/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:44:39 by maxcote           #+#    #+#             */
/*   Updated: 2026/04/21 18:44:41 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	init_struc(t_exec *exec)
{
	exec->cmd_count = 0;
	exec->cmds = NULL;
	exec->pid = NULL;
	exec->pipe_a[0] = -1;
	exec->pipe_a[1] = -1;
	exec->pipe_b[0] = -1;
	exec->pipe_b[1] = -1;
	exec->inuse = 0;
	exec->paths = NULL;
	exec->status = NULL;
	exec->envp = NULL;
	return ;
}

void	init_cmd(t_cmd *cmd)
{
	cmd->args = NULL;
	cmd->path = NULL;
	cmd->redirs = NULL;
	cmd->redir_count = 0;
	cmd->infile = -1;
	cmd->outfile = -1;
}
