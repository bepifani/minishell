/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:02:01 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/22 18:50:18 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_size_of_pipe(char *line, int i)
{
	int	size;

	size = 0;
	while (line[i] != '|' && line[i] != '\0')
	{
		i++;
		size++;
	}
	return (size);
}

char *ft_str_to_pipe(char *line, int size, int j)
{
	char	*str = NULL;;
	int		i;
	
	i = 0;
	//str = malloc(sizeof(char) * size + 1);
	while (size > 0)
	{
		str[i] = line[j];
		j++;
		i++;
		size--;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split_to_pipe(char *line)
{
	char	**mas;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mas = NULL;
	while (line[i] != '\0')
	{
		mas[j] = malloc((sizeof(char)) * ft_size_of_pipe(line, i));
		mas[j] = ft_str_to_pipe(line, ft_size_of_pipe(line, i), i);
		j++;
		i++;
	}
	mas[j] = NULL;
	return (mas);
}
