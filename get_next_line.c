/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:26:13 by amdedieu          #+#    #+#             */
/*   Updated: 2019/11/06 16:26:58 by amdedieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_line(char *buf, char c)
{
	char *ret;
	int i;

	i = 0;
	while (buf[i] != c)
		i++;
	if (!(ret = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (buf[i] != c)
	{
		ret[i] = buf[i];
		i++;
	}
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	j;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen((char*)s1);
	j = ft_strlen((char*)s2);
	if (!(str = malloc(sizeof(char) * (i + j) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

int		ft_strchr(char *s, int c)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = 0;
	str = (char*)s;
	while (str[size])
		size++;
	while (i < size + 1)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char	*buf;
	static	char	*cache;
	size_t	i;
	size_t  j;
	
	i = 0;
	j = 0;
	if (*line = malloc(sizepf(BUFFER_SIZE)))
		return (NULL); 
	while (read(fd, buf, BUFFER_SIZE))
	{ 
		while (i < BUFFER_SIZE)
		{
			*line[i] = buf[i];
			i++;
		}

	}
}

int	main(int argc, char **argv)
{
	int fd;
	int i;
	char *res;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &res) == 1)
	{
		write(1, res, ft_strlen(res));
		write(1, "\n", 1);
	}
	return (0);
}
