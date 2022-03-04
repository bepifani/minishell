/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:54:50 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/04 14:45:38 by bepifani         ###   ########.fr       */
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
	// int a;
	// a = ft_check_scobe(&info);
	// a = ft_check_pipe(&info);
	char **massiv;
	massiv = NULL;
	//massiv = malloc (1000);
	//massiv = ft_split_to_pipe(&info);
	printf ("0 =%s)\n1 =%s)\n2 =%s)\n", massiv[0], massiv[1], massiv[2]);
	return (0);
}