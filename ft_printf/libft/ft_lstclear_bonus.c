/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:01:32 by estina            #+#    #+#             */
/*   Updated: 2019/11/09 13:04:50 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	while ((*lst)->next)
	{
		aux = (*lst);
		*lst = (*lst)->next;
		ft_lstdelone(aux, del);
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
