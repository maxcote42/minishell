/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:22:17 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:22:19 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
/* 
int main(void)
{
    int fd = 1; // ie standout

    ft_putstr_fd("abc", fd);
    write(fd, "\n", 1);
    ft_putstr_fd("0", fd);
	write(fd, "\n", 1);
    ft_putstr_fd("-2147483648", fd); 
	write(fd, "\n", 1);
    ft_putstr_fd("", fd); 
    return 0;
}  */
