/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:15:00 by estina            #+#    #+#             */
/*   Updated: 2019/11/09 19:37:58 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *str, char c)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str && (*str == c))
			str++;
		if (*str && *str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static char		*ft_fill_the_matrix(char const *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(word = malloc(i + 1)))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char			**ft_split(char const *str, char c)
{
	int		words;
	char	**matrix;
	int		i;

	if (!str)
		return (NULL);
	words = ft_count_words(str, c);
	if (!(matrix = malloc((words + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && (*str == c))
			str++;
		if (*str && *str != c)
		{
			matrix[i] = ft_fill_the_matrix(str, c);
			i++;
			while (*str && *str != c)
				str++;
		}
	}
	matrix[i] = NULL;
	return (matrix);
}
