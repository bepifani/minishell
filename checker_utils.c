/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:47:41 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/04 13:54:15 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_import(char *st, char *str, int i, int j) //ft_import
{
	char	*newline;
	int		zh[2];

	zh[0] = 0;
	newline = malloc(sizeof(char) * \
			(ft_strlen(str) + ft_strlen(st) - j + 1));
	if (!newline)
		ft_error(NULL, 1); //???????????
	while (zh[0] < i)
	{
		newline[zh[0]] = st[zh[0]];
		zh[0]++;
	}
	zh[1] = 0;
	while (str[zh[1]])
		newline[zh[0]++] = str[zh[1]++];
	i += j;
	while (st[i])
		newline[zh[0]++] = st[i++];
	newline[zh[0]] = '\0';
	if (st)
		free(st);
	if (str)
		free(str);
	return (newline);
}

int	ft_enver(t_info *info, int index, int i, int j) //ft_enver
{
	char	*newline;
	int		z;

	z = 0;
	newline = malloc(sizeof(char) * (ft_strlen(info->splited[index]) - j + 1));
	if (!newline)
		ft_error(info, 1); //?????????
	while (z < i)
	{
		newline[z] = info->splited[index][z];
		z++;
	}
	i = i + j;
	while (info->splited[index][i])
		newline[z++] = info->splited[index][i++];
	newline[z] = '\0';
	if (info->splited[index])
		free(info->splited[index]);
	info->splited[index] = newline;
	return (-1);
}

int	ft_swap_symbols(t_info *info, int index, int i) //ft_swap_env
{
	char	*name;
	int		j;
	int		tmp;
	char	*str;

	tmp = i + 1;
	if (ft_checkenv_d_pars(&info->splited[index][i]) == 2) //??????????/
		return (ft_swap_ask(info, index, i)); //???????????
	else if (ft_isdigit(info->splited[index][i + 1]))
		return (ft_enver(info, index, i, 2));
	else if (ft_checkenv_d_pars(&info->splited[index][i])) //??????????????/
		return (0);
	while (ft_isalnum(info->splited[index][tmp]) && info->splited[index][tmp])
		tmp++;
	j = 1 + (tmp - (i + 1));
	name = ft_substr(info->splited[index], i, j);
	name[ft_strlen(name) + 1] = '\0';
	name[ft_strlen(name)] = '=';
	str = find_env(name + 1, info); //???????????
	if (name != NULL)
		free(name);
	if (str == NULL)
		return (ft_enver(info, index, i, j));
	info->splited[index] = ft_import(info->splited[index], str, i, j); //???????????/
	return (ft_strlen(str) - 1);
}

int	ft_checker_for_pipes(t_info *info) //ft_check_pipes
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	is_it_quot(info->line[i], 1); //??????????????
	while (info->line[i])
	{
		j = i;
		if (is_it_quot(info->line[i], 0) == 0 && info->line[i] == '|') //?????????????
		{
			flag = 0;
			while (info->line[j + 1] != '|' && info->line[j + 1])
			{
				if (info->line[j + 1] != ' ')
					flag = 1;
				j++;
			}
			if (flag == 0)
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_cutter(t_info *info) //ft_cutter
{
	int		i;
	char	*tmp;

	i = 0;
	while (info->commands[i])
	{
		tmp = ft_strtrim(info->commands[i], " ");
		if (info->commands[i])
			free(info->commands[i]);
		info->commands[i] = tmp;
		i++;
	}
}
