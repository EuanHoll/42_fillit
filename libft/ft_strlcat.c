/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 11:53:22 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/31 13:26:22 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	j = 0;
	i = (size > ft_strlen(dst)) ? ft_strlen(dst) : size;
	while (src[j] != '\0' && (j + i + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (size > i)
		dst[i + j] = '\0';
	if (size < i + j)
		return (size);
	return (i + ft_strlen(src));
}
