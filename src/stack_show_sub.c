/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_show_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 14:04:46 by sjang             #+#    #+#             */
/*   Updated: 2016/12/30 14:04:48 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static int	get_positional_int_sw(int nb)
{
	int positional;
	int temp;

	positional = 1;
	temp = nb;
	while (temp >= 10 || temp <= -10)
	{
		temp /= 10;
		positional *= 10;
	}
	return (positional);
}

int			ft_putnbr_sw(int nb)
{
	char	digit;
	int		positional;
	int		ret;

	positional = get_positional_int_sw(nb);
	ret = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		positional *= -1;
		ret++;
	}
	while (positional != 0)
	{
		digit = nb / positional + '0';
		write(1, &digit, 1);
		nb %= positional;
		positional /= 10;
		ret++;
	}
	return (ret);
}

void		ft_putstr_wd(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 3);
		i += 3;
	}
}
