/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:23:12 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:23:15 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i] != 0)
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/*
#include <stdio.h>
int	main()
{
    char *s = "je cherche le premier i dans la phrase";
    char *dest = ft_strdup(s);

	if (!dest)
    {
        printf("Erreur allocation\n");
        return (1);
    }
	printf("dest : %s\n", dest);
	printf("src : %s\n", s);
	free(dest);
	return(0);
}
*/
