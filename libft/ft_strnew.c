/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 11:41:08 by dkroeke        #+#    #+#                */
/*   Updated: 2019/04/06 16:16:53 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	if (size == 0)
		size = 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size + 1] = '\0';
	while (size != 0)
	{
		str[size] = '\0';
		size--;
	}
	str[size] = '\0';
	return (str);
}
