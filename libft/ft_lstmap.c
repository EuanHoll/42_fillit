/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 17:07:53 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/29 17:42:26 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*first;

	if (!(lst))
		return (NULL);
	new = f(lst);
	first = new;
	while (lst->next != NULL)
	{
		new->next = f(lst->next);
		if (!(new || new->next))
			return (NULL);
		lst = lst->next;
		new = new->next;
	}
	return (first);
}
