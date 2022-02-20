/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:35:59 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/20 17:34:48 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_scobe(t_info *info) //?
{
	int	i = 0;
	int	count1 = 0;
	int	count2 = 0;
	
	while (info->line[i] != '\0')
	{
		if (info->line[i] == '"' && count1 == 0)
			count1++;
		else if (info->line[i] == '"' && count1 == 1)
			count1--;
		else if (info->line[i] == 39 && count2 == 0)
			count2++;
		else if (info->line[i] == 39 && count2 == 1)
			count2--;
		i++;
	}
	if (count1 == 0 && count2 == 0)
		return (1);
	else
		return (0);
}

int	ft_check_str_pipe(char *str) // +
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

int	ft_check_pipe(t_info *info) // +
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
			i++;
			if (info->line[i] == '|' || info->line[i + 1] == '|')
			{
				return (0);
				break ;
			}
			while (info->line[i] != '|' && info->line[i] != '\0')
			{
				str[j] = info->line[i];
				i++;
				j++;
			}
			printf ("%s\n", str);
			if (ft_check_str_pipe(str) == 0)
				return (0);
			j = 0;
			free (str);
			i--;
		}
		i++;
	}
	return (1);
}

void	ft_line_to_mas(t_info *info) //?
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

int	ft_chack_spase(t_info *info) //+
{
	size_t	i;

	i = 0;
	while(info->line[i] != '\0' && info->line[i] == ' ')
		i++;
	if (i == ft_strlen(info->line))
		return (0); 
	else
		return (1);
}

int	ft_redirect_helper (int i, char *line)
{
	int j = 0;
	
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	j = i + 1;
	if (line[i + 1] == '>' || line[i + 1] == '<' || line[i + 1] == '|' || !line[i + 1])
		return (0);
	if (line[j - 1] == '>' && line[j  + 1] == '>' && ft_isdigit(line[j]) == 1)
		return(0);
	return (1);
}

int	ft_check_redirect(t_info *info)
{
	int i;

	i = 0;
	while (info->line[i] != '\0')
	{
		if (info->line[i] == '>' || info->line[i] == '<')
		{
			if ((info->line[i+1] == '>' && info->line[i] == '>') || (info->line[i+1] == '<' && info->line[i] == '<'))
			{
				i++;
				if (ft_redirect_helper(i, info->line) == 0)
					return (0);
				i++;
			}
			else
			{
				if (ft_redirect_helper(i, info->line) == 0)
					return (0);
			}
		}
		i++;
	}
	return (1);
}

int ft_scobes(char *line)
{
	int i = 0;
	int check = 0;

	while (line[i] !='\0')
	{
		if (line[i] == 34 && (check == 0 || check == 1))
		{
			if (check == 0)
				check == 1;
			else
				check == 0;
		}
		if ((check == 0 || check == 2) && line[i] == 39)
		{
			if (check == 0)
				check == 2;
			else
				check == 0;
		}
		i++;
	}
	return (check);
}

int	ft_parser(t_info *info)
{
	if (ft_scobe(info->line))
		ft_error ();
	if (!ft_chack_spase(info) || !ft_check_pipe(info) || !ft_check_redirect(info));
		ft_error();
	return (0);
}