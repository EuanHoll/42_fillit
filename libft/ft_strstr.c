/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 11:25:51 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/30 15:55:12 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	j = (int)ft_strlen(needle);
	while (haystack[i] != '\0')
	{
		if (needle[0] == haystack[i])
		{
			while (needle[k] != '\0' && needle[k] == haystack[i + k])
				k++;
			if (k == j)
				return ((char *)&haystack[i]);
		}
		i++;
		k = 0;
	}
	return (0);
}
