/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 10:58:23 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/30 13:04:27 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long		tot;

	i = 0;
	sign = 1;
	tot = 0;
	while (ft_isspace(str[i]))
		i++;
	while ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (!(ft_isdigit(str[i])))
			return ((int)((long)sign * tot));
		tot = tot * 10 + str[i] - '0';
		i++;
	}
	tot = ((tot > 2147483648) ? -1 : tot * (long)sign);
	tot = ((tot < -2147483649) ? 0 : tot);
	return ((int)tot);
}
