/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:00:01 by estina            #+#    #+#             */
/*   Updated: 2019/11/09 18:34:26 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		count;

	count = 0;
	while (s1[count])
		count++;
	if (!(s2 = malloc(count + 1)))
		return (NULL);
	while (count >= 0)
	{
		s2[count] = s1[count];
		count--;
	}
	return (s2);
}
