/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:39:18 by amdedieu          #+#    #+#             */
/*   Updated: 2019/11/14 19:04:47 by amdedieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int fd;
	int res;
	int i;
	int j;
	int k;
	char tmp[BUFFER_SIZE];
	char **line;

	i = -1;
	j = 0;
	k = 0;
	fd = open(argv[1], O_RDONLY);
	if (!(*line = malloc(sizeof(char *) * BUFFER_SIZE)))
		return (0);
	res = read(fd, tmp, BUFFER_SIZE);
	tmp[res] = 0;
	while (tmp[++i] != '\n' && tmp[i] && j < res)
	{
		printf("%c\n", tmp[i]);
		*(*line + j) = tmp[i];
		j++;
	}
	printf("%s\n", *line);
	printf("%s\n", tmp);
	return (0);
}
