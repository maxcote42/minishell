/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfeijoei <sfeijoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 22:35:00 by sfeijoei          #+#    #+#             */
/*   Updated: 2026/04/25 14:26:33 by sfeijoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

// Helper ez on ajoute un caractere a la fin du buffer resultat
static void	append_char_to_result(char **result, char c)
{
	char	tmp[2];
	char	*new;

	tmp[0] = c;
	tmp[1] = '\0';
	new = ft_strjoin(*result, tmp);
	free(*result);
	*result = new;
}

// Expansion de heredoc pour $VAR et $? tavu
char	*expand_heredoc_line(char *line, t_exec *exec)
{
	char	*result;
	int		i;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == '$')
			result = handle_dollar(result, line, &i, exec);
		else
			append_char_to_result(&result, line[i++]);
		if (!result)
			return (NULL);
	}
	return (result);
}

int	is_delimiter_line(char *line, char *delimiter)
{
	int	len;

	len = ft_strlen(delimiter);
	if (!ft_strncmp(line, delimiter, len)
		&& (line[len] == '\n' || line[len] == '\0'))
		return (1);
	return (0);
}

void	need_norminette(int read_fd)
{
	perror("waitpid");
	close(read_fd);
	setup_signals();
}

int	wait_heredoc_child(pid_t pid, int read_fd)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (waitpid(pid, &status, 0) == -1)
		return (need_norminette(read_fd), -1);
	setup_signals();
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
	{
		g_signal = SIGINT;
		close(read_fd);
		return (-1);
	}
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		return (close(read_fd), -1);
	if (WIFSIGNALED(status))
	{
		g_signal = WTERMSIG(status);
		close(read_fd);
		return (-1);
	}
	return (read_fd);
}
