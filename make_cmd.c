/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:59:59 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/04 13:27:15 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_com_counter(char **mas) //find_com_count
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (mas && mas[i])
		count = 1;
	while (mas && mas[i])
	{
		if (mas[i][0] == '|')
			count++;
		i++;
	}
	return (count);
}

char	**ft_create_mas(t_info *info, int *j) //ft_create_node
{
	int		i;
	int		tmp;
	int		size;
	char	**lnew_line;

	i = (*j);
	size = 0;
	while (info->commands[i] && info->commands[i][0] != '|')
	{
		i++;
		size++;
	}
	tmp = (*j);
	(*j) = i + 1;
	lnew_line = ft_calloc(size + 1, sizeof(char *));
	if (lnew_line == NULL)
		ft_error(NULL, 1); //???????
	i = 0;
	while (i + tmp < tmp + size)
	{
		lnew_line[i] = ft_strdup(info->commands[tmp + i]);
		i++;
	}
	lnew_line[i] = NULL;
	return (lnew_line);
}

char	***ft_create_cmd(t_info *info) //ft_createrofcmd
{
	char	***new_mas;
	int		i;
	int		len;
	int		order;

	i = 0;
	order = 0;
	new_mas = NULL;
	len = find_com_count(info->commands); //?????????
	if (len != 0)
	{
		new_mas = ft_calloc(len + 1, sizeof(char **));
		if (new_mas == NULL)
			ft_error(NULL, 1); //??????????
		while (i < len)
		{
			new_mas[i] = ft_create_node(info, &order); //????????
			i++;
		}
		new_mas[i] = NULL;
	}
	return (new_mas);
}
