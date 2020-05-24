/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 03:36:32 by estina            #+#    #+#             */
/*   Updated: 2019/11/26 06:54:26 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	negative(float *f, char **str, int *pos, int *len)
{
	int		value;

	value = (int)*f;
	if (f < 0)
	{
		*f *= -1;
		value *= -1;
		if (value == 0)
		{
			*str[0] = '-';
			(*pos)++;
			(*len)++;
		}
	}
	return (value);
}

static void	float_to_string(char *str, float f, char size, int len)
{
	int		pos;
	char	*curr;
	int		value;

	pos = 0;
	value = negative(&f, &str, &pos, &len);
	curr = ft_itoa(value);
	while (*curr)
	{
		str[pos] = *curr;
		curr++;
		pos++;
	}
	len += size + 1;
	str[pos++] = '.';
	while (pos < len)
	{
		f = f - (float)value;
		f *= 10;
		value = (int)f;
		curr = ft_itoa(value);
		str[pos++] = *curr;
	}
	str[pos] = 0;
}

static void	len_value(int *len, int num)
{
	*len = 1;
	while (num >= 10)
	{
		num /= 10;
		(*len)++;
	}
}

void		handle_float(int *size, t_flags *flags, va_list ap)
{
	double	num;
	char	*str;
	int		len;

	num = va_arg(ap, double);
	len_value(&len, (int)num);
	if (flags->flag_point)
	{
		str = malloc(len + flags->width_precision + 2);
		float_to_string(str, num, flags->width_precision, len);
	}
	else
	{
		str = malloc(len + 6 + 2);
		float_to_string(str, num, 6, len);
	}
	ft_putstr_fd(str, 1);
	*size += ft_strlen(str);
	free(str);
}
