/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 15:57:10 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/29 18:09:33 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
size_t n)
{
	unsigned char			*p1;
	unsigned const char		*p2;
	size_t					i;
	unsigned char			cc;

	i = 0;
	p1 = dst;
	p2 = src;
	cc = (unsigned char)c;
	while (n > i && (i == 0 || p1[i - 1] != cc))
	{
		p1[i] = p2[i];
		i++;
		if (p2[i - 1] == cc)
			return (&dst[i]);
	}
	return (NULL);
}
