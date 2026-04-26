/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:25:15 by maxcote           #+#    #+#             */
/*   Updated: 2025/11/12 20:25:18 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while ((i + j < len) && haystack[i + j] && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
/* #include <stdio.h>
int	main()
{
	char	*s1 = "nous sommes les soeurs jumelles!";
	char	*s2 = "les";
	char	*s3 = "jesuispaslà";
	printf("diff : %s\n", ft_strnstr(s1,s2,31));
	printf("diff : %s\n", ft_strnstr(s1,s3,31));
	return(0);
}
 */
