/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 15:14:12 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/30 15:55:55 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	j = (int)ft_strlen(needle);
	while (haystack[i] != '\0' && len > i)
	{
		if (needle[0] == haystack[i])
		{
			while (needle[k] != '\0' && needle[k] == haystack[i + k] &&
			i + k < len)
				k++;
			if (k == j)
				return ((char *)&haystack[i]);
		}
		i++;
		k = 0;
	}
	return (0);
}
