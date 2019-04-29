/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atl.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 17:39:18 by ehollidg       #+#    #+#                */
/*   Updated: 2019/04/29 17:43:23 by ehollidg      ########   odam.nl         */
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

int				atl(char **str, t_list **lst, int num)
{
	t_list	*elm;
	t_ter	*ter;

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
	return (1);
}
