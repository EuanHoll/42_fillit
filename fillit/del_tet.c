/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_tet.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 12:16:09 by ehollidg       #+#    #+#                */
/*   Updated: 2019/05/02 12:20:19 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		del_tet(void *tet, size_t size)
{
	free(&size);
	free(tet);
}
