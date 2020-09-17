/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:08:19 by estina            #+#    #+#             */
/*   Updated: 2019/11/10 14:17:45 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_aux;
	t_list	*aux;

	if (!l && !del)
		return (NULL);
	aux = l;
	if (!(new = ft_lstnew(f(aux->content))))
		return (NULL);
	aux = aux->next;
	while (aux)
	{
		if (!(new_aux = ft_lstnew(f(aux->content))))
			return (NULL);
		ft_lstadd_back(&new, new_aux);
		aux = aux->next;
	}
	return (new);
}
