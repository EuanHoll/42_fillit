/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 14:29:34 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/30 12:40:44 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (del != NULL)
		del((*alst)->content, (*alst)->content_size);
	free((*alst));
	(*alst) = NULL;
}
