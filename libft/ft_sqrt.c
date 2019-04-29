/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sqrt.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 09:54:08 by dkroeke        #+#    #+#                */
/*   Updated: 2019/04/22 17:15:23 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;
	int j;

	i = 1;
	if (nb < 1)
		return (0);
	if (nb % 2 == 0)
		i++;
	while (i <= nb / 2)
	{
		j = i * i;
		if (j >= 2147483646 || j > nb)
			return (0);
		if (j == nb)
			return (i);
		else if (j > nb)
			return (i - 1);
		i += 2;
	}
	return (0);
}
