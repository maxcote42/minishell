/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:18:35 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:18:37 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_isalpha(88)); //lettre x
	printf("%d\n", ft_isalpha(0)); //rien
	printf("%d\n", ft_isalpha(48)); //chiffre 0
	printf("%d\n", ft_isalpha(57)); //chiffre 9
	return (0);
}*/
