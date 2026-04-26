/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:22:04 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:22:06 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}
/* 
int main(void)
{
    int fd = 1; // ie standout

    ft_putnbr_fd(0, fd);
    write(fd, "\n", 1);
    ft_putnbr_fd(-1, fd);
	write(fd, "\n", 1);
    ft_putnbr_fd(-2147483648, fd); // int min
	write(fd, "\n", 1);
    ft_putnbr_fd(2147483647, fd); // int max
    return 0;
} */
