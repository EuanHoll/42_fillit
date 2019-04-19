/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 16:40:37 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/22 16:43:52 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*first;

	first = (char *)s;
	i = (int)n;
	while (i > 0)
	{
		if (*first == (char)c)
			return (first);
		first++;
		i--;
	}
	return (0);
}
