/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_store.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 14:30:02 by sjang             #+#    #+#             */
/*   Updated: 2016/12/30 14:30:02 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void		ft_memcheck_operators(t_operators *op)
{
	if (op->idx >= op->size - 2)
	{
		op->operators =
		(t_sw_operator*)ft_realloc(
		op->operators,
		op->size * sizeof(t_sw_operator),
		(op->size + 100) * sizeof(t_sw_operator));
		op->size += 100;
	}
}

void			ft_store_operator(t_operators *op, t_sw_operator operator)
{
	ft_memcheck_operators(op);
	(op->operators)[op->idx] = operator;
	(op->idx)++;
}

void			ft_op_store_do(t_swstacks *sts, t_sw_operator operator)
{
	ft_store_operator(sts->op, operator);
	sw_operate(sts->a, sts->b, operator);
}

void			change_color(int n)
{
	static int num = 0;

	if (!n)
	{
		write(1, "\033[0;m", 6);
		return ;
	}
	if (num == 6)
		num = 0;
	if (num == 0)
		write(1, "\033[31;m", 6);
	if (num == 1)
		write(1, "\033[32;m", 6);
	if (num == 2)
		write(1, "\033[33;m", 6);
	if (num == 3)
		write(1, "\033[34;m", 6);
	if (num == 4)
		write(1, "\033[35;m", 6);
	if (num == 5)
		write(1, "\033[36;m", 6);
	num++;
}

void			ft_op_store_do_show(t_swstacks *sts, t_sw_operator operator)
{
	if (sts->option & OP_COLOR)
		change_color(1);
	ft_store_operator(sts->op, operator);
	sw_operate(sts->a, sts->b, operator);
	ft_show_operator(operator);
	ft_stack_display_cos(sts->a, sts->b);
	if (sts->option & OP_COLOR)
		change_color(0);
}
