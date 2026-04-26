/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:22:55 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:22:57 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = (char)c;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i++;
	}
	if (ch == '\0')
		return ((char *)&s[i]);
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	char	*s = "je cherche le premier i dans la phrase";
	char	*res;

	res = ft_strchr(s, 'i');
	printf("%s\n", res);
	res = ft_strchr(s, 'j');
	printf("%s\n", res);
	res = ft_strchr(s, '0'); 
	printf("%s\n", res);
	return (0);
}
*/
