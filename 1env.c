/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1env.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:56:51 by nbyrd             #+#    #+#             */
/*   Updated: 2022/03/04 18:25:25 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int sizer(char **envp)
// {
//     int i;

//     i = 0;
// 	printf("QWERT\n");
// 	printf("%s\n", envp[0]);
//     while (envp[i])
//         i++;
// 	printf("QWERT2\n");
//     return (i);
// }

int set_envp(t_info *info, char **envp, int counter)
{
    int     i;
    char **new_env;

    printf("envp %p\n", envp);
	printf("SADSADDSA\n");
	printf("ABCD1\n");
    new_env = malloc(sizeof(char *) * (counter + 1));
	printf("ABCD2\n");
    i = 0;
	printf("%p", envp);
    while (envp[i])
    {
        new_env[i] = ft_strdup(envp[i]);
        i++;
		printf("POZ\n");
    }
	printf("ABCD3\n");
    info->env = new_env;
	printf("ABCD4\n");
    return (1);
}

void    ft_env(t_info *info)
{
    int i;

    i = 0;
    while (info->env[i])
    {
        ft_putstr_fd(info->env[i], 1);
        ft_putchar_fd('\n', 1);
        i++;
    }
    exit(0);
}