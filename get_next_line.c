/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:53:01 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/06 13:53:03 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_up(char *remains, char *buffer)
{
	char	*omegalul;
	int		i;
	int		j;

	i = ft_strlen(remains) + ft_strlen(buffer);
	if (!remains && !buffer)
		return (NULL);
	omegalul = malloc(sizeof(char) * (i + 1));
	if (omegalul == NULL)
		ft_error(NULL, 1);
	i = 0;
	j = 0;
	if (remains)
	{
		while (remains[i])
			omegalul[j++] = remains[i++];
		i = 0;
	}
	while (buffer[i])
		omegalul[j++] = buffer[i++];
	omegalul[ft_strlen(remains) + ft_strlen(buffer)] = '\0';
	free(remains);
	return (omegalul);
}

char	*push_line(char *remains)
{
	char	*before_n;
	int		i;

	i = 0;
	if (!remains || !(*remains))
		return (NULL);
	while (remains[i])
		if (remains[i++] == '\n')
			break ;
	before_n = ft_substr(remains, 0, i);
	return (before_n);
}

char	*cut(char *remains)
{
	char	*after_n;
	int		i;

	i = 0;
	if (!remains)
		return (NULL);
	after_n = NULL;
	while (remains[i])
		if (remains[i++] == '\n')
			break ;
	if (remains[i] == '\0')
	{
		free(remains);
		return (NULL);
	}
	else if (remains[i - 1] == '\n')
		after_n = ft_substr(remains, i, ft_strlen(remains + i));
	free (remains);
	return (after_n);
}

int	get_next_line(char **line)
{
	int			count;
	char		buffer[BUFFER_SIZE + 1];
	static char	*remains;
	int			fd;

	count = 1;
	fd = 0;
	while (!ft_strchr(remains, '\n') && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return (-1);
		buffer[count] = '\0';
		remains = ft_strjoin(remains, buffer);
	}
	*line = push_line(remains);
	remains = cut(remains);
	if (count != 0)
		return (1);
	return (0);
}
