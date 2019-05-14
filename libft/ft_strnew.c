/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 11:41:08 by dkroeke        #+#    #+#                */
/*   Updated: 2019/05/02 13:29:12 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char *str;

	if ((int)size < 0)
		return (NULL);
	str = (char*)ft_memalloc(size + 1);
	if (!str)
		return (NULL);
	return (str);
}
