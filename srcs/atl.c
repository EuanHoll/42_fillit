/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atl.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 17:39:18 by ehollidg       #+#    #+#                */
/*   Updated: 2019/05/01 13:10:08 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		assign_work(t_ter **ter, t_point *stpnt,
	t_point *fnd, char **str)
{
	if (str[(*fnd).y][(*fnd).x] == '#' && (*stpnt).z == 0)
	{
		(*stpnt).z = 1;
		(*stpnt).x = (*fnd).x;
		(*stpnt).y = (*fnd).y;
	}
	if (str[(*fnd).y][(*fnd).x] == '#')
	{
		(*ter)->point[(*fnd).z].x = (*fnd).x - (*stpnt).x;
		(*ter)->point[(*fnd).z].y = (*fnd).y - (*stpnt).y;
		(*fnd).z++;
	}
}

static t_ter	*assign(char **str)
{
	t_ter	*ter;
	t_point	stpnt;
	t_point	fnd;

	ter = ft_memalloc(sizeof(t_ter));
	if (ter == NULL)
		return (NULL);
	fnd.z = 0;
	fnd.x = 0;
	fnd.y = 0;
	stpnt.z = 0;
	while (str[fnd.y][fnd.x])
	{
		fnd.y = 0;
		while (fnd.y < 4 && str[fnd.y][fnd.x])
		{
			assign_work(&ter, &stpnt, &fnd, str);
			fnd.y++;
		}
		fnd.x++;
	}
	return (ter);
}

static int		is_beside(t_point a, t_point b)
{
	if ((a.x - 1 == b.x && a.y == b.y) || (a.x + 1 == b.x && a.y == b.y)
	|| (a.y + 1 == b.y && a.x == b.x) || (a.y - 1 == b.y && a.x == b.x))
		return (1);
	return (-1);
}

static int		check_ter(t_point p[4])
{
	int i;
	int k;
	int j;
	int l;

	i = 0;
	l = 0;
	while (i < 4)
	{
		k = 0;
		j = 0;
		while (k < 4)
		{
			if (i != k && is_beside(p[i], p[k]) == 1)
				j++;
			k++;
		}
		if (j <= 1)
			l++;
		i++;
	}
	if (l > 3)
		return (-1);
	return (1);
}

int				atl(char **str, t_list **lst, int num)
{
	t_list	*elm;
	t_ter	*ter;

	if (num > 25)
		return (-1);
	elm = ft_lstnew(NULL, 0);
	if (elm == NULL || lst == NULL)
		return (-1);
	ter = assign(str);
	if (ter == NULL)
	{
		ft_lstdelone(&elm, NULL);
		return (-1);
	}
	ter->c = 'A' + num;
	ter->st = 0;
	elm->content = ter;
	elm->content_size = sizeof(ter);
	if (!*lst)
		*lst = elm;
	else
		ft_lstaddend(lst, elm);
	if (check_ter(ter->point) == -1)
		return (-1);
	return (1);
}
