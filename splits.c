/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:02:01 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/23 17:40:21 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_redir1(char *str)
{
	int i;
	char *s;

	i = 0;
	s = NULL;
	while (str[i] != ' ' && str[i] != '|' && str[i] != '<' && str[i] != '>' && str[i]) 
		i++;
	s = malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] != ' ' && str[i] != '|' && str[i] != '<' && str[i] != '>' && str[i])
	{
		s[i] = str[i]; 
		i++;
	}
	//free(str);
	s[i] = '\0';
	return (s);
}

char	**ft_split_to_pipe(t_info *info)
{
	char	**mas;

	mas = NULL;
	info->cmd = NULL;
	mas = ft_split(info->line, '|');
	printf("tyt\n");
	//info->cmd[0][0] = NULL;
	printf("%s.\n", ft_redir1(mas[0]));
	info->cmd[0][0] = ft_redir1(mas[0]);
	printf("%s\n", info->cmd[0][0]);
	return (mas);
}
