/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:48:07 by rennacir          #+#    #+#             */
/*   Updated: 2022/11/19 16:31:14 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_f(char *buff, char *stvr, int fd)
{
	int	i;

	i = 15;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (ft_strchr(stvr, '\n') != 1 && i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = '\0';
		stvr = ft_strjoin(stvr, buff);
	}
	free(buff);
	return (stvr);
}

char	*tmp_f(char *stvr)
{
	int		i;
	char	*tmp;
	int		count;

	count = 0;
	if (!(*stvr))
		return (NULL);
	while (stvr[count] != '\n' && stvr[count] != '\0')
		count++;
	tmp = malloc(count + 2);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < count)
	{
		tmp[i] = stvr[i];
		i++;
	}
	if (stvr[i] == '\n')
	{
		tmp[i] = '\n';
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*free_sta(char *stvr)
{
	char	*tmp;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!(*stvr) || !stvr)
		return (free(stvr), NULL);
	while (stvr[count] != '\n' && stvr[count] != '\0')
		count++;
	if (stvr[count] == '\n')
		count++;
	tmp = malloc(ft_strlen(stvr) - count + 1);
	if (!tmp)
		return (NULL);
	while (stvr[i + count])
	{
		tmp[i] = stvr[i + count];
		i++;
	}
	tmp[i] = '\0';
	free(stvr);
	stvr = NULL;
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*tmp;
	static char	*stvr[10240];
	int			count;

	buff = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647
		|| read(fd, NULL, BUFFER_SIZE < 0))
		return (NULL);
	count = 0;
	stvr[fd] = read_f(buff, stvr[fd], fd);
	tmp = tmp_f(stvr[fd]);
	stvr[fd] = free_sta(stvr[fd]);
	return (tmp);
}
