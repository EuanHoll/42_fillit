/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 11:22:26 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/31 12:54:14 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	*str1;

	j = 0;
	i = (int)ft_strlen(str) - 1;
	str1 = ft_strnew(i);
	if (!str1)
		return (NULL);
	while (i != 0)
	{
		str1[j] = str[i];
		i--;
		j++;
	}
	str1[j] = str[i];
	return (str1);
}
