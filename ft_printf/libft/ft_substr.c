/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:06:37 by estina            #+#    #+#             */
/*   Updated: 2019/11/09 20:37:50 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen(s) < start)
	{
		if (!(dst = malloc(len + 10)))
			return (NULL);
		while (i++ < len)
			dst[i - 1] = 0;
	}
	else
	{
		if (!(dst = malloc(len + 1)))
			return (NULL);
	}
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
