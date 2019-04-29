/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 12:07:41 by dkroeke        #+#    #+#                */
/*   Updated: 2019/04/22 18:10:38 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_tetros(t_list **tet)
{
	int		mustbe;
	int		is;
	t_list	*temp;

	temp = *tet;
	is = 0;
	mustbe = ft_lstcnt(*tet);
	while (temp != NULL)
	{
		if (((t_ter*)(temp->content))->st == 1)
			is++;
		temp = temp->next;
	}
	if (mustbe == is)
		return (1);
	return (0);
}

static t_point		plus_point(t_point p)
{
	p.z++;
	return (p);
}

int		remove_tetro(t_list **tet, char **map, t_point p)
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

int		fill_tetro(t_list **tet, char **map, t_point p)
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

int		check_tetro(t_list **tet, char **map, t_point p)
{
	int k;
	int	i;

	i = (int)ft_strlen(*map) - 2;
	k = 0;
	if (*tet == NULL || CONT(tet)->st == 1)
		return (0);
	while (k < 4)
	{
		if (PT(k).y + p.y < 0
		|| PT(k).x + p.x < 0
		|| PT(k).y + p.y > i
		|| PT(k).x + p.x > i)
			return (0);
		if (map[PT(k).y + p.y][PT(k).x + p.x] == '.')
			k++;
		else
			return (0);
	}
	return (1);
}

int		fil_solver(t_list **tet, char **map, t_point p)
{
	int		i;
	t_list	*first;
	t_list	*temp;

	i = ft_strlen(*map) - 1;
	p.x = (p.z % i);
	p.y = (p.z / i);
	temp = *tet;
	first = *tet;
	//print_fillit(map);
	if ((p.z >= i * i && check_tetros(tet)) || check_tetros(tet))
		return (1);
	else if (p.z >= i * i)
		return (0);
	if (ft_isalpha(map[p.y][p.x]))
		return (fil_solver(&first, map, plus_point(p)));
	while (temp)
	{
		if (check_tetro(&temp, map, p) && fill_tetro(&temp, map, p))
		{
			if (fil_solver(&first, map, plus_point(p)))
				return (1);
			else
				remove_tetro(&temp, map, p);
		}
		temp = temp->next;
	}
	return (0);
}

