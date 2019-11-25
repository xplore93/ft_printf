/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 00:47:38 by estina            #+#    #+#             */
/*   Updated: 2019/11/25 00:53:49 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_n(char **str, va_list ap, int *size)
{
	int		*var;

	var = va_arg(ap, int*);
	if (!var)
		return ;
	*var = *size;
	ft_putstr_fd(" ", 1);
	(*size)++;
	(*str)++;
}
