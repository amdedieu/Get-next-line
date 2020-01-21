/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:47:17 by ameliadedie       #+#    #+#             */
/*   Updated: 2020/01/21 16:44:03 by amdedieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_nl(char *cache, int i, char c)
{
	if (!cache)
		return (0);
	while (cache[i])
	{
		if (cache[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

void	ft_fill_line(char **cache, char **line)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = (find_nl(*cache, 0, '\n') ? find_nl(*cache, 0, '\n')
		: ft_strlen(*cache));
	if (!((*line) = malloc(sizeof(char) * (size + 1))))
		return ;
	while (i < size)
	{
		*((*line) + j) = *((*cache) + i);
		i++;
		j++;
	}
	(*((*line) + (size > 1 ? size - 1 : 0))) = '\0';
	*cache = ft_strndup(cache, ft_strlen(*cache), find_nl(*cache, 0, '\n'));
}

int		ft_return(int ret, char **cache, char *buf, char **line)
{
	if (ret >= 0)
	{
		buf[ret] = '\0';
		*cache = ft_strjoinfree(cache, buf);
		if (!find_nl(*cache, 0, '\n'))
		{
			*line = ft_strndup(cache, ft_strlen(*cache) + 1, 0);
			return (0);
		}
	}
	ft_fill_line(cache, line);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	static char	*cache = NULL;

	if ((fd < 0 || line == NULL || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0))
		return (-1);
	if (find_nl(cache, 0, '\n'))
	{
		ft_fill_line(&cache, line);
		return (1);
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) == BUFFER_SIZE)
	{
		buf[ret] = '\0';
		cache = ft_strjoinfree(&cache, buf);
		if (find_nl(buf, 0, '\n'))
		{
			ft_fill_line(&cache, line);
			return (1);
		}
	}
	return (ft_return(ret, &cache, buf, line));
}
