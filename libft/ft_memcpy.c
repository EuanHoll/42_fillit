/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 13:45:30 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/29 18:04:18 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*p1;
	const char	*p2;
	int			i;

	p1 = (char *)dst;
	p2 = (const char *)src;
	i = 0;
	while ((int)n > i)
	{
		p1[i] = p2[i];
		i++;
	}
	return (dst);
}
