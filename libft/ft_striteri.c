/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:23:26 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:23:28 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != 0)
	{
		f(i, &s[i]);
		i++;
	}
}
/* 
#include <stdio.h>
void majuscule_index(unsigned int i, char *c)
{
    if ((i % 2) == 0 && *c >= 'a' && *c <= 'z') 
        // si index pair, mettre en majuscule
        *c = *c - 32;
}

int main(void)
{
    char str[] = "coucou c'est ok ou pas ?";

    printf("Avant : %s\n", str);
    ft_striteri(str, majuscule_index);
    printf("Après : %s\n", str);
    return 0;
} */
