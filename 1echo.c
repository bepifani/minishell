/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1echo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:51:12 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/06 15:07:03 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char *arg, t_struct *st)
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
		ft_putstr(splited[i]);
		i++;
		if (splited[i])
			ft_putchar_fd(' ', 1);
	}
	if (!flag)
		ft_putchar_fd('\n', 1);
	(void)st;
	exit(0);
}
