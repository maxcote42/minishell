/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:26:11 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:26:14 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	i = len;
	j = 0;
	if (len > (ft_strlen(s) - start))
		i = ft_strlen(s) - start;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (0);
	while (j < i)
	{
		dst[j] = s[j + start];
		j++;
	}
	dst[j] = 0;
	return (dst);
}
/* 
#include <stdio.h>
int	main()
{
	char	*s = "xxxxxxxa10je cherche le premier i dans la phrase";
	char	*res;

	res = ft_substr(s, 10, 10);
	printf("%s\n", res);
	free(res);
	res = ft_substr(s, 10, 20);
	printf("%s\n", res);
	free(res);
	res = ft_substr(s, 0, 10);
	printf("%s\n", res);
	free(res);
	res = ft_substr(s, 0, 0);
	printf("%s\n", res);
	free(res);
	return (0);
} */
