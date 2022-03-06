/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:52:51 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/06 13:52:53 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_word_count_l(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

int	ft_parser_split_helper(char *s, int i, char *c, int code)
{
	int	count;

	count = 0;
	while (s[i])
	{
		if ((s[i] != c[0] && s[i] != c[1]) && s[i])
		{
			count++;
			while ((is_it_quot(s[i], 0)
					|| (s[i] != c[0] && s[i] != c[1])) && s[i])
			{
				if (is_it_quot(s[i], 2) == 0 && s[i] == '|' && code == 1)
				{
					if (s[i - 1] != ' ')
						count ++;
					i++;
					break ;
				}
				i++;
			}
		}
		else
			i++;
	}
	return (count);
}

int	ft_parser_split_helper2(char *s, int i, char *c, int code)
{
	int	count;

	count = 0;
	while (s[i])
	{
		if (s[i] && (s[i] != c[0] && s[i] != c[1]))
		{
			if (s[i] != 34 && s[i] != 39 && code != 3)
				count++;
			while (s[i] && (s[i] != c[0] && s[i]))
			{
				if (s[i] == 34 || s[i] == 39)
				{
					count++;
					while (s[i] && is_it_quot(s[i], 0) != 0)
						i++;
					break ;
				}
				i++;
			}
		}
		else
			i++;
	}
	return (count);
}
