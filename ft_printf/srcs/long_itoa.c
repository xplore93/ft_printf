/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 00:57:47 by estina            #+#    #+#             */
/*   Updated: 2019/11/28 05:26:12 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_sum_digits(unsigned long int *num, int *num_digits)
{
	while (*num >= 10)
	{
		(*num_digits)++;
		*num /= 10;
	}
}

static char	*ft_malloc_number(long int n, int *num_digits)
{
	char					*number;
	unsigned long int		num;

	if (n == 0)
	{
		if (!(number = malloc(2)))
			return (NULL);
		number[0] = '0';
		number[1] = 0;
		return (number);
	}
	*num_digits = 1;
	if (n < 0)
	{
		num = -n;
		(*num_digits)++;
	}
	else
		num = n;
	ft_sum_digits(&num, num_digits);
	if (!(number = malloc(*num_digits + 1)))
		return (NULL);
	number[*num_digits] = 0;
	return (number);
}

char		*long_itoa(long int n)
{
	char					*number;
	int						num_digits;
	unsigned long int		num;

	number = NULL;
	if (!(number = ft_malloc_number(n, &num_digits)))
		return (NULL);
	if (n < 0)
	{
		num = -n;
		number[0] = '-';
	}
	else
		num = n;
	while (num >= 10)
	{
		num_digits--;
		number[num_digits] = 48 + num % 10;
		num /= 10;
	}
	if (num_digits)
		num_digits--;
	number[num_digits] = 48 + num % 10;
	return (number);
}
