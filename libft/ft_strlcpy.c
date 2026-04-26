/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:24:08 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:24:11 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (src[len] != 0)
		len++;
	if (dstsize == 0)
		return (len);
	while ((i < dstsize - 1) && src[i])
	{
		dst[i] = src [i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/* #include <stdio.h>

int main()
{
    char dst[7] = "coucou";
    char *src = "c'est ok?";
    size_t ret;

    printf("Avant : dst = '%s'\n", dst);

    ret = ft_strlcpy(dst, src, sizeof(dst));

    printf("Après  : dst = '%s'\n", dst);
    printf("Valeur retour : %zu\n", ret);

    return 0;
} */
