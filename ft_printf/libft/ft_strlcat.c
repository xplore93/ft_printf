/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:30:32 by estina            #+#    #+#             */
/*   Updated: 2019/11/06 16:05:33 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	len;
	size_t	i;
	size_t	j;

	dst_len = ft_strlen(dst);
	if (dstsize < dst_len)
		dst_len = dstsize;
	len = dstsize - dst_len;
	if (!len)
	{
		return (dst_len + ft_strlen(src));
	}
	i = 0;
	j = dst_len;
	while (src[i] && j + 1 < dstsize)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = 0;
	return (dst_len + ft_strlen(src));
}
