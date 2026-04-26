/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:21:36 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:21:38 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/* 
int main(void)
{
    int fd = 1; // ie standout

    ft_putchar_fd('a', fd);
    ft_putchar_fd('0', fd);
	ft_putchar_fd(0, fd); //carac null
    ft_putchar_fd('-', fd); 
    return 0;
} */
