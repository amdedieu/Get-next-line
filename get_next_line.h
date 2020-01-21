/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:23:43 by amdedieu          #+#    #+#             */
/*   Updated: 2020/01/21 16:43:13 by amdedieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strndup(char **s1, int size, int i);
char	*ft_strjoinfree(char **s1, char *s2);
int		find_nl(char *cache, int i, char c);
void	ft_fill_line(char **cache, char **line);
int		get_next_line(int fd, char **line);
int		ft_return(int ret, char **cache, char *buf, char **line);

#endif
