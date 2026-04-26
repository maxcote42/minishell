/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:20:16 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:20:19 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)&(((unsigned char *)s)[i]));
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	char	str[] = "Coucou l'équipe 42";
	char	*p;

	p = ft_memchr(str, 'q', 4);
	if (p)
		printf("Résultat : '%c'\n", *p);
	else
		printf("Pas de résultat\n");
		p = ft_memchr(str, 'q', 12);
	if (p)
		printf("2nd test : Résultat : '%c'\n", *p);
	else
		printf("2nd test : Pas de résultat\n");
	return (0);
}*/
