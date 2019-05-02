/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 10:40:12 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/30 12:58:57 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char			*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = (int)ft_strlen(s) - 1;
	j = 0;
	k = 0;
	while ((ft_isblank(s[j]) || s[j] == '\n') && s[j])
		j++;
	while ((ft_isblank(s[i]) || s[i] == '\n') && i > j)
		i--;
	i++;
	str = ft_strnew(i - j);
	if (!str)
		return (NULL);
	ft_strncpy(str, &s[j], i - j);
	return ((char *)str);
}
