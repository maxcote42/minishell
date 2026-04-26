/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:25:39 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:25:40 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		n;
	char	ch;

	i = 0;
	n = -1;
	ch = (char)c;
	while (s[i])
	{
		if (s[i] == ch)
			n = i;
		i++;
	}
	if (ch == '\0')
		return ((char *)&s[i]);
	if (n != -1)
		return ((char *)&s[n]);
	return (0);
}
/* 
#include <stdio.h>
int	main()
{
	char	*s = "je cherche le premier i dans la phrase";
	char	*res;

	res = ft_strrchr(s, 'i');
	printf("%s\n", res);
	res = ft_strrchr(s, 's');
	printf("%s\n", res);
	res = ft_strrchr(s, '0'); 
	printf("%s\n", res);
	res = ft_strrchr(s, 0); 
	printf("%s\n", res);
	return (0);
} */
