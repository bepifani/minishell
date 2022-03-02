/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:23:41 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/02 16:59:24 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_str_redirs(char *str, int q) //ft_strrchr_upred
{
	size_t	i;
	char	*s;

	i = ft_strlen(str) + 1;
	s = (char *)str;
	ft_where_quot(' ', 1);
	while (i-- > 0)
	{
		if (s[i] == (char)q && ft_where_quot(s[i], 0))
			return (1);
	}
	return (0);
}

void	ft_make_redir(t_info *info, char *str, int pos) //ft_create_l
{
	int		i;
	int		name;
	char	*buf;

	i = ft_strlen(str);
	while (i >= 0)
	{

		if (str[i] == '<')
		{
			name = ft_find_name(str, i, '<'); //find_name_len
			buf = ft_remake(info, i, name, pos); //ft_rebilder
			info->commands[pos - 1] = ft_gnl_strjoin(info->commands[pos - 1], buf); //ft_gnlstrjoin
			if (buf != NULL)
				free(buf);
			if (info->commands[pos - 1] == ';')
				info->commands[pos - 1] = ft_skiper(info->commands[pos - 1]); //ft_skipsimic
			break ;
		}
		i--;
	}
}

void	ft_make_redir2(t_info *info, char *str, int pos) //ft_create_ll
{
	int		i;
	int		name;
	char	*buf;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '<' && str[i + 1] == '<')
		{
			name = ft_find_name(str, i, '<'); //find_name_len
			buf = ft_remake(info, i, name, pos); //ft_rebilder
			info->commands[pos - 1] = ft_gnl_strjoin(info->commands[pos - 1], buf); //ft_gnlstrjoin
			if (buf != NULL)
				free(buf);
			if (info->commands[pos - 1] == ';')
				info->commands[pos - 1] = ft_skiper(info->commands[pos - 1]); //ft_skipsimic
			break ;
		}
		i++;
	}
}

void	ft_make_redir3(t_info *info, char *str, int q) //ft_create_r
{
	int		i;
	int		name;
	char	*buf;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '>')
		{
			name = ft_find_name(str, i, '>'); //find_name_len
			buf = ft_remake(info, i, name, q); //ft_rebilder
			if (info->commands[q + 1] != NULL)
				free(info->commands[q + 1]);
			info->commands[q + 1] = buf;
			while ((info->commands[q + 1][j] == '>' || info->commands[q + 1][j] == ' ') && info->commands[q  + 1][j])
				j++;
			ft_opening(info->commands[q + 1], &info->commands[q + 1][j], 0); //open_file_h
			break ;
		}
		i++;
	}
}

void	ft_maker_commands(t_info *info) //ft_rebildredir
{
	int	i;

	i = 0;
	while (info->commands[i] != NULL)
	{
		if (info->commands[i][0] != ';')
		{
			while (ft_strnstr(info->commands[i], "<<", ft_strlen(info->commands[i])))
				ft_make_redir2(info, info->commands[i], i); //ft_create_ll
			while (ft_str_redirs(info->commands[i], '<')) //ft_strrchr_upred
				ft_make_redir(info, info->commands[i], i); //ft_create_l
			while (ft_str_redirs(info->commands[i], '>')) //ft_strrchr_upred
				ft_make_redir3(info, info->commands[i], i); //ft_create_r
		}
		if (info->commands[i + 1] && info->commands[i + 2])
			i = i + 2;
		if (info->commands[i + 1] != NULL)
			i++;
		if (info->commands[i + 1] != NULL)
			i++;
		else
			break ;
	}
}
