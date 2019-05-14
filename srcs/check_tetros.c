/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_tetros.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 13:34:16 by ehollidg       #+#    #+#                */
/*   Updated: 2019/05/01 13:34:56 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_tetros(t_list **tet)
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
