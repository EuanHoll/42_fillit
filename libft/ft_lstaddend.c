/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstaddend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 14:42:24 by ehollidg       #+#    #+#                */
/*   Updated: 2019/04/18 14:44:42 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*blst;

	blst = *alst;
	if (new != NULL)
	{
		while (blst->next)
			blst = blst->next;
		blst->next = new;
	}
}
