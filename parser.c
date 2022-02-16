/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:35:59 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/16 17:54:47 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_simbol1(t_info *info)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	while (info->line[i] != '\0')
	{
		if (info->line[i] == '"')
			count++;
		i++;
	}
	if (count % 2 == 0)
		return (1);
	else
		return (0);
}

int	ft_check_simbol2(t_info *info)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	while (info->line[i] != '\0')
	{
		if (info->line[i] == 39)
			count++;
		i++;
	}
	if (count % 2 == 0)
		return (1);
	else
		return (0);
}

int	ft_check_str_pipe(char *str)
{
	int	i = 0;
	size_t	count = 0;
	
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	if (count == ft_strlen(str))
		return (0);
	return (1);
}

int	ft_check_pipe(t_info *info)
{
	int		i;
	int		j = 0;
	char	*str;

	i = 0;
	str = malloc(1000);
	while (info->line[i] != '\0')
	{
		if (info->line[i] == '|')
		{
			printf ("tytt\n");
			i++;
			while (info->line[i] != '|' && info->line[i])
			{
				i++;
				str[j] = info->line[i];
				//printf ("tyt%c\n", info->line[i]);
				j++;
			}
			printf ("%s\n", str);
			if (ft_check_str_pipe(str) == 0)
				return (0);
			j = 0;
			free (str);
		}
		i++;
	}
	return (1);
}

void	ft_line_to_mas(t_info *info)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = malloc(1000);
	// if (!str)
	// 	return ();
	while (info->line[i] != '\0')
	{
		j = 0;
		while (info->line[i] != '|' && info->line[i] != '\0')
		{
			str[j] = info->line[i];
			j++;
			i++;
		}
		info->commands[j] = str;
		free(str);
		i++;
	}
	free(str);
}

// int	ft_parser(t_info *info)
// {
	
// }