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

	if (argc < 2)
		return (0);
	option = ft_get_swoption(argv[1]);
	if (option != NOTHING && argc == 2)
		return (0);
	sts = ft_stsnew(option);

	ft_get_stack_a(argc, argv, sts);
	if (ft_check_stack(sts->a, sts->b))
	{
		ft_destroy_sts(sts);
		return (0);
	}
	solve_quick_atob(sts, ft_stack_size(sts->a));
	ft_display_operators(sts->op);
	ft_destroy_sts(sts);
	return (0);
}
