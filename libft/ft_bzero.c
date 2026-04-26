/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:17:43 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:17:45 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)0;
		i++;
	}
}
/*
#include <stdio.h>
int	main()
{
	char	str[] = "Coucou l'équipe";

	printf("Avant bzero : %s\n", str);
	ft_bzero(str + 6, 6);
	printf("Après bzero : %s\n", str);
	return (0);
}
*/
