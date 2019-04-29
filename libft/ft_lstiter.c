/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 15:34:57 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/29 18:18:47 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*temp;

	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			temp = lst->next;
			f(lst);
			lst = temp;
		}
		f(lst);
	}
}
