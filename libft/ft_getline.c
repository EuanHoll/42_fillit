/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getline.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 16:32:45 by dkroeke        #+#    #+#                */
/*   Updated: 2019/04/17 19:04:06 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		freeret(int ret, char **cline)
{
	if (!cline)
		return (0);
	ft_strdel(cline);
	*cline = NULL;
	return (ret);
}

static int		copy_line(char **fds, char **line)
{
	int		i;
	char	*temp;

	if (ft_strchr(*fds, '\n') != NULL)
	{
		i = ft_strlend(*fds, '\n');
		*line = ft_strsub(*fds, 0, i);
		temp = ft_strdup(*fds + i + 1);
		free(*fds);
		*fds = temp;
		return (1);
	}
	*line = *fds;
	*fds = NULL;
	return (0);
}

static int		read_gnl(char **line, int fd, char **fds, char *cline)
{
	char	*temp;
	char	*temp2;
	int		rr;

	rr = 1;
	while (rr > 0)
	{
		rr = read(fd, cline, BUFF_SIZE);
		if (rr == -1)
			return (-1);
		cline[rr] = '\0';
		temp = *line;
		*line = ft_strjoin(temp, cline);
		if (ft_strchr(*line, '\n'))
		{
			*fds = ft_strdup(*line + (ft_strlend(*line, '\n') + 1));
			temp2 = ft_strsub(*line, 0, ft_strlend(*line, '\n'));
			free(*line);
			*line = temp2;
			return (freeret(rr, &temp));
		}
		free(temp);
	}
	return (rr);
}

int				ft_getline(const int fd, char **line)
{
	int			rr;
	static char	*fds[12000];
	char		*cline;

	cline = ft_strnew(BUFF_SIZE + 1);
	if (line == NULL || read(fd, cline, 0) < 0)
		return (freeret(-1, &cline));
	*line = NULL;
	if (fds[fd] != NULL)
		if (copy_line(&fds[fd], line))
			return (freeret(1, &cline));
	if (!*line)
		*line = ft_strnew(0);
	rr = read_gnl(line, fd, &fds[fd], cline);
	free(cline);
	if (rr == 0 && ft_strlen(*line) == 0)
		return (freeret(0, line));
	if (rr == -1)
		return (-1);
	return (1);
}
