/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:21:52 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:21:54 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
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
	write(fd, "\n", 1);
}
/* 
int main(void)
{
    int fd = 1; // ie standout

    ft_putendl_fd("abc", fd);
    ft_putendl_fd("0", fd);
	ft_putendl_fd("", fd); 
    ft_putendl_fd("-2147483648", fd); 
    return 0;
}  */
