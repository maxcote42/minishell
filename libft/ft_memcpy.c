/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:20:54 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:20:56 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src && n > 0)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
int	main()
{
	char a[] = {1, 2, 3, 5, 9};
	char b[] = {8, 8, 8};

	printf("Avant : %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
	ft_memcpy(a, b, 3); // copie de 3 octets de b dans a
	printf("Après  : %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
	return 0;
}
*/
