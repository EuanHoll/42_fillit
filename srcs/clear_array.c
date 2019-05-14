/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_array.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 11:29:44 by ehollidg       #+#    #+#                */
/*   Updated: 2019/04/19 11:39:50 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		clear_array(char **str, size_t max)
{
	while (max > 0)
	{
		ft_strdel(&str[max - 1]);
		max--;
	}
}
