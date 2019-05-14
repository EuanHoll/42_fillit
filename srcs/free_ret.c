/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_ret.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 11:40:55 by ehollidg       #+#    #+#                */
/*   Updated: 2019/05/02 13:20:14 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list			**free_ret(t_list **elm, char *ar[4], int j)
{
	int i;

	i = 0;
	if (ar)
		while (i < 4 && ar[i] != NULL)
		{
			ft_strdel(&ar[i]);
			i++;
		}
	if (j)
	{
		ft_lstdel(elm, del_tet);
		free(elm);
	}
	return (NULL);
}
