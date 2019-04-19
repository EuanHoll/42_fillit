/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_fillit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 10:26:22 by dkroeke        #+#    #+#                */
/*   Updated: 2019/04/19 10:29:08 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		print_fillit(char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[j] != NULL)
	{
		ft_putstr(map[j]);
		j++;
	}
	return (1);
}
