/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:55:42 by estina            #+#    #+#             */
/*   Updated: 2019/11/09 18:50:58 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_sum_digits(long int *num, int *num_digits)
{
	while (*num >= 10)
	{
		(*num_digits)++;
		*num /= 10;
	}
}

static char	*ft_malloc_number(int n, int *num_digits)
{
	char		*number;
	long int	num;

	if (n == 0)
	{
		if (!(number = malloc(2)))
			return (NULL);
		number[0] = '0';
		number[1] = 0;
		return (number);
	}
	*num_digits = 1;
	num = n;
	if (num < 0)
	{
		num *= -1;
		(*num_digits)++;
	}
	ft_sum_digits(&num, num_digits);
	if (!(number = malloc(*num_digits + 1)))
		return (NULL);
	number[*num_digits] = 0;
	return (number);
}

char		*ft_itoa(int n)
{
	char		*number;
	int			num_digits;
	long int	num;

	number = NULL;
	if (!(number = ft_malloc_number(n, &num_digits)))
		return (NULL);
	num = n;
	if (num < 0)
	{
		num *= -1;
		number[0] = '-';
	}
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
