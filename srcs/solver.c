/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 12:07:41 by dkroeke        #+#    #+#                */
/*   Updated: 2019/05/03 11:04:28 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_tetro(t_list **tet, char **map, t_point p)
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
		|| PT(k).x + p.x < 0)
			return (-1);
		if (PT(k).y + p.y > i
		|| PT(k).x + p.x > i)
			return (0);
		if (map[PT(k).y + p.y][PT(k).x + p.x] == '.')
			k++;
		else
			return (0);
	}
	return (1);
}

static int	check2_tetro(t_list **tet)
{
	t_list		*temp;
	int			i;
	int			k;

	i = ft_lstcnt(*tet);
	k = 0;
	temp = *tet;
	while (temp->next)
	{
		if (((t_ter *)temp->content)->point[0].x ==
		((t_ter *)temp->next->content)->point[0].x &&
		((t_ter *)temp->content)->point[1].x ==
		((t_ter *)temp->next->content)->point[1].x &&
		((t_ter *)temp->content)->point[2].x ==
		((t_ter *)temp->next->content)->point[2].x &&
		((t_ter *)temp->content)->point[3].x ==
		((t_ter *)temp->next->content)->point[3].x)
			k++;
		temp = temp->next;
	}
	if (k == i)
		return (1);
	return (0);
}

static void	set_point(t_point *p, int z_val, int i)
{
	p->z = z_val;
	p->x = (z_val % i);
	p->y = (z_val / i);
}

static void	set_lst(t_list **lst0, t_list **lst1, t_list **set)
{
	*lst0 = *set;
	*lst1 = *set;
}

int			fil_solver(t_list **tet, char **map)
{
	int		i;
	t_list	*lst[2];
	t_point	p;

	i = ft_strlen(map[0]) - 1;
	set_lst(&lst[0], &lst[1], tet);
	set_point(&p, 0, i);
	if (check_tetros(&lst[1]))
		return (1);
	while (p.z < i * i)
	{
		if (ft_isalpha(map[p.y][p.x]))
			set_point(&p, p.z + 1, i);
		if (check_tetro(&lst[0], map, p) > 0 && fill_tetro(&lst[0], map, p))
		{
			if (lst[0]->next == NULL || fil_solver(&lst[0]->next, map))
				return (1);
			else
				remove_tetro(&lst[0], map, p);
			if (check2_tetro(&lst[0]))
				return (0);
		}
		set_point(&p, p.z + 1, i);
	}
	return (0);
}
