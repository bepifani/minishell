/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:02:01 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/05 18:30:40 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_where_quot(char c, int code) //is_it_quot
{
	static int	f = 0;

	if (code == 1)
	{
		f = 0;
		return (f);
	}
	if (code == 2)
	{
		return (f);
	}
	if (c == 34 && f == 0)
		f = 1;
	else if (c == 34 && f == 1)
		f = 0;
	else if (c == 39 && f == 0)
		f = 2;
	else if (c == 39 && f == 2)
		f = 0;
	return (f);
}

size_t ft_words(char *str, char *c, int code) //ft_word_count_up
{
	size_t	i;
	size_t	answ;
	
	answ = 0;
	i = 0;
	ft_where_quot(str[i], 1);
	answ = ft_helper_for_words(str, i, c, code);
	return (answ);	
}

static char	*ft_newword(char *str, char c, size_t *i) //ft_newword_up
{
	char	*mas;
	size_t	size;
	size_t	pos;

	size = 0;
	ft_where_quot(' ', 1);
	while (str[*i] == c && str[*i] != '\0')
		(*i)++;
	pos = *i;
	while (str[*i] != '\0' && (ft_where_quot(str[*i], 0) || str[*i] != c))
	{
		size++;
		(*i)++;
	}
	mas = ft_calloc(size + 1, sizeof(char));
	ft_strlcpy(mas, &str[pos], size + 1);
	return (mas);
}

char	**ft_free_mas(char **mas) //ft_mmyfree_up
{
	size_t	i;

	i = 0;
	while (mas[i])
	{
		free(mas[i]);
		i++;
	}
	free(mas);
	return (NULL);
}


char	**ft_split_for_words(char *str1, char *str2) //ft_split_up
{
	char	**mas;
	size_t	counter;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str1)
		return (NULL);
	counter = ft_words(str1, str2, 1);
	mas = ft_calloc(counter + 1, sizeof(char *));
	if (mas == NULL)
		ft_error(NULL, 1);
	while (i < counter)
	{
		mas[i] = ft_newword((char *)str1, str2[0], &j);
		if (mas[i] == NULL)
			return (ft_free_mas(mas));
		i++;
	}
	mas[i] = NULL;
	return (mas);
}
