/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/02 12:13:53 by dkroeke        #+#    #+#                */
/*   Updated: 2019/04/03 18:46:13 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t size, size_t increase)
{
	void		*nptr;

	nptr = (void *)malloc(sizeof(void) * (size + increase));
	ft_memcpy(ptr, nptr, size - increase);
	free(ptr);
	return (nptr);
}
