/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:54:50 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/04 18:32:49 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parsing(t_info *st)
{
	int	i;

	i = 0;
	ft_reinit_pip(st);
	st->line = readline("minishell> ");
	if (st->line == NULL)
		ft_sigex(st);
	if (st->line[0] == '\0')
		return (ft_mshfree1(st, 1, -1));
	if (*st->line && ft_strlen(st->line))
		add_history(st->line);
	if (ft_space_check(st->line))
		return (ft_mshfree1(st, 1, -1));
	if (ft_big_checker(st) == 1)
		return (ft_mshfree1(st, 1, 2));
	if (st->cmd == NULL)
		return (ft_mshfree1(st, 1, 1));
	signal(SIGINT, sig_void);
	if (st->cmd == NULL)
		ft_skiper3(st);
	else
		pipex(st->cmd, st);
	ft_mshfree1(st, 2, 0);
	return (0);
}

int sizer(char **envp)
{
    int i;

    i = 0;
	printf("QWERT\n");
	printf("%s\n", envp[0]);
    while (envp[i])
        i++;
	printf("QWERT2\n");
    return (i);
}
int	main(int argc, char **argv, char **envp)
{
	t_info	st;
	int	i;

	i = sizer(envp);
	printf("%p\n", envp);
	ft_init(&st, argc, argv, envp);
	printf("after init %p\n", envp);

	printf("1\n");
	set_envp(&st, envp, i);
	printf("2\n");
	while (!st.exit)
	{
		signal(SIGINT, sig_handler);
		signal(SIGQUIT, sig_handler);
		ft_parsing(&st);
	}
	return (0);
}
