/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:23:55 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:23:57 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && (i + j + 1 < dstsize))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
/* #include <stdio.h>

int main()
{
    char dst[7] = "coucou";
    char *src = "c'est ok?";
    size_t ret;

    printf("Avant : dst = '%s'\n", dst);

    ret = ft_strlcat(dst, src, sizeof(dst));

    printf("Après  : dst = '%s'\n", dst);
    printf("Valeur retour : %zu\n", ret);

    return 0;
} */
