/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:26:52 by maxcote           #+#    #+#             */
/*   Updated: 2025/12/09 17:03:35 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	add_stash(char **stash, char *buffer, int n)
{
	char	*new_stash;
	int		len;

	if (!stash || !buffer)
		return (-1);
	len = 0;
	if (*stash)
		len = ft_strlen(*stash);
	new_stash = malloc(sizeof(char) * (len + n + 1));
	if (!new_stash)
		return (-1);
	if (*stash)
	{
		ft_strncpy(new_stash, *stash, len);
		new_stash[len] = '\0';
		free(*stash);
	}
	else
		new_stash[0] = '\0';
	ft_strncat(new_stash, buffer, n);
	*stash = new_stash;
	return (0);
}

static int	read_and_stash(int fd, char **stash)
{
	char	*buffer;
	int		n;

	n = 1;
	while ((!*stash || !isnewline(*stash)) && n > 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (-1);
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer [n] = '\0';
		if (add_stash(stash, buffer, n) == -1)
		{
			free (buffer);
			return (-1);
		}
		free (buffer);
	}
	return (0);
}

static int	copy_line(char **line, char **stash)
{
	int	i;
	int	len;

	if (!stash || !*stash || **stash == '\0')
	{
		*line = NULL;
		return (0);
	}
	len = checknewline(*stash);
	*line = malloc(sizeof(char) * (len + 1));
	if (!*line)
		return (-1);
	i = 0;
	while (i < len)
	{
		(*line)[i] = (*stash)[i];
		i++;
	}
	(*line)[i] = '\0';
	return (0);
}

static int	clean_stash(char **stash)
{
	char	*tmp;
	int		i;
	int		j;
	int		len;

	if (!stash || !*stash)
		return (0);
	len = checknewline(*stash);
	j = len;
	if (len >= (int)ft_strlen(*stash))
	{
		free(*stash);
		*stash = NULL;
		return (0);
	}
	tmp = malloc (sizeof(char) * (ft_strlen(*stash) - len + 1));
	if (!tmp)
		return (-1);
	i = 0;
	while ((*stash)[j])
		tmp[i++] = (*stash)[j++];
	tmp [i] = '\0';
	free(*stash);
	*stash = tmp;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (read_and_stash(fd, &stash) == -1 || copy_line(&line, &stash) == -1
		|| clean_stash(&stash) == -1)
	{
		free (line);
		free (stash);
		stash = NULL;
		return (NULL);
	}
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	i = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("ligne %d: %s", i, line);
		free (line);
		i ++;
	}
	close (fd);
	return (0);
}*/
