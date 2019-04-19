/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 18:42:46 by ehollidg       #+#    #+#                */
/*   Updated: 2019/04/19 13:09:20 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h> // REMOVE

# define CONT(x) ((t_ter*)((*x)->content))
# define NXT(x) ((t_ter*)((*x)->next))
# define PT(x) CONT(tet)->point[(x)]

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_ter
{
	t_point		point[4];
	char		c;
	int			st;
}				t_ter;

t_list			**ret_ter(char *str);
int				check_individual(char **str);
void			clear_array(char **str, size_t max);
t_list			**free_ret(t_list **elm);
char			**ft_create_tdaf(int cw, int cl);
int				fil_solver(t_list **tet, char **map, t_point p);
int				print_fillit(char **map);

#endif
