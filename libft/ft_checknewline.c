/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknewline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:18:59 by maxcote           #+#    #+#             */
/*   Updated: 2026/02/06 12:19:01 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Renvoie l'indice du premier '\n' ou la longueur si pas de '\n' */
int	checknewline(const char *stash)
{
	int	i;

	if (!stash)
		return (0);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return (i);
}
