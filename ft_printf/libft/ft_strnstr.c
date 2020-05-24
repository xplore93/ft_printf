/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:53:47 by estina            #+#    #+#             */
/*   Updated: 2019/11/05 17:13:46 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str2[i])
		return ((char*)str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str2[j] && str[i + j] == str2[j] && (i + j) < len)
		{
			j++;
			if (str2[j] == '\0')
				return ((char*)&str[i]);
		}
		i++;
	}
	return (NULL);
}
