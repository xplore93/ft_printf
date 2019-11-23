/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:10:07 by estina            #+#    #+#             */
/*   Updated: 2019/11/22 02:16:10 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*unsigned_itoa(unsigned int n)
{
	char			*number;
	int				num_digits;
	unsigned int	aux;

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
