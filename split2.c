/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:38:56 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/02 15:12:23 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_counter_for_words(char *str, char symbol) //ft_word_count_l
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != symbol)
	{
		if (str[i] != '\0' && str[i] != symbol)
		{
			counter++;
			while (str[i] != '\0' && str[i] != symbol)
				i++;
		}
		else
			i++;
	}
	return (counter);
}

int	ft_helper_for_words(char *str1, int i, char *str2, int c) //ft_parser_split_helper
{
	int	counter;

	counter = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] != '\0' && (str1[i] != str2[0] && str1[i] != str2[1]))
		{
			counter++;
			while (str1[i] != '\0' && (ft_where_quot(str1[i], 0) || (str1[i] != str2[0] && str1[i] != str2[1])))
			{
				if (c == 1 && ft_where_quot(str1[i], 2) == 0 && str1[i] == '|')
				{
					if (str1[i - 1] != ' ')
						counter++;
					i++;
					break ;
				}
				i++;
			}
		}
		else
			i++;
	}
	return (counter);
}

int	ft_split_helper(char *str1, int i, char *str2, int c) //ft_parser_split_helper2
{
	int	counter;

	counter = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] != '\0' && (str1[i] != str2[0] && str1[i] != str2[1]))
		{
			if (str1[i] != 39 && c != 3 && str1[i] !=34)
				counter++;
			while (str1[i] != '\0' && str1[i] != str2[0])
			{
				if (str1[i] == 39 || str1[i] == 34)
				{
					counter++;
					while (str1[i] != '\0' && ft_where_quot(str1[i], 0) != 0)
						i++;
					break ;
				}
				i++;
			}
		}
		else
			i++;
	}
	return (counter);
}