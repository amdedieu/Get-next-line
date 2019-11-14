/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:26:13 by amdedieu          #+#    #+#             */
/*   Updated: 2019/11/14 20:10:53 by amdedieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int		ft_find_nl(char *cache)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(cache);
	while (i < size)
	{
		if (cache[i] == '\n')
			return (i);
		i++;
	}
	return (i - 1);
}

char	*ft_strndup(char *s, int size)
{
	char	*dst;
	int		i;

	i = -1;
	if (!(dst = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (++i < size)
		dst[i] = s[i];
	dst[i] = '\0';
	return (dst);
}

int		ft_check_cache(char *cache)
{
	int i;
	int count;

	if (!cache)
		return (0);
	i = -1;
	count = 0;
	while (cache[++i])
		(cache[i] == '\n') ? count++ : 0;
	return (count > 1 ? 1 : 0);
}

int 	ft_fill_line(char *cache, char c, char **line)
{
	int i;
	char *ret;
	int size;

	size = ft_find_nl(cache);
	i = -1;
	ret = ft_strndup(cache, size);
	if (*line)
		free(*line);
	*line = ret;
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int	j;
	int	i;

	i = ft_strlen((char*)s1);
	j = ft_strlen((char*)s2);
	if (!(str = malloc(sizeof(char) * (i + j) + 1)))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_strlen(s1))
		str[i] = s1[i];
	while (j < ft_strlen(s2))
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}


int		get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;
	static	char	*cache = NULL;
	int 			res;

	if (fd < 0)
		return (-1);
	while (!ft_check_cache(cache) && (res = read(fd, buf, BUFFER_SIZE)))
	{
		buf[res] = '\0';
		tmp = cache;
		cache = ft_strjoin(tmp, buf);
		free(tmp);
	}
	if (cache)
	{
		ft_fill_line(cache,'\n', line);
		tmp = cache;
		res = ft_find_nl(cache) + 1;
		if (res >= ft_strlen(cache))
		{
			free(cache);
			cache = NULL;
			return (1);
		}
		cache = ft_strndup(cache + res, ft_strlen(cache + res));
		free(tmp);
	}
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int fd;
	char *res;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &res) == 1)
	{
		printf("-> %s\n", res);
		//write(1, res, ft_strlen(res));
		//write(1, "\n", 1);
	}
	while (1);
	return (0);
}
