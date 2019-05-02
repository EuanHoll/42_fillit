/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 12:21:06 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/30 13:04:49 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*d;
	int		i;
	int		j;

	i = 0;
	j = (int)ft_strlen(s);
	d = (char *)malloc(sizeof(char) * j + 1);
	if (!d)
		return (NULL);
	while (s[i] != '\0')
	{
		d[i] = f(s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}
