/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:25:01 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:25:03 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == 0)
			return (0);
		i++;
	}
	return (0);
}
/* #include <stdio.h>
int	main()
{
	char	*s1 = "nous sommes les soeurs jumelles!";
	char	*s2 = "nous sommes les soeurs jumelles";
	printf("diff : %d\n", ft_strncmp(s1,s2,31));
	printf("diff : %d\n", ft_strncmp(s1,s2,32)); // avec le ! en plus
	return(0);
} */
