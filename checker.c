/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:37:14 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/04 13:46:08 by bepifani         ###   ########.fr       */
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
		is_it_quot(sst[i][j], 1); //?????????
		while (sst[i][j])
		{
			if (is_it_quot(sst[i][j], 0) == 0 //??????????
				&& sst[i][j] == ';')
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
	is_it_quot (info->line[i], 1); //????????
	while (info->line[i] == ' ')
		i++;
	while (info->line[i])
	{
		flag = is_it_quot(info->line[i], 0); //????????????
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
	is_it_quot(' ', 1); //??????????????
	while (info->splited[i])
	{
		j = 0;
		flag = is_it_quot(info->splited[i][j], 1); //??????????????/
		while (info->splited[i][j])
		{
			flag = is_it_quot(info->splited[i][j], 0); //??????????????
			if (info->splited[i][j] == '$')
			{
				if (flag == 2)
					while (ft_isalnum(info->splited[i][j]) && info->splited[i][j])
						j++;
				else
					j += ft_swap_env(info, i, j); //??????????????
			}
			j++;
		}
		i++;
	}
}

int	ft_big_checker(t_info *info) //ft_com_check
{
	//signal(SIGINT, sig_void);
	if (ft_quot(info->line)) //???????????????
		return (ft_error(info, 4)); //????????????????
	if (ft_check_pipes(info) || ft_check_reddir(info)) //????????????
		return (ft_error(info, 4)); //???????????????
	info->splited = ft_split_up(info->line, "|"); //????????????
	ft_changefirstcomm(info); //??????????????
	if (ft_semicolon(info->splited)) //????????????
	{
		ft_myfree(info->splited); //??????????????
		return (ft_error(info, 4)); //?????????????
	}
	ft_opendollar(info); //???????????????????
	g_error = 0;
	if (!ft_add_pipe(info)) //????????????????
		return (ft_error(info, 1)); //??????????????
	ft_last_red(info, info->commands); //???????????
	ft_rebildredir(info); //????????????
	ft_cutter(info); //??????????????
	info->commands = get_modif_arg(info->commands); //????????????
	info->commands = foo_bar(info->commands); //???????????
	info->cmd = ft_createrofcmd(info); //??????????????
	if (info->splited)
		free(info->splited);
	return (0);
}
