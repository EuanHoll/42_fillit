/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlend.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 16:24:21 by dkroeke        #+#    #+#                */
/*   Updated: 2019/04/09 12:33:20 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlend(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (1);
	return (i);
}
