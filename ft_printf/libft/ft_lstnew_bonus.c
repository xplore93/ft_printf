/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:22:39 by estina            #+#    #+#             */
/*   Updated: 2019/11/09 19:40:58 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*element;

	if (!(element = malloc(sizeof(t_list))))
		return (NULL);
	element->content = (void*)content;
	element->next = NULL;
	return (element);
}
