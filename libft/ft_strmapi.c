/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:24:42 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:24:44 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	result = malloc(sizeof(char) * (ft_strlen(s)+1));
	if (!result)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/* #include <stdio.h>
char majuscule_index(unsigned int i, char c)
{
    if ((i % 2) == 0 && c >= 'a' && c <= 'z')
	// si index pair, mettre en majuscule
        return (c - 32);
	return(c);
}

int main(void)
{
    char str[] = "coucou c'est ok ou pas ?";
    char *dst = ft_strmapi(str, majuscule_index);
	if(!dst)
		return (0);
    printf("str : %s\n", str);
    printf("dst : %s\n", dst);
    return 0;
}  */
