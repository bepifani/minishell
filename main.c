/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:54:50 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/22 18:48:21 by bepifani         ###   ########.fr       */
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
	a = ft_check_pipe(&info);
	char **massiv;
	massiv = NULL;
	massiv = ft_split_to_pipe(info.line);
	printf ("%s\n", massiv[0]);
	return (0);
}