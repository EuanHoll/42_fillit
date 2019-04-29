/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 15:06:17 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/30 13:00:48 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*first;
	char	*last;

	last = NULL;
	first = (char *)s;
	i = (int)ft_strlen(s);
	while (i >= 0)
	{
		if (*first == (char)c)
			last = first;
		first++;
		i--;
	}
	return (last);
}
