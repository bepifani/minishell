/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1echo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:42:40 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/05 16:15:51 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char *arg, t_info *st)
{
	char	**splited;
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	splited = ft_split_wquots(arg);
	if (!ft_strcmp(splited[i], "-n"))
	{
		i++;
		flag = 1;
	}
	while (splited[i])
	{	
		ft_putstr_fd(splited[i], 1);
		i++;
		if (splited[i])
			ft_putchar_fd(' ', 1);
	}
	if (!flag)
		ft_putchar_fd('\n', 1);
	(void)st;
	exit(0);
}