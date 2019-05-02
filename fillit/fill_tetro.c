/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_tetro.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 13:15:47 by ehollidg       #+#    #+#                */
/*   Updated: 2019/05/01 13:16:20 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fill_tetro(t_list **tet, char **map, t_point p)
{
	int		k;

	k = 0;
	while (k < 4)
	{
		map[PT(k).y + p.y][PT(k).x + p.x] = CONT(tet)->c;
		k++;
	}
	CONT(tet)->st = 1;
	return (1);
}
