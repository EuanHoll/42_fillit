/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 11:43:16 by ehollidg       #+#    #+#                */
/*   Updated: 2019/04/19 12:31:52 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			assign_work(t_ter **ter, t_point *stpnt,
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

static t_ter		*assign(char **str)
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

static int			add_to_list(char **str, t_list **lst, int num)
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

static t_list		**get_lst(int fd)
{
	t_list	**lst;
	char	*ar[4];
	char	*tmp;
	t_point	i;

	i.x = 0;
	i.y = 0;
	lst = (t_list**)ft_memalloc(sizeof(t_list*));
	while (read(fd, NULL, 0) != -1)
	{
		i.y = 0;
		while (i.y < 4 && ft_getline(fd, &ar[i.y]) == 1 &&
			ft_strlen(ar[i.y]) == 4)
			i.y++;
		i.z = ft_getline(fd, &tmp);
		if ((i.z > 0 && tmp[0] != '\0')
			|| check_individual(ar) < 0 || add_to_list(ar, lst, i.x) < 0)
			return (free_ret(lst));
		clear_array(ar, 4);
		i.x++;
		if (i.z == 0)
			break ;
	}
	return (lst);
}

t_list				**ret_ter(char *str)
{
	int			fd;
	t_list		**lst;

	fd = open(str, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	lst = get_lst(fd);
	close(fd);
	return (lst);
}
