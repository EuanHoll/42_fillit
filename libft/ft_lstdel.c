/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 14:56:46 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/29 15:21:49 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*elem;

	if (*alst)
	{
		while (*alst)
		{
			elem = (*alst)->next;
			ft_lstdelone(alst, (*del));
			(*alst) = elem;
		}
	}
}
