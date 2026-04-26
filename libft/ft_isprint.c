/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:19:23 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:19:25 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_isprint(31)); //or ascii min
	printf("%d\n", ft_isprint(32)); //limite min
	printf("%d\n", ft_isprint(126)); // limite max
	printf("%d\n", ft_isprint(127)); //or ascii
	return (0);
}*/
