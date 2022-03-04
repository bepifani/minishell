/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:29:56 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/04 13:33:36 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_get_modif_arg(char **argv) //get_modif_arg
{
	int		n;
	int		acc;
	char	**modif_arg;

	n = -1;
	acc = 0;
	while (argv[++n])
		if (ft_strncmp(argv[n], ";", 1) && argv[n][0] != '\0')
			acc++;
	modif_arg = ft_calloc(acc + 1, sizeof(char *));
	if (modif_arg == NULL)
		ft_error(NULL, 1);
	modif_arg[acc] = NULL;
	n = -1;
	acc = 0;
	while (argv[++n])
		if (ft_strncmp(argv[n], ";", 1) && argv[n][0] != '\0')
			modif_arg[acc++] = ft_strdup(argv[n]);
	if (argv)
		ft_myfree(argv);//?????????????????
	return (modif_arg);
}

char	**ft_add_string(char **arr, char *str) //ft_add_string
{
	int		n;
	char	**result;

	n = 0;
	while (arr && arr[n])
		n++;
	result = ft_calloc(n + 1 + (str != NULL), sizeof(char *));
	if (!result)
		ft_error(NULL, 1);//??????????????
	result[n + (str != NULL)] = NULL;
	n = 0;
	while (arr && arr[n])
	{
		result[n] = ft_strdup(arr[n]);
		n++;
	}
	result[n] = ft_strdup(str);
	if (arr)
		ft_myfree(arr);//???????????????
	if (str)
		free(str);
	return (result);
}

void	ft_mas_from_arr_helper(char *s, int *c, int *len) //foo_helper
{
	while (s[(*c)] && (s[(*c)] == '<' || s[(*c)] == ' '))
	{
		(*c)++;
		(*len)++;
	}
	while (s[(*c)] && s[(*c)] != '<' && s[(*c)] != ' ')
	{
		(*c)++;
		(*len)++;
	}
}

char	**ft_mas_from_arr(char **arr) //foo_bar
{
	char	**res;
	int		n;
	int		c;
	int		len;

	n = 0;
	res = NULL;
	while (arr[n])
	{
		if (ft_strncmp(arr[n], "<", 1))
			res = ft_add_string(res, ft_strdup(arr[n])); //????????
		else
		{
			c = 0;
			while (arr[n][c] == '<')
			{
				len = 0;
				foo_helper(arr[n], &c, &len);  //?????????????
				res = ft_add_string(res, ft_substr(&arr[n][c - len], 0, len)); //???????????
			}
		}
		n++;
	}
	ft_myfree(arr); //????????
	return (res);
}
