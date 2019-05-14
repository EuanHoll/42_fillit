/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 11:43:16 by ehollidg       #+#    #+#                */
/*   Updated: 2019/05/11 12:04:23 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		create_strar(char *ar[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		ar[i] = ft_strnew(5);
		if (ar[i] == NULL)
		{
			clear_array(ar, i);
			return (-1);
		}
		i++;
	}
	return (1);
}

static t_list	**get_lst(int fd)
{
	t_list	**lst;
	char	tmp[2];
	char	*ar[4];
	t_point	i;

	i.x = 0;
	lst = (t_list**)ft_memalloc(sizeof(t_list*));
	while (read(fd, NULL, 0) != -1)
	{
		i.y = 0;
		if (create_strar(ar) == -1)
			return (free_ret(lst, ar, 1));
		while (i.y < 4 && read(fd, ar[i.y], 5) == 5 && ar[i.y][4] == '\n')
			i.y++;
		i.z = read(fd, &tmp, 1);
		if ((i.z > 0 && tmp[1] != '\0')
			|| ch_in(ar) < 0 || atl(ar, lst, i.x) < 0)
			return (free_ret(lst, ar, 1));
		clear_array(ar, 4);
		i.x++;
		if (i.z == 0)
			break ;
	}
	clear_array(ar, 4);
	return (lst);
}

t_list			**ret_ter(char *str)
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
