/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:46:50 by maxcote           #+#    #+#             */
/*   Updated: 2025/12/03 14:46:54 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_unsigned_decimal(unsigned int n)
{
	int		i;
	char	c;

	i = 0;
	if (n >= 10)
		i += ft_print_unsigned_decimal(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	i++;
	return (i);
}
