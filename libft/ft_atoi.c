/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:17:20 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:17:29 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		n;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}
/*
#include <stdio.h>
int	main()
{
	int	n;

	n = ft_atoi("    -184");
	printf("%d\n", n);
	n = ft_atoi("   - -184");
	printf("%d\n", n);
	n = ft_atoi("    +-184");
	printf("%d\n", n);
	n = ft_atoi("-2147483648");
	printf("%d\n", n);
	n = ft_atoi("0");
	printf("%d\n", n);
}*/
