/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:21:23 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:21:24 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
int	main()
{
	char	str[] = "Coucou l'équipe";

	printf("Avant memset : %s\n", str);
	ft_memset(str + 6, 73, 6); // on place des I à partir de str[6] sur 6 octets
	printf("Après memset : %s\n", str);
	return (0);
}
*/
