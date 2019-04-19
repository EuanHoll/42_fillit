/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_create_tda.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 16:26:35 by dkroeke        #+#    #+#                */
/*   Updated: 2019/04/01 14:37:33 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_create_tda(int cw, int cl)
{
	int		j;
	char	**str;

	j = 0;
	if (cw == 0 || cl == 0)
		return (NULL);
	str = (char **)ft_memalloc(sizeof(char *) * (cw + 1));
	if (!str)
		return (NULL);
	str[cw + 1] = NULL;
	while (j < cw)
	{
		str[j] = ft_strnew(cl);
		if (!str[j])
			return (NULL);
		j++;
	}
	return (str);
}
