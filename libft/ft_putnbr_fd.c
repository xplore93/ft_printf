/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:57:59 by estina            #+#    #+#             */
/*   Updated: 2019/11/09 19:56:35 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int nb_hulk;

	nb_hulk = n;
	if (nb_hulk < 0)
	{
		nb_hulk = -nb_hulk;
		ft_putchar_fd('-', fd);
	}
	if (nb_hulk >= 10)
		ft_putnbr_fd(nb_hulk / 10, fd);
	ft_putchar_fd(48 + nb_hulk % 10, fd);
}
