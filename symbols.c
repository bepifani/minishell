/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbols.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:10:27 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/04 14:38:47 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_delete_symbol(char *str, char *line) //ft_delquot
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 34)
		{
			i++;
			while (str[i] != 34 && str[i] != '\0')
				line[j++] = str[i++];
		}
		else if (str[i] == 39)
		{
			i++;
			while (str[i] != '\0' && str[i] != 39)
				line[j++] = str[i++];
		}
		if (str[i] == 39 || str[i] == 34)
			i++;
		line[j++] = str[i++];
	}
	line[j] = '\0';
}

void	ft_swaper(t_info *info, int q, char *str) //ft_swap_string
{
	int		i;
	char	*line1;
	char	*line2;

	i = 0;
	while (info->splited[q][i] == ' ' && info->splited[q][i] != '\0')
		i++;
	while (info->splited[q][i] != ' ' && info->splited[q][i] != '\0')
		i++;
	line1 = ft_substr(info->splited[q], i, (ft_strlen(info->splited[q]) - i));
	line2 = ft_strjoin(str, line1);
	if (info->splited[q])
		free (info->splited[q]);
	if (line1)
		free (line1);
	if (str)
		free (str);
	info->splited[q] = line2;
}

void	ft_first_comm(t_info *info) //ft_changefirstcomm
{
	int		i;
	char	**mas;
	char	*line;
	char	*new_line;

	i = 0;
	while (info->splited[i])
	{
		mas = ft_split(info->splited[i], ' ');
		if (ft_where_is_quot(mas[0]) == 0)
		{
			if (ft_strrchr(mas[0], 34) || ft_strrchr(mas[0], 39))
			{
				new_line = malloc(sizeof(char) * (ft_strlen(mas[0]) - 1));
				if (new_line == NULL)
					ft_error(info, 1);
				ft_delete_symbol(mas[0], new_line);
				line = new_line;
				ft_swaper(info, i, line);
			}
		}
		ft_myfree(mas);
		i++;
	}
}

int	ft_checker_for_name(char *line) //check_name_var_pars
{
	if (!line)
		return (0);
	if (!ft_isalpha(*line))
		if (*line != '_')
			return (0);
	while (line && *line && *line != '=' && *line != '$'
		&& *line != 34 && *line != 39)
	{
		if (!ft_isalnum(*line) && *line != '_')
			return (0);
		line++;
	}
	return (1);
}

int	ft_checker_for_pars(char *str) //ft_checkenv_d_pars
{
	int		size;
	char	*line;

	size = 0;
	while (str && str[size] != ' ' && str[size] != 34 && str[size] != '\0')
		size++;
	line = ft_substr(str, 0, size);
	if (!strncmp(line, "$?", 2))
	{
		if (line)
			free(line);
		return (2);
	}
	if (ft_checker_for_name(line + 1) == 0)
	{
		if (line)
			free(line);
		return (1);
	}
	if (line)
		free(line);
	return (0);
}
