/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:09:15 by maxcote           #+#    #+#             */
/*   Updated: 2026/04/09 18:09:16 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	error_cmd(int ret, char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	if (ret == 126)
		ft_putstr_fd(": Permission denied\n", 2);
	else if (ret == 127)
		ft_putstr_fd(": command not found\n", 2);
	else if (ret == 128)
		ft_putstr_fd(": Is a directory\n", 2);
}

static char	*build_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*full;

	if (dir[0] == '\0')
		tmp = ft_strdup(".");
	else
		tmp = ft_strdup(dir);
	if (!tmp)
		return (NULL);
	full = ft_strjoin(tmp, "/");
	free(tmp);
	if (!full)
		return (NULL);
	tmp = ft_strjoin(full, cmd);
	free(full);
	return (tmp);
}

static int	search_in_paths(char *cmd, char **paths, char **path)
{
	char	*full;
	int		i;
	int		found;

	i = 0;
	found = 0;
	while (paths[i])
	{
		full = build_path(paths[i], cmd);
		if (!full)
			return (1);
		if (access(full, X_OK) == 0)
		{
			*path = full;
			return (0);
		}
		if (access(full, F_OK) == 0)
			found = 1;
		free(full);
		i++;
	}
	if (found)
		return (126);
	return (127);
}

int	try_direct(char *cmd, char **path)
{
	struct stat	st;
	int			ret;

	if (access(cmd, F_OK) != 0)
		ret = 127;
	else if (stat(cmd, &st) == 0 && S_ISDIR(st.st_mode))
		return (128);
	else if (access(cmd, X_OK) != 0)
		ret = 126;
	else
	{
		*path = ft_strdup(cmd);
		if (!*path)
			ret = 1;
		else
			ret = 0;
	}
	return (ret);
}

int	find_cmd_path(char **cmd, char **paths, char **path)
{
	int		ret;

	if (cmd[0] == NULL)
		ret = 127;
	else if (ft_strchr(cmd[0], '/'))
	{
		ret = try_direct(cmd[0], path);
		if (ret == 0)
			return (0);
		error_cmd(ret, cmd[0]);
		if (ret == 128)
			return (126);
		return (ret);
	}
	else if (paths == NULL)
		ret = 127;
	else
		ret = search_in_paths(cmd[0], paths, path);
	if (ret != 0)
		error_cmd(ret, *cmd);
	return (ret);
}
