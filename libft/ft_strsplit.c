/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 18:31:37 by dkroeke        #+#    #+#                */
/*   Updated: 2019/04/05 13:51:10 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *s, char c)
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

static int		count_letters(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char		**create_tda(const char *s, char c, char **str, int cl)
{
	int		i;
	int		cw;
	int		j;

	i = 0;
	j = 0;
	cw = count_words(s, c);
	str = (char **)ft_memalloc(sizeof(char *) * (cw + 1));
	if (!str)
		return (NULL);
	str[cw + 1] = NULL;
	while (s[i] && j <= cw)
	{
		if (s[i] == c)
			i++;
		else
		{
			cl = count_letters(&s[i], c);
			str[j] = ft_strnew(cl);
			j++;
			i += cl;
		}
	}
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		a;
	int		i;

	a = 0;
	i = 0;
	str = NULL;
	str = create_tda(s, c, str, 0);
	if (!str)
		return (NULL);
	while (s[a] != '\0')
	{
		if (s[a] == c)
			a++;
		else
		{
			ft_strncpy(str[i], &s[a], count_letters(&s[a], c));
			a += count_letters(&s[a], c);
			i++;
		}
	}
	return (str);
}
