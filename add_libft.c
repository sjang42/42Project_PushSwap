/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 03:08:26 by sjang             #+#    #+#             */
/*   Updated: 2016/11/26 03:08:26 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			ft_isint(long long n)
{
	if (n >= -2147483648 && n <= 2147483647)
		return (1);
	else
		return (0);
}

int			ft_isonly_digit(const char *str)
{
	int i;

	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_digitcount(int nb)
{
	int			count;
	long long	n;

	n = (long long)nb;
	count = 1;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	ft_putstr_wd(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 3);
		i += 3;
	}
}
