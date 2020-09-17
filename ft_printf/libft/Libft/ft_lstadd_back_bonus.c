/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:55:10 by estina            #+#    #+#             */
/*   Updated: 2019/11/09 20:54:08 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*aux;

	if (!alst)
		return ;
	aux = *alst;
	if (!*alst)
	{
		*alst = new;
	}
	else
	{
		aux = ft_lstlast(*alst);
		aux->next = new;
	}
}
