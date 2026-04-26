/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfeijoei <sfeijoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 22:46:12 by sfeijoei          #+#    #+#             */
/*   Updated: 2026/04/25 14:21:22 by sfeijoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

// On ecrit la ligne commee dans le pipe heredoc en ajoutant \n si fqut
static void	write_heredoc_line(int fd, char *line)
{
	int	len;

	ft_putstr_fd(line, fd);
	len = ft_strlen(line);
	if (len == 0 || line[len - 1] != '\n')
		ft_putstr_fd("\n", fd);
}

// Petit helper pour nromette expand la ligne, ecrit, puis free
static int	write_expanded_heredoc_line(int fd, char *line, t_exec *exec)
{
	char	*expanded;

	expanded = expand_heredoc_line(line, exec);
	if (!expanded)
		return (1);
	write_heredoc_line(fd, expanded);
	free(expanded);
	return (0);
}

static int	line_norminette(char *delimiter)
{
	ft_putstr_fd("warning: here-document delimited by end-of-file", 2);
	ft_putstr_fd(" (wanted `", 2);
	ft_putstr_fd(delimiter, 2);
	ft_putstr_fd("')\n", 2);
	return (0);
}

int	save_heredoc(int fd, char *delimiter, int do_expand, t_exec *exec)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			if (g_signal == SIGINT)
				return (130);
			return (line_norminette(delimiter));
		}
		if (is_delimiter_line(line, delimiter))
			return (free(line), 0);
		if (do_expand)
		{
			if (write_expanded_heredoc_line(fd, line, exec))
			{
				free(line);
				return (1);
			}
		}
		else
			write_heredoc_line(fd, line);
		free(line);
	}
}
