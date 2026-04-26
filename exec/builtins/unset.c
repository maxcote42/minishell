/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:06:55 by maxcote           #+#    #+#             */
/*   Updated: 2026/04/09 18:06:57 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	unset_core(t_env **envp, char *cmd)
{
	t_env	*tmp;
	t_env	*prev;

	tmp = *envp;
	prev = NULL;
	while (tmp)
	{
		if (!ft_strcmp_key(cmd, tmp->value))
		{
			if (prev)
				prev->next = tmp->next;
			else
				*envp = tmp->next;
			free(tmp->value);
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

int	exec_unset(t_env **envp, char **cmd)
{
	int		i;
	int		ret;

	ret = 0;
	if (!cmd[1])
		return (0);
	i = 1;
	while (cmd[i])
	{
		if (!is_valid_identifier(cmd[i], 1))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(cmd[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			ret = 1;
		}
		else
			unset_core(envp, cmd[i]);
		i++;
	}
	return (ret);
}
