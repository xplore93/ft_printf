/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:23:56 by estina            #+#    #+#             */
/*   Updated: 2019/11/10 13:37:25 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_count_initial(char const *s1, char const *set)
{
	int		found;
	int		i;
	int		j;

	found = 1;
	i = 0;
	while (s1[i] && found)
	{
		j = 0;
		while (set[j] && s1[i] && found)
		{
			if (set[j] == s1[i])
				found = 0;
			j++;
		}
		if (!found)
			found = 1;
		else
			found = 0;
		i++;
	}
	return (i - 1);
}

static int		ft_count_final(char const *s1, char const *set)
{
	int		found;
	int		i;
	int		j;

	found = 1;
	i = ft_strlen(s1) - 1;
	while (i >= 0 && s1[i] && found)
	{
		j = 0;
		while (set[j] && found)
		{
			if (set[j] == s1[i])
				found = 0;
			j++;
		}
		if (!found)
			found = 1;
		else
			found = 0;
		i--;
	}
	return (i + 1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		first;
	int		last;
	int		i;

	if (!s1)
		return (NULL);
	first = ft_count_initial(s1, set);
	last = ft_count_final(s1, set);
	if (!last)
	{
		str = malloc(1);
		str[0] = 0;
		return (str);
	}
	if (!(str = malloc(last - first + 2)))
		return (NULL);
	i = 0;
	while (first++ <= last)
	{
		str[i] = s1[first - 1];
		i++;
	}
	str[i] = 0;
	return (str);
}
