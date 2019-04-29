/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 15:24:57 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/29 19:04:11 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	unsigned char	ss1;
	unsigned char	ss2;
	int				i;

	i = 0;
	ss1 = (unsigned char)s1[i];
	ss2 = (unsigned char)s2[i];
	if (n == 0)
		return (0);
	while (n > 0 && ss1 == ss2)
	{
		if (ss1 == '\0' && ss2 == '\0')
			return (0);
		if (n > 0)
		{
			ss1 = (unsigned char)s1[i];
			ss2 = (unsigned char)s2[i];
			i++;
		}
		n--;
	}
	return (ss1 - ss2);
}
