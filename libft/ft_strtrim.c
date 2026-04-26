/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:25:58 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:25:59 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*ret;

	if (s1 == 0)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && (ft_strchr(set, (int)s1[start]) != 0))
		start++;
	while (end > start && (ft_strchr(set, (int)s1[end - 1]) != 0))
		end --;
	ret = malloc(sizeof(char) * (end - start + 1));
	if (!ret)
		return (0);
	i = 0;
	while (start < end)
	{
		ret[i] = s1[start];
		i++;
		start++;
	}
	ret[i] = 0;
	return (ret);
}
/* 
#include <stdio.h>
int	main()
{
	char	*s = "xxxxxxxaje cherche le premier i dans la phraseaaaxaxaxaxxxxx";
	char	*res;

	res = ft_strtrim(s, "ax");
	printf("%s\n", res);
	free(res);
	res = ft_strtrim(s, "x");
	printf("%s\n", res);
	free(res);
	res = ft_strtrim(s, "0"); 
	printf("%s\n", res);
	free(res);
	return (0);
} */
