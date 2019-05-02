/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove_tetro.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 13:21:37 by ehollidg       #+#    #+#                */
/*   Updated: 2019/05/01 13:21:55 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			remove_tetro(t_list **tet, char **map, t_point p)
{
	char	tmp;
	int		k;

	k = 0;
	tmp = CONT(tet)->c;
	while (k < 4)
	{
		if (map[PT(k).y + p.y][PT(k).x + p.x] == tmp)
			map[PT(k).y + p.y][PT(k).x + p.x] = '.';
		k++;
	}
	CONT(tet)->st = 0;
	return (1);
}
