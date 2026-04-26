/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfeijoei <sfeijoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:33:34 by sfeijoei          #+#    #+#             */
/*   Updated: 2026/04/22 15:34:03 by sfeijoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

//void	debug_print_env(t_env *head)
//{
//	t_env	*current;
//	int		i;

//	i = 0;
//	current = head;
//	printf("debug env :\n");
//	if (!head)
//		printf("ERREUR PAS DE ENV\n");
//	while (current)
//	{
//		printf("└─env[%d]: %s\n", i, current->value);
//		current = current->next;
//		i++;
//	}
//}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		free(env->value);
		free(env);
		env = tmp;
	}
}

void	free_tokens(t_token *tokens)
{
	t_token	*next;

	while (tokens)
	{
		next = tokens->next;
		free(tokens->text);
		free(tokens);
		tokens = next;
	}
}

void	init_main(t_exec *exec, int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	init_struc(exec);
	exec->env = set_env(envp);
	exec->last_status = 0;
	setup_signals();
}
