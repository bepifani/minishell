/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_for_com2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:25:19 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/05 20:45:31 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_pipe_to_str(t_info *info, int *i, int *j) //pipe_to_string
{
	int		size;
	char	*new_line;

	size = ft_strlen(info->splited[(*i)]) + 1;
	new_line = malloc(sizeof(char) * (size + 1));
	if (!new_line)
		ft_error(info, 1);
	new_line = ft_strjoin(new_line, info->splited[(*i)]);
	new_line[ft_strlen(new_line)] = ' ';
	new_line[ft_strlen(new_line) + 1] = '\0';
	(*j)++;
	(*i)++;
	return (new_line);
}

char	*ft_gnl_join(char *line, char *buf) //ft_gnlstrjoin
{
	char	*str;
	int		i;
	int		j;

	i = ft_strlen(line) + ft_strlen(buf);
	if (!line && !buf)
		return (NULL);
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		ft_error(NULL, 1);
	i = 0;
	j = 0;
	if (line)
	{
		while (line[i])
			str[j++] = line[i++];
		i = 0;
	}
	while (buf[i])
		str[j++] = buf[i++];
	str[ft_strlen(line) + ft_strlen(buf)] = '\0';
	free(line);
	return (str);
}

int	ft_checker_env(char *str) //ft_checkenv_d
{
	int		size;
	char	*tmp;

	size = 0;
	while (str && str[size] != ' ' && str[size] != 34 && str[size] != '\0')
		size++;
	tmp = ft_substr(str, 0, size);
	if (!strncmp(tmp, "$?", 2))
	{
		if (tmp)
			free(tmp);
		return (2);
	}
	if (check_name_var(tmp + 1) == 0)
	{
		if (tmp)
			free(tmp);
		return (1);
	}
	if (tmp)
		free(tmp);
	return (0);
}

int	ft_swap_ask(t_info *info, int index, int i) //ft_swap_ask
{
	char	*digit;

	digit = ft_itoa(g_error);
	if (!digit)
		return (ft_error(info, 1));
	info->splited[index] = ft_import(info->splited[index], \
		digit, i, ft_strlen(digit) + 1);
	return (ft_strlen(digit) - 1);
}
