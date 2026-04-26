/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:18:16 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:18:19 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/* 
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_isalnum(88)); //lettre x
	printf("%d\n", ft_isalnum(0)); //rien
	printf("%d\n", ft_isalnum(48)); //chiffre 0
	printf("%d\n", ft_isalnum(57)); //chiffre 9
	return (0);
} */
