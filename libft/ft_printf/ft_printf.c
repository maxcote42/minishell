/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:44:13 by maxcote           #+#    #+#             */
/*   Updated: 2025/12/03 15:50:05 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	handle_conversion(char c, va_list *args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_print_char(va_arg(*args, int));
	else if (c == 's')
		count = ft_print_string(va_arg(*args, char *));
	else if (c == 'p')
		count = ft_print_pointer(va_arg(*args, void *));
	else if (c == 'd' || c == 'i')
		count = ft_print_nbr(va_arg(*args, int));
	else if (c == 'u')
		count = ft_print_unsigned_decimal(va_arg(*args, unsigned int));
	else if (c == 'x' || c == 'X')
		count = ft_print_hexadecimal(va_arg(*args, unsigned int), c);
	else if (c == '%')
	{
		write(1, "%", 1);
		count++;
	}
	return (count);
}
/*va_list	args; déclaration de la va_list
va_start initialisation la va_list, 
	args est le curseur pour lire les arguments, 
	format est le dernier argument connu avant .. 
va_end // nettoie les ressources*/

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += handle_conversion(format[i], &args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
