/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_for_com.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:04:32 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/03 16:22:38 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_add_end(void) //ft_add_noth
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		ft_error(NULL, 1);
	str[0] = ';';
	str[1] = '\0';
	return (str);
}

int	ft_add_helper(t_info *info, char **mas, int i, int j) //add_pipe_helper
{
	while (info->splited[i])
	{
		mas[j++] = ft_add_noth();
		mas[j++] = info->splited[i];
		mas[j++] = ft_add_noth();
		if (info->splited[i + 1] != NULL)
		{
			mas[j] = malloc(sizeof(char) * 2);
			if (mas[j] == NULL)
				return (ft_error(info, 1));
			mas[j][0] = '|';
			mas[j][1] = '\0';
			j++;
		}
		i++;
	}
	mas[j] = NULL;
	return (0);
}

int	ft_add_pipe(t_info *info) //ft_add_pipe
{
	char	**mas;
	int		len;
	int		i;
	int		j;

	len = 0;
	i = 0;
	while (info->splited[i])
		i++;
	len = (i + i - 1) + i * 2;
	mas = malloc(sizeof(char *) * (len + 1));
	if (mas == NULL)
		return (ft_error(info, 1));
	len = i;
	i = 0;
	j = 0;
	add_pipe_helper(info, mas, i, j);
	if (info->commands)
		ft_myfree(info->commands);
	info->commands = mas;
	return (1);
}