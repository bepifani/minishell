/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:02:38 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/04 14:05:32 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_size_of_line(char *args, int *i) //get_interval_len
{
	int	len;

	len = 0;
	if (is_it_quot(args[*i], 0) != 0) //??????????
	{
		(*i)++;
		while (is_it_quot(args[*i], 0) && args[*i]) //???????????
		{
			(*i)++;
			len++;
		}
	}
	else
	{
		while (args[*i] && args[*i] != 34 && args[*i] != 39 && args[*i] != ' ')
		{
			(*i)++;
			len++;
		}
	}
	return (len);
}

void	ft_maker_for_strings(int acc, char *args, char **splited) //make_strings
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	is_it_quot(' ', 1); //??????????
	while (j < acc)
	{
		len = 0;
		while (args[i] && args[i] == ' ')
			i++;
		len = get_interval_len(args, &i); //????????????
		splited[j++] = ft_substr(args, i - len, len);
	}
}

size_t	ft_word_count_up(char *s, char *c, int code) //ft_word_count_up2
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	is_it_quot(s[i], 1); //????????????
	count = ft_parser_split_helper2(s, i, c, code); //????????????
	return (count);
}

char	**ft_split_wquots(char *args) //ft_split_wquots
{
	char	**splited;
	int		acc;

	acc = ft_word_count_up(args, "  ", 0);
	splited = malloc(sizeof(char *) * (acc + 1));
	if (!splited)
		ft_error(NULL, 1); //?????????
	splited[acc] = NULL;
	is_it_quot(' ', 1); //??????????
	ft_maker_for_strings(acc, args, splited);
	return (splited);
}
