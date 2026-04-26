/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:47:33 by maxcote           #+#    #+#             */
/*   Updated: 2025/12/03 15:47:05 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	print_hex(unsigned long p)
{
	int		i;
	char	*base;
	char	c;

	i = 0;
	base = "0123456789abcdef";
	if (p >= 16)
		i += print_hex(p / 16);
	c = base[p % 16];
	write(1, &c, 1);
	i++;
	return (i);
}

int	ft_print_pointer(void *pp)
{
	int				i;
	unsigned long	p;

	p = (unsigned long)pp;
	if (pp == NULL)
	{
		return (write(1, "(nil)", 5));
	}
	write(1, "0x", 2);
	i = 2;
	if (p == 0)
	{
		i += write(1, "0", 1);
		return (i);
	}
	i += print_hex(p);
	return (i);
}
