/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:41:19 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/30 12:56:42 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*first;

	first = (char *)s;
	i = (int)ft_strlen(s);
	while (i >= 0)
	{
		if (*first == (char)c)
			return (first);
		first++;
		i--;
	}
	return (0);
}
