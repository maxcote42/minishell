/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:18:02 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:18:06 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	if (count == 0 || size == 0)
		return (malloc(1));
	ptr = malloc(size * count);
	if (!ptr)
		return (0);
	i = 0;
	while (i < count * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>
int main()
{
	int	*tab;

	tab = ft_calloc(5, sizeof(int));
	if(!tab)
		return(1);
	printf("Avant modification : %d %d %d %d %d\n",
		tab[0], tab[1], tab[2], tab[3], tab[4]);
	tab[3] = 29;
	printf("Avant modification : %d %d %d %d %d\n",
		tab[0], tab[1], tab[2], tab[3], tab[4]);
	free(tab);
	return(0);
}*/
