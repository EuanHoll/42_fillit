/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcw.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 16:21:02 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/30 16:25:56 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcw(const char *s, char c)
{
	int		i;
	int		cw;

	i = 0;
	cw = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			cw++;
		i++;
	}
	return (cw);
}
