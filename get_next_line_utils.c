/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:55:07 by amdedieu          #+#    #+#             */
/*   Updated: 2020/01/21 16:23:22 by amdedieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str || str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strndup(char **s1, int size, int i)
{
	char	*ret;
	int		j;

	j = 0;
	if (size <= i)
	{
		free(*s1);
		*s1 = NULL;
		return (0);
	}
	if (!(ret = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size && *(*s1 + i))
	{
		ret[j] = *(*s1 + i);
		i++;
		j++;
	}
	ret[j] = '\0';
	free(*s1);
	*s1 = NULL;
	return (ret);
}

char	*ft_strjoinfree(char **s1, char *s2)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (!(ret = malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (i < ft_strlen(*s1))
		ret[j++] = (*s1)[i++];
	i = 0;
	while (i < ft_strlen(s2))
		ret[j++] = s2[i++];
	ret[j] = '\0';
	if (*s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	return (ret);
}
