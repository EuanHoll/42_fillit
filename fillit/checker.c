/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 12:30:19 by ehollidg       #+#    #+#                */
/*   Updated: 2019/04/29 16:51:03 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			check_around(char **str, t_point loc)
{
	int		count;

	count = 0;
	if (loc.x - 1 >= 0 && str[loc.x - 1][loc.y] && str[loc.x - 1][loc.y] == '#')
		count++;
	if (loc.y - 1 >= 0 && str[loc.x][loc.y - 1] && str[loc.x][loc.y - 1] == '#')
		count++;
	if (str[loc.x][loc.y + 1] && str[loc.x][loc.y + 1] == '#')
		count++;
	if (str[loc.x + 1][loc.y] && str[loc.x + 1][loc.y] == '#')
		count++;
	return (count > 0 && count < 4);
}

int					ch_in(char **str)
{
	t_point i;

	i.x = 0;
	i.z = 0;
	while (i.x < 4)
	{
		if (ft_strlen(str[i.x]) != 5)
			return (-1);
		i.y = 0;
		while (i.y < 4)
		{
			if ((str[i.x][i.y] != '.' && str[i.x][i.y] != '#') ||
				(str[i.x][i.y] == '#' && check_around(str, i) == -1))
				return (-1);
			if (str[i.x][i.y] == '#')
				i.z++;
			i.y++;
		}
		i.x++;
	}
	if (i.x != 4 || i.z != 4)
		return (-1);
	return (1);
}
