/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1env.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:56:51 by nbyrd             #+#    #+#             */
/*   Updated: 2022/03/05 20:42:11 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_envp(t_info *st)
{
	int		count;
	char	**new_env;
	t_list	*dup;
	int		i;

	count = ft_lstsize(st->vars);
	new_env = malloc(sizeof(char *) * (count + 1));
	
	if (!new_env)
		return (ft_error(st, 1));
	new_env[count] = NULL;
	dup = st->vars;
	i = 0;
	while (dup)
	{
		new_env[i++] = ft_strdup(dup->content);
		dup = dup->next;
	}
	if (st->env)
		ft_myfree(st->env);
	st->env = new_env;
	return (1);
}

void	get_env(t_info *st)
{
	t_list	*dup;

	dup = st->vars;
	while (dup)
	{
		ft_putstr_fd(dup->content, 1);
		ft_putchar_fd('\n', 1);
		dup = dup->next;
	}
	exit(0);
}