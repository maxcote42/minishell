/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:18:51 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:18:55 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_isascii(88)); //lettre x
	printf("%d\n", ft_isascii(0)); //limite min
	printf("%d\n", ft_isascii(128)); //or ascii
	printf("%d\n", ft_isascii(127)); //limite max ascii
	return (0);
}*/
