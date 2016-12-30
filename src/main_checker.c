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
	t_swstacks		*sts;
	t_swoptions		option;

	if (argc < 2)
		return (0);
	option = ft_get_swoption(argv[1]);
	if (option != NOTHING && argc == 2)
	{
		ft_show_usage();
		return (0);
	}
	sts = ft_stsnew(option);
	ft_get_stack_a(argc, argv, sts);

	ft_get_operators(sts, option);

	if (ft_check_stack(sts->a, sts->b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");

	if (option & OP_SIZE_OPER)
	{
		ft_putstr("Size of Instruction : ");
		ft_putnbr(sts->op->idx);
		ft_putstr("\n");
	}
	ft_destroy_sts(sts);
	return (0);
}
