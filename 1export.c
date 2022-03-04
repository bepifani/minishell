/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1export.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:43:12 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/04 17:49:57 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_print_export(t_info *st)
{
	t_list	*dup;

	dup = st->vars;
	while (dup)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(dup->content, 1);
		dup = dup->next;
	}
	return (0);
}

int	ft_export_helper(t_info *st, char **splited, int i, int len)
{
	t_list	*dup;

	dup = st->vars;
	while (dup)
	{
		if (splited[i][len] != '=')
			break ;
		if (!ft_strncmp(dup->content, splited[i], len))
		{
			ft_changevar(&splited[i], &(dup), len);
			break ;
		}
		dup = dup->next;
	}
	if (!dup)
		return (0);
	return (1);
}

int	ft_export_print_err(char **splited, int i)
{
	if (!check_name_var(splited[i]))
	{
		ft_putstr_fd("export: ", 2);
		ft_putstr_fd("`", 2);
		ft_putstr_fd(splited[i], 2);
		ft_putstr_fd("': ", 2);
		ft_putstr_fd("not a valid identifier\n", 2);
		ft_myfree(splited);
		return (0);
	}
	return (1);
}

int	ft_export(char *var, t_info *st)
{
	int		len;
	char	**splited;
	int		i;

	i = 1;
	printf("RUSSIA0\n");
	splited = ft_split_wquots(var);
	printf("RUSSIA1\n");
	len = ft_getlen(splited[i]);
	printf("RUSSIA2\n");
	if (len == 0)
		return (ft_print_export(st));
	printf("RUSSIA3\n");
	while (splited[i])
	{
		if (!ft_export_print_err(splited, i))
			return (1);
		if (!ft_export_helper(st, splited, i, len))
			ft_lstadd_back(&(st->vars), ft_lstnew(ft_strdup(splited[i])));
		i++;
		len = ft_getlen(splited[i]);
	}
	printf("RUSSIA4\n");
	set_envp(st, st->env);
	printf("RUSSIA5\n");
	ft_myfree(splited);
	return (0);
}