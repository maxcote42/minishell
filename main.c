/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfeijoei <sfeijoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:42:58 by sfeijoei          #+#    #+#             */
/*   Updated: 2026/04/24 12:40:56 by sfeijoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int	line_handler(t_exec *exec, char **line)
{
	*line = readline("minishell$ ");
	if (!*line)
	{
		ft_putstr_fd("exit\n", 2);
		return (1);
	}
	if (g_signal == SIGINT)
		exec->last_status = 130;
	if (**line)
		add_history(*line);
	exec->tokens = tokenize(*line);
	free(*line);
	return (0);
}

void	handle_invalid_syntax(t_exec *exec)
{
	free_tokens(exec->tokens);
	exec->last_status = 2;
}

void	process_tokens(t_exec *exec)
{
	parser(exec->tokens, exec);
	free_tokens(exec->tokens);
	expand(exec);
	if (handle_heredoc(exec) == 1)
	{
		if (g_signal == SIGINT)
			exec->last_status = 130;
		else
			exec->last_status = 1;
		cleanup(exec);
		return ;
	}
	exec->last_status = exec_core(exec);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_exec	exec;

	init_main(&exec, argc, argv, envp);
	while (1)
	{
		g_signal = 0;
		if (line_handler(&exec, &line) == 1)
			break ;
		if (exec.tokens && is_syntax_valid(exec.tokens) == true)
			process_tokens(&exec);
		else if (exec.tokens)
			handle_invalid_syntax(&exec);
		cleanup(&exec);
	}
	free_env(exec.env);
	rl_clear_history();
	return (exec.last_status);
}
