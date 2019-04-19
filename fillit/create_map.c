/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 10:11:44 by dkroeke        #+#    #+#                */
/*   Updated: 2019/04/19 14:58:24 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**pop_map(char **str, int cw, int cl)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (j < cw)
	{
		while (i < cl)
		{
			str[j][i] = '.';
			if (i == cl - 1)
				str[j][i] = '\n';
			i++;
		}
		j++;
		i = 0;
	}
	return (str);
}

char			**ft_create_tdaf(int cw, int cl)
{
	int		j;
	int		i;
	char	**str;

	j = 0;
	i = 0;
	if (cw == 0 || cl == 0)
		return (NULL);
	str = (char **)ft_memalloc(sizeof(char *) * (cw + 1));
	if (!str)
		return (NULL);
	str[cw] = NULL;
	cw--;
	while (j < cw)
	{
		str[j] = ft_strnew(cl);
		if (!str[j])
			return (NULL);
		j++;
	}
	str = pop_map(str, cw, cl);
	return (str);
}
