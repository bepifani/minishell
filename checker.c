/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:37:14 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/04 14:45:21 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_where_is_quot(char *s) //ft_quot
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == 34 && (flag == 0 || flag == 1))
		{
			if (flag == 0)
				flag = 1;
			else if (flag == 1)
				flag = 0;
		}
		if (s[i] == 39 && (flag == 0 || flag == 2))
		{
			if (flag == 0)
				flag = 2;
			else if (flag == 2)
				flag = 0;
		}
		i++;
	}
	return (flag);
}

int	ft_colon(char **sst) //ft_semicolon
{
	int	i;
	int	j;

	i = 0;
	while (sst[i])
	{
		j = 0;
		ft_where_quot(sst[i][j], 1);
		while (sst[i][j])
		{
			if (ft_where_quot(sst[i][j], 0) == 0 && sst[i][j] == ';')
				return (1);
			j++;
		}	
		i++;
	}
	return (0);
}

int	ft_check_spaces(t_info *info) //check_space_inquot
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	ft_where_quot(info->line[i], 1);
	while (info->line[i] == ' ')
		i++;
	while (info->line[i])
	{
		flag = ft_where_quot(info->line[i], 0);
		if ((flag != 0) && info->line[i] == ' ')
		{
			return (1);
		}
		else if ((flag == 0) && info->line[i] == ' ')
			return (0);
		i++;
	}
	return (0);
}

void	ft_opendollar(t_info *info) //ft_opendollar
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	ft_where_quot(' ', 1);
	while (info->splited[i])
	{
		j = 0;
		flag = ft_where_quot(info->splited[i][j], 1);
		while (info->splited[i][j])
		{
			flag = ft_where_quot(info->splited[i][j], 0);
			if (info->splited[i][j] == '$')
			{
				if (flag == 2)
					while (ft_isalnum(info->splited[i][j]) && info->splited[i][j])
						j++;
				else
					j += ft_swap_symbols(info, i, j);
			}
			j++;
		}
		i++;
	}
}

int	ft_big_checker(t_info *info) //ft_com_check
{
	//signal(SIGINT, sig_void);
	if (ft_where_is_quot(info->line))
		return (ft_error(info, 4));
	if (ft_checker_for_pipes(info) || ft_check_reddir(info))
		return (ft_error(info, 4));
	info->splited = ft_split_for_words(info->line, "|");
	ft_first_comm(info);
	if (ft_semicolon(info->splited)) //????????????
	{
		ft_myfree(info->splited); //??????????????
		return (ft_error(info, 4));
	}
	ft_opendollar(info); //???????????????????
	g_error = 0;
	if (!ft_add_pipe(info))
		return (ft_error(info, 1));
	ft_last_red(info, info->commands); //???????????
	ft_maker_commands(info);
	ft_cutter(info);
	info->commands = get_modif_arg(info->commands);
	info->commands = ft_mas_from_arr(info->commands);
	info->cmd = ft_create_cmd(info);
	if (info->splited)
		free(info->splited);
	return (0);
}
