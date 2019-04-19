/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 14:05:27 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/31 13:29:11 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*ss;
	size_t		i;
	size_t		j;

	i = 0;
	j = (size_t)start;
	ss = (char *)malloc(sizeof(char) * len + 1);
	if (!ss)
		return (NULL);
	while (i < len)
	{
		ss[i] = s[j + i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
