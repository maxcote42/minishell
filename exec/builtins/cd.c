/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:06:29 by maxcote           #+#    #+#             */
/*   Updated: 2026/04/09 18:06:31 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int	set_env_value(t_env **env, char *key, char *value)
{
	char	*tmp;
	char	*entry;

	tmp = ft_strjoin(key, "=");
	if (!tmp)
		return (ft_putstr_fd("minishell: cd: malloc error\n", 2), 1);
	entry = ft_strjoin(tmp, value);
	free(tmp);
	if (!entry)
		return (ft_putstr_fd("minishell: cd: malloc error\n", 2), 1);
	if (export_core(env, entry) == 1)
	{
		free(entry);
		return (ft_putstr_fd("minishell: cd: malloc error\n", 2), 1);
	}
	free(entry);
	return (0);
}

static int	update_pwd(t_env **env, char *old_pwd)
{
	char	new_pwd[PATH_MAX];

	if (!getcwd(new_pwd, PATH_MAX))
	{
		ft_putstr_fd("minishell: cd: getcwd failed\n", 2);
		return (1);
	}
	if (old_pwd)
	{
		if (set_env_value(env, "OLDPWD", old_pwd) == 1)
			return (1);
	}
	if (set_env_value(env, "PWD", new_pwd) == 1)
		return (1);
	return (0);
}

static int	check_access(char *path)
{
	char	cwd_check[PATH_MAX];

	if (!getcwd(cwd_check, PATH_MAX))
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	return (0);
}

static int	cd_core(char *cmd, t_env **env)
{
	char	*old_pwd;

	if (!ft_strcmp(cmd, "-"))
	{
		old_pwd = get_env_value(*env, "OLDPWD");
		if (!old_pwd)
		{
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
			return (1);
		}
		ft_putstr_fd(old_pwd, 1);
		ft_putstr_fd("\n", 1);
		return (cd_core(old_pwd, env));
	}
	old_pwd = get_env_value(*env, "PWD");
	if (chdir(cmd) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	return (update_pwd(env, old_pwd));
}

int	exec_cd(char **cmd, t_env **env)
{
	int		i;
	char	*target;

	i = count_arg(cmd);
	if (i > 2)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (1);
	}
	if (i == 1 || !cmd[1] || !*cmd[1])
	{
		target = get_env_value(*env, "HOME");
		if (!target)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			return (1);
		}
		return (cd_core(target, env));
	}
	else
		target = cmd[1];
	if (check_access(target))
		return (1);
	return (cd_core(target, env));
}
