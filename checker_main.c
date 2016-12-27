/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 03:56:44 by sjang             #+#    #+#             */
/*   Updated: 2016/11/26 03:56:45 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//지워야함

#include "../include/main.h"
#include <stdio.h>

// int main(int argc, char *argv[])
// {
// 	t_stack		*a;
// 	t_stack		*b;
// 	t_operators *op;

// 	b = ft_stack_new();

// 	a = ft_get_stack_a(argc, argv);
// 	op = ft_operators_new(100);

// 	// sw_solve_quick(a, b, op, 1, ft_stack_size(a));
// 	// // sw_solve_send(a, b, op);
// 	// ft_display_operators(op);

// 	op = ft_get_operators(a, b, 1);

// 	ft_check_stack(a, b);
// 	ft_stack_destroy(&a);
// 	ft_stack_destroy(&b);
// 	ft_destroy_operators(&op);
// 	return (0);
// }

t_swoptions ft_get_swoption(char *str)
{
	if (!ft_strcmp("-s", str))
		return (CHECKER_SHOW_OP);
	return (NOTHING);
}

void		ft_show_usage(void)
{
	ft_putstr("Usage	: ./checker [-option] num1 num2 num3 ...\n");
	ft_putstr("Option	: -s\n");
}

int main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	t_operators *op;
	t_swoptions	option;

	if (argc < 2)
	{
		ft_show_usage();
		return (0);
	}
	option = ft_get_swoption(argv[1]);
	a = ft_get_stack_a(argc, argv, option);
	b = ft_stack_new();

	op = ft_get_operators(a, b, 0);
	ft_check_stack(a, b);
	ft_stack_destroy(&a);
	ft_stack_destroy(&b);
	ft_destroy_operators(&op);
	return (0);
}


