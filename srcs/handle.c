/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 00:11:06 by estina            #+#    #+#             */
/*   Updated: 2019/11/23 21:54:47 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flag_zero(int *size, t_flags *flags, char **str)
{
	if (**str == '-' || **str == '+')
	{
		ft_putchar_fd(**str, 1);
		(*size)++;
		(*str)++;
		flags->spaces_zeros--;
	}
	flags->spaces_zeros -= ft_strlen(*str);
	while (flags->spaces_zeros-- > 0)
	{
		ft_putchar_fd('0', 1);
		(*size)++;
	}
}

static int	flag_minus_none(int *size, t_flags *flags, char **str)
{
	int		i;

	i = 0;
	flags->spaces_zeros -= ft_strlen(*str);
	if (**str == '+' && flags->flag_point && !flags->width_precision)
	{
		i = 1;
		flags->spaces_zeros++;
	}
	while (flags->spaces_zeros-- > 0)
	{
		ft_putchar_fd(' ', 1);
		(*size)++;
	}
	return (i);
}

static int	spaces_zeros(int *size, t_flags *flags, char **str)
{
	size_t	len;
	int		i;

	i = 0;
	if (flags->flag_point && !flags->width_precision)
		i = 1;
	len = ft_strlen(*str);
	if (**str == '-' || **str == '+')
		flags->spaces_zeros--;
	if ((flags->spaces_zeros - len) > (flags->width_precision - len))
		if (!flags->flag_minus && !flags->flag_zero)
		{
			if (flags->width_precision <= (int)len)
				flags->width_precision = 0;
			while (flags->spaces_zeros-- > flags->width_precision)
			{
				ft_putchar_fd(' ', 1);
				(*size)++;
			}
		}
	return (i);
}

static int	flag_point(int *size, t_flags *flags, char **str)
{
	int		i;

	i = spaces_zeros(size, flags, str);
	flags->width_precision -= ft_strlen(*str);
	if (**str == '-' || **str == '+')
		flags->width_precision++;
	if ((**str == '-' || **str == '+') && flags->width_precision > 0)
	{
		ft_putchar_fd(**str, 1);
		(*size)++;
		(*str)++;
	}
	while (flags->width_precision-- > 0)
	{
		ft_putchar_fd('0', 1);
		(*size)++;
		flags->spaces_zeros--;
	}
	return (i);
}

int			handle(int *size, t_flags *flags, char *str)
{
	int		i;
	char	c;

	i = 0;
	if (!str)
		return (0);
	c = *str;
	if (flags->flag_point && flags->width_precision > (int)ft_strlen(str))
		i = flag_point(size, flags, &str);
	//else if (flags->flag_point && flags->width_precision < (int)ft_strlen(str))
	//	i = 1;
	if (flags->flag_zero)
		flag_zero(size, flags, &str);
	if (flags->spaces_zeros && !flags->flag_minus)
		i = flag_minus_none(size, flags, &str);
	if (!i)
		ft_putstr_fd(str, 1);
	else if (c == '+' || c == '-')
		ft_putchar_fd(c, 1);
	*size += ft_strlen(str);
	if (flags->flag_minus)
		flag_minus_none(size, flags, &str);
	return (1);
}
