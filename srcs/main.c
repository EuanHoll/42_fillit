/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 11:39:01 by ehollidg       #+#    #+#                */
/*   Updated: 2019/05/13 17:03:52 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	clear_st(t_list **tet)
{
	int		k;
	t_list	*temp;

	k = 0;
	temp = *tet;
	while (temp != NULL)
	{
		CONT(&temp)->st = 0;
		temp = temp->next;
	}
}

static int	get_min_cube(int lst)
{
	int i;
	int j;

	i = lst * 4;
	j = 1;
	while (j * j < i)
	{
		if (j * j == i)
			return (j + 1);
		j++;
	}
	return (j - 1);
}

static void	clean_up(t_list **lst, char **map, int len)
{
	ft_lstdel(lst, del_tet);
	free(lst);
	clear_array(map, len);
	free(map);
}

static int	make_map(t_list **lst)
{
	char	**map;
	int		m;
	int		j;
	t_point	k[1];

	m = get_min_cube(ft_lstcnt(*lst)) + 2;
	j = 0;
	k->x = 0;
	k->y = 0;
	while (j == 0)
	{
		map = ft_create_tdaf(m, m);
		clear_st(lst);
		k->z = 0;
		j = fil_solver(lst, map);
		if (j == 0)
		{
			clear_array(map, m + 1);
			free(map);
		}
		m++;
	}
	print_fillit(map);
	clean_up(lst, map, m);
	return (1);
}

int			main(int argc, char **argv)
{
	t_list	**ter;

	if (argc == 2)
	{
		ter = ret_ter(argv[1]);
		if (ter == NULL)
		{
			ft_putendl("error");
		}
		else
		{
			if (make_map(ter) == -1)
				ft_putendl("error");
		}
	}
	else
	{
		ft_putendl("Usage : Give one file location as an arg");
	}
	return (0);
}
