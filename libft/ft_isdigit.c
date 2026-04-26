/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:19:11 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:19:13 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_isdigit(88)); //lettre x
	printf("%d\n", ft_isdigit(0)); //rien
	printf("%d\n", ft_isdigit(48)); //chiffre 0
	printf("%d\n", ft_isdigit(57)); //chiffre 9
	return (0);
}*/
