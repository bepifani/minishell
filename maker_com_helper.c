/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker_com_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:02:56 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/05 19:53:35 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_helper(char *str, int *i) //helper
{
	int	j;

	j = 0;
	while (str[*i] == ' ' && str[*i] != '\0')
	{
		j++;
		(*i)++;
	}
	return (j);
}

void	ft_skiper2(char *str, int *i, int *j) //ft_skipp
{
	if (str[*i] == 34)
	{
		while (str[*i] != 34 && str[*i] != '\0')
		{
			(*i)++;
			(*j)++;
		}
	}
	else if (str[*i] == 39)
	{
		while (str[*i] != 39 && str[*i] != '\0')
		{
			(*i)++;
			(*j)++;
		}
	}
	else if (ft_isalnum(str[*i]) || str[*i] == '.')
	{
		while ((ft_isalnum(str[*i]) || str[*i] == '.') && str[*i] != '\0')
		{
			(*i)++;
			(*j)++;
		}
	}
}

int	ft_find_name(char *str, int i, char symbol) //find_name_len
{
	int	j;
	
	j = 0;
	while (str[i] == symbol)
	{
		i++;
		j++;
	}
	j = j + ft_helper(str, &i);
	ft_skiper2(str, &i, &j);
	return (j);
}

char	*ft_skiper(char *str) //ft_skipsimic
{
	char	*c;

	c = ft_substr(str, 1, ft_strlen(str));
	if (str != NULL)
		free(str);
	return (c);
}

char	*ft_remake(t_info *info, int i, int name, int pos) //ft_rebilder
{
	char	*line;
	char	*line1;
	char	*line2;
	char	*line3;

	line1 = ft_substr(info->commands[pos], 0, i);
	line = ft_substr(info->commands[pos], i, name);
	line2 = line1;
	line3 = ft_substr(info->commands[pos], i + name, \
			(ft_strlen(info->commands[pos]) - i - name));
	line1 = ft_strjoin(line1, line3);
	if (info->commands[pos] != NULL)
		free (info->commands);
	info->commands[pos] = line1;
	if (line2)
		free(line2);
	if (line3)
		free(line3);
	return (line);
}