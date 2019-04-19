/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 13:46:20 by dkroeke        #+#    #+#                */
/*   Updated: 2019/04/19 15:31:14 by ehollidg      ########   odam.nl         */
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

static int		fill_check_tet(char **map, t_list **tet, t_point *p)
{
	int k;
	int	i;

	i = (int)ft_strlen(*map);
	k = 0;
	while (k < 4)
	{
		if (PT(k).y + p->y < 0 || PT(k).x + p->x < 0 || PT(k).y + p->y >
		(int)ft_strlen(*map) || PT(k).x + p->x > (int)ft_strlen(*map))
			return (0);
		if (map[PT(k).y + p->y][PT(k).x + p->x] == '.')
			k++;
		else
			return (0);
	}
	k--;
	while (k >= 0)
	{
		map[PT(k).y + p->y][PT(k).x + p->x] = CONT(tet)->c;
		k--;
	}
	CONT(tet)->st = 1;
	return (1);
}

int				fil_solver(t_list **tet, char **map, t_point p)
{
	int		i;
	t_list	*first;

	i = ft_strlen(*map) - 1;
	p.x = p.z % i;
	p.y = p.z / i;
	first = *tet;
	while (p.z != i * i)
	{
		if (check_tetros(&first) && (*tet) == NULL)
			return (1);
		if ((*tet) == NULL)
			return (fil_solver(&first, map, plus_point(p)));
		while ((*tet) != NULL && CONT(tet)->st == 1)
			(*tet) = (*tet)->next;
		if (ft_isalpha(map[p.y][p.x]) || ((*tet) != NULL &&
		fill_check_tet(map, tet, &p)))
			return (fil_solver(&first, map, plus_point(p)));
		else if ((*tet) != NULL)
			(*tet) = (*tet)->next;
	}
	return (0);
}
