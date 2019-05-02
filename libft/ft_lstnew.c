/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 12:31:25 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/29 21:08:17 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!(new_elem))
		return (NULL);
	if (content)
	{
		new_elem->content = (void *)malloc(content_size);
		if (!(new_elem->content))
			return (NULL);
		new_elem->content = ft_memcpy(new_elem->content, content, content_size);
		new_elem->content_size = content_size;
	}
	else
	{
		new_elem->content = NULL;
		new_elem->content_size = 0;
	}
	new_elem->next = NULL;
	return (new_elem);
}
