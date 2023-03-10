/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 11:54:40 by dkroeke        #+#    #+#                */
/*   Updated: 2019/03/25 12:05:46 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void		ft_striter(char *s, void (*f)(char *))
{
	while (*s)
	{
		f(s);
		s++;
	}
}
