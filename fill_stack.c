/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 02:45:40 by sjang             #+#    #+#             */
/*   Updated: 2016/11/26 02:45:40 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

t_stack		*ft_get_stack_a(int argc, char *argv[], t_swoptions	option)
{
	int			i;
	long long	n;
	t_stack		*a;

	a = ft_stack_new();
	
	i = argc - 1;
	while (i > (option != 0))
	{
		n = ft_atoll(argv[i]);
		if (!ft_isonly_digit(argv[i]) || !ft_isint(n))
			ft_exit_error("One or more input is not an int");
		if (ft_stack_where_data(a, n))
			ft_exit_error("One number used twice or more");
		ft_stack_push(a, (int)n);
		i--;
	}
	return (a);
}
