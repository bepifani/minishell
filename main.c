/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:54:50 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/18 17:39:29 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main (int argc, char **argv, char **envp)
{
	t_info	info;
	
	(void)argv;
	(void)envp;
	if (argc == 1)
	{
		info.line = readline(PROMPT);
		ft_echo(&info.line);
		//ft_pwd();
	}
	int a;
	a = ft_check_scobe(&info);
	printf ("%d\n",a);
	return (0);
}