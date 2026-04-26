/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:26:24 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:26:25 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		c = c + 32;
	return (c);
}

/* #include <stdio.h>
int	main()
{
	printf("%c\n", ft_tolower('c')); //retourne c
	printf("%c\n", ft_tolower('C')); //retourne c
	printf("%c\n", ft_tolower('0')); //retourne 0
	printf("%c\n", ft_tolower('F')); //retourne f
	printf("%c\n", ft_tolower('/')); //retourne /
	return (0);
} */
