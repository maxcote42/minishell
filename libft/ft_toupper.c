/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:26:40 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:26:42 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		c = c - 32;
	return (c);
}
/* 
#include <stdio.h>
int	main()
{
	printf("%c\n", ft_toupper('c')); //retourne C
	printf("%c\n", ft_toupper('C')); //retourne C
	printf("%c\n", ft_toupper('0')); //retourne 0
	printf("%c\n", ft_toupper('f')); //retourne F
	printf("%c\n", ft_toupper('/')); //retourne /
	return (0);
} */
