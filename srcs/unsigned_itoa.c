/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:10:07 by estina            #+#    #+#             */
/*   Updated: 2019/11/28 05:52:03 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*unsigned_itoa(unsigned long int n)
{
	char					*number;
	int						num_digits;
	unsigned long int		aux;

	aux = n;
	num_digits = 1;
	while (aux >= 10)
	{
		num_digits++;
		aux /= 10;
	}
	if (!(number = malloc(num_digits + 1)))
		return (NULL);
	number[num_digits] = 0;
	while (n >= 10)
	{
		num_digits--;
		number[num_digits] = 48 + n % 10;
		n /= 10;
	}
	number[--num_digits] = 48 + n % 10;
	return (number);
}

static char		*unsigned_int_itoa(unsigned int n)
{
	char					*number;
	int						num_digits;
	unsigned long int		aux;

	aux = n;
	num_digits = 1;
	while (aux >= 10)
	{
		num_digits++;
		aux /= 10;
	}
	if (!(number = malloc(num_digits + 1)))
		return (NULL);
	number[num_digits] = 0;
	while (n >= 10)
	{
		num_digits--;
		number[num_digits] = 48 + n % 10;
		n /= 10;
	}
	number[--num_digits] = 48 + n % 10;
	return (number);
}

void			handle_unsigned(va_list ap, int *size, t_flags *flags)
{
	char					*aux;

	if (!flags->flag_ll && !flags->flag_hh)
		aux = unsigned_int_itoa(va_arg(ap, unsigned int));
	else if (flags->flag_ll == 1)
		aux = unsigned_itoa(va_arg(ap, unsigned long int));
	else if (flags->flag_ll == 2)
		aux = unsigned_long_itoa(va_arg(ap, unsigned long long int));
	else if (flags->flag_hh == 2)
		aux = unsigned_int_itoa(va_arg(ap, unsigned int));
	else
		aux = unsigned_int_itoa(va_arg(ap, unsigned int));
	handle(size, flags, aux);
}
