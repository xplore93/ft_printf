/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:12:25 by estina            #+#    #+#             */
/*   Updated: 2019/11/22 05:29:22 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	transform(unsigned long n, unsigned long b_l, char *bs, char **s)
{
	unsigned long	aux;
	int				len;

	aux = n;
	len = 0;
	while (aux >= b_l)
	{
		len++;
		aux /= b_l;
	}
	while (n >= b_l)
	{
		(*s)[len] = bs[n % b_l];
		len--;
		n /= b_l;
	}
	(*s)[len] = bs[n % b_l];
}

char		*hex_itoa(unsigned long nbr, int upper)
{
	unsigned long	base_len;
	char			*base;
	int				hex_len;
	char			*str;
	unsigned long	aux;

	hex_len = 1;
	base_len = 16;
	if (upper)
		base = ft_strdup("0123456789ABCDEF");
	else
		base = ft_strdup("0123456789abcdef");
	aux = nbr;
	while (aux >= base_len)
	{
		hex_len++;
		aux /= base_len;
	}
	if (!(str = malloc(hex_len + 1)))
		return (NULL);
	transform(nbr, base_len, base, &str);
	free(base);
	return (str);
}
