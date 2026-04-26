/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:45:05 by maxcote           #+#    #+#             */
/*   Updated: 2025/12/03 14:45:11 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_nbr(int n)
{
	int		i;
	long	num;
	char	c;

	i = 0;
	num = n;
	if (n < 0)
	{
		num = -num;
		write(1, "-", 1);
		i++;
	}
	if (num >= 10)
		i += ft_print_nbr(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
	i++;
	return (i);
}
