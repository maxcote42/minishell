/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:20:39 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:20:41 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((((unsigned char *)s1)[i]) != (((unsigned char *)s2)[i]))
			return ((int)(((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	char a[] = {1, 2, 3, 5, 9};
	char b[] = {1, 2, 4};
	char c[] = {1, 2, 3, 5, 6};

	printf("memcmp(a, b, 3) = %d\n", ft_memcmp(a, b, 3));
	printf("memcmp(a, c, 3) = %d\n", ft_memcmp(a, c, 3));
	printf("memcmp(a, c, 5) = %d\n", ft_memcmp(a, c, 5)); 
	return (0);
}*/
