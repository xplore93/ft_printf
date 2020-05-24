/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:41:39 by estina            #+#    #+#             */
/*   Updated: 2019/11/09 20:54:54 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list		*aux;
	int			i;

	aux = lst;
	i = 0;
	if (aux)
		i++;
	else
		return (0);
	while (aux->next)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}
