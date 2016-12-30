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

void			ft_op_store_do(t_operators *op, t_sw_operator operator,
								t_stack *a, t_stack *b)
{
	ft_store_operator(op, operator);
	sw_operate(a, b, operator);
}

void			ft_op_store_do_show(t_operators *op, t_sw_operator operator,
								t_stack *a, t_stack *b)
{
	ft_store_operator(op, operator);
	sw_operate(a, b, operator);
	ft_show_operator(operator);
	ft_stack_display_cos(a, b);
}
