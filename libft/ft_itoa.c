/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:19:44 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:19:46 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_figure(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while ((n != 0))
	{
		n = n / 10;
		count ++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	numb;
	int		i;

	numb = n;
	i = count_figure(n);
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (0);
	if (numb == 0)
		result[0] = '0';
	if (numb < 0)
	{
		result[0] = '-';
		numb = -numb;
	}
	result[i] = 0;
	while (numb != 0)
	{
		i--;
		result[i] = numb % 10 + '0';
		numb = numb / 10;
	}
	return (result);
}
/*
#include <stdio.h>
int	main()
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(1000000));
	printf("%s\n", ft_itoa(-10));
	printf("%s\n", ft_itoa(888888888));
	printf("%s\n", ft_itoa(99091928));
	return (0);
}*/
