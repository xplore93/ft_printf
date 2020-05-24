/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:40:04 by estina            #+#    #+#             */
/*   Updated: 2019/11/09 18:31:43 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	mem;

	if (size == 0)
		mem = count;
	else
		mem = count * size;
	if (!(p = malloc(mem)))
		return (NULL);
	return (ft_memset(p, 0, mem));
}
