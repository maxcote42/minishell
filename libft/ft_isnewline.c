/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnewline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:19:14 by maxcote           #+#    #+#             */
/*   Updated: 2026/02/06 12:19:16 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Vérifie si la chaîne contient un '\n' */
int	isnewline(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
