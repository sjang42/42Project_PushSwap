/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 10:41:09 by sjang             #+#    #+#             */
/*   Updated: 2016/12/22 10:41:10 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int main(int argc, char *argv[])
{
	t_swstacks		*sts;
	t_swoptions		option;

	sts = (t_swstacks*)malloc(sizeof(t_swstacks));
	if (argc < 2)
	{
		ft_show_usage_ps();
		return (0);
	}
	option = ft_get_swoption(argv[1]);
	if (option != NOTHING && argc == 2)
	{
		ft_show_usage_ps();
		return (0);
	}
	sts->a = ft_get_stack_a(argc, argv, option);
	sts->b = ft_stack_new();
	sts->op = ft_operators_new(100);

	solve_quick_atob(sts, ft_stack_size(sts->a));
	ft_display_operators(sts->op);
	
	ft_stack_destroy(&sts->a);
	ft_stack_destroy(&sts->b);
	ft_destroy_operators(&sts->op);
	return (0);
}
