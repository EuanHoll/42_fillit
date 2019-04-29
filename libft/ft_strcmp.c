/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 10:19:10 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/30 15:37:39 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char const *s1, char const *s2)
{
	unsigned char	ss1;
	unsigned char	ss2;
	int				i;

	ss1 = (unsigned char)*s1;
	ss2 = (unsigned char)*s2;
	i = 0;
	while (ss1 == ss2)
	{
		if (ss1 == '\0' && ss2 == '\0')
			return (0);
		ss1 = (unsigned char)s1[i];
		ss2 = (unsigned char)s2[i];
		i++;
	}
	return (ss1 - ss2);
}
