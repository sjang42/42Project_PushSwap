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

#include "main.h"
#include "stdio.h"

int main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	t_operators *op;
	int arr[] = {100, 90, -1, 200};

	a = ft_stack_new();
	b = ft_stack_new();

	a = ft_get_stack_a(argc, argv);
	op = ft_operators_new(100);

	sw_solve_quick(a, b, op, 1, ft_stack_size(a));
	// sw_solve_send(a, b, op);
	ft_display_operators(op);

	// op = ft_get_operators_cos(a, b);
	// ft_calculate(a, b, op);
	
	ft_check_stack(a, b);
	ft_stack_destroy(&a);
	ft_stack_destroy(&b);
	ft_destroy_operators(&op);
	return (0);
}
