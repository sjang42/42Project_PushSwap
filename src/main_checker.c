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

void			check_answer(t_swstacks *sts)
{
	if (ft_check_stack(sts->a, sts->b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

t_swoptions		get_option(int argc, char *argv[])
{
	t_swoptions	ret;

	ret = ft_get_swoption(argv[1]);
	if (ret != NOTHING && argc == 2)
	{
		ft_show_usage();
		ft_exit_error(NULL);
	}
	return (ret);
}

int				main(int argc, char *argv[])
{
	t_swstacks		*sts;
	t_swoptions		option;

	if (argc < 2)
		return (0);
	option = get_option(argc, argv);
	sts = ft_stsnew(option);
	ft_get_stack_a(argc, argv, sts);
	ft_get_operators(sts, option);
	check_answer(sts);
	if (option & OP_SIZE_OPER)
	{
		ft_putstr("Size of Instruction : ");
		ft_putnbr(sts->op->idx);
		ft_putstr("\n");
	}
	ft_destroy_sts(sts);
	return (0);
}
