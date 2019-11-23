/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 01:49:53 by estina            #+#    #+#             */
/*   Updated: 2019/11/22 08:32:13 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	chage_flag(int num, t_flags *flags)
{
	num *= -1;
	flags->flag_zero = 0;
	flags->flag_minus = 1;
	flags->spaces_zeros = num;
}

void		flag_zero_handle(va_list ap, char **str, t_flags *flags)
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
	flags->spaces_zeros = num;
	if (num < 0)
		chage_flag(num, flags);
	(*str)++;
}
