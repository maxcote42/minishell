/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:23:38 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:23:41 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) + ft_strlen(s2);
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (0);
	i = 0;
	while (s1[i] != 0)
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (dst);
}
/* 
#include <stdio.h>
int	main()
{
	char	*s1 = "dis-moi si on se rejoint?";
	char	*s2 = "oui. enfin je crois.";
	char	*res = ft_strjoin(s1,s2);

	printf("%s", res);

	free(res);
	return (0);
} */
