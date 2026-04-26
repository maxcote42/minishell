/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:22:38 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:22:41 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if ((s[i] != c) && ((i == 0) || (s[i - 1] == c)))
			count++;
		i++;
	}
	return (count);
}

static char	*split_malloc(char const *s, char c)
{
	char	*word;
	int		i;
	int		len;

	len = 0;
	while (s[len] && (s[len] != c))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static void	*free_all(char **result, size_t j)
{
	while (j > 0)
	{
		free(result[j - 1]);
		j--;
	}
	free(result);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	result = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if ((s[i] != c) && ((i == 0) || (s[i - 1] == c)))
		{
			result[j] = split_malloc(&s[i], c);
			if (!result[j])
				return (free_all(result, j));
			j++;
		}
		i++;
	}
	result[j] = 0;
	return (result);
}
/*
#include <stdio.h>
int	main()
{
	char	*str = "iiiiiiiiiiPrendreilaipremiereiaigauchei!i";
	char	c = 'i';
	char	**res;
	int	i = 0;

	res = ft_split(str, c);
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
	return (0);
}*/
