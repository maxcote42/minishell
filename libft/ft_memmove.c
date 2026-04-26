/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:21:07 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:21:08 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	if ((unsigned char *)dst < (unsigned char *)src)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
	}
	return (dst);
}
/*
#include <stdio.h>
int	main()
{
	char str[] = "12345678";
	ft_memmove(str + 2, str, 6); 
	// on teste le chevauchement (diff avec memcpy) en copiant str dans str+2
	printf("%s\n", str); // affiche : "12123456"
	return (0);
}*/
