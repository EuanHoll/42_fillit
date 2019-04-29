/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_ret.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 11:40:55 by ehollidg       #+#    #+#                */
/*   Updated: 2019/04/19 11:50:01 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list			**free_ret(t_list **elm)
{
	ft_lstdel(elm, NULL);
	return (NULL);
}
