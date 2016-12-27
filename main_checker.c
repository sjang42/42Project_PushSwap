/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 10:39:04 by sjang             #+#    #+#             */
/*   Updated: 2016/12/22 10:39:06 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;
	t_operators		*op;
	t_swoptions		option;

	if (argc < 2)
	{
		ft_show_usage();
		return (0);
	}
	option = ft_get_swoption(argv[1]);
	a = ft_get_stack_a(argc, argv, option);
	b = ft_stack_new();
	op = ft_get_operators(a, b, option);

	ft_check_stack(a, b);

	ft_stack_destroy(&a);
	ft_stack_destroy(&b);
	ft_destroy_operators(&op);
	return (0);
}
