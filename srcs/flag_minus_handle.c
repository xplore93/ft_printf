/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_minus_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 01:45:43 by estina            #+#    #+#             */
/*   Updated: 2019/11/22 10:35:03 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_minus_handle(va_list ap, char **str, t_flags *flags)
{
	int		num;
	int		aux;
	int		size;

	if (**str == '*')
		num = va_arg(ap, int);
	else if (ft_isdigit(**str))
	{
		num = ft_atoi(*str);
		aux = num;
		size = 0;
		while (aux >= 10)
		{
			aux /= 10;
			size++;
		}
		*str += size;
	}
	else
		num = 0;
	if (num < 0)
		num *= -1;
	flags->spaces_zeros = num;
	(*str)++;
}
