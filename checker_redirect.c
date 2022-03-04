/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:58:51 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/04 14:10:48 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_false_redir(char *s, int i) //err_redd
{
	int	j;

	ft_where_quot(' ', 1);
	while (s[i + 1] == ' ' && s[i + 1])
		i++;
	j = i + 1;
	if (s[i + 1] == '>' || s[i + 1] == '|'
		|| s[i + 1] == '<' || !s[i + 1])
		return (0);
	if (ft_isdigit(s[j]) && s[j - 1] == '>' && s[j + 1] == '>')
		return (0);
	return (1);
}

int	ft_check_reddir(t_info *info) //ft_check_reddir
{
	int	i;

	i = 0;
	while (info->line[i])
	{
		if (info->line[i] == '>' || info->line[i] == '<')
		{
			if ((info->line[i + 1] == '>' && info->line[i] == '>')
				|| (info->line[i + 1] == '<' && info->line[i] == '<'))
			{
				if (ft_false_redir(info->line, i + 1) == 0)
					return (1);
				i++;
			}
			else
			{
				if (ft_false_redir(info->line, i) == 0)
					return (1);
			}
		}
		i++;
	}
	return (0);
}
