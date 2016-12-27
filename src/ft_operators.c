/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 09:25:19 by sjang             #+#    #+#             */
/*   Updated: 2016/12/21 09:25:20 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

//111

static void		ft_memcheck_operators(t_operators *op)
{
	if (op->idx >= op->size - 2)
	{
		op->operators =
		(t_sw_operator*)ft_realloc(op->operators, op->size * sizeof(t_sw_operator),
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

t_operators		*ft_operators_new(size_t size)
{
	t_operators	*ret;

	ret = (t_operators*)malloc(sizeof(t_operators));
	ret->operators = (t_sw_operator*)malloc(sizeof(t_sw_operator) * size);
	ret->size = size;
	ret->idx = 0;
	return (ret);
}

void			ft_destroy_operators(t_operators **op)
{
	free((*op)->operators);
	free(*op);
	*op = NULL;
}

//222

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

void			ft_op_store_do_show_ch(t_operators *op, t_sw_operator operator,
								t_stack *a, t_stack *b)
{
	ft_store_operator(op, operator);
	sw_operate(a, b, operator);
	ft_stack_display_cos(a, b);
}

int				ft_display_operators(t_operators *op)
{
	size_t i;

	i = 0;
	while (i < op->idx)
	{
		if ((op->operators)[i] == SA)
			ft_putstr("sa");
		else if ((op->operators)[i] == SB)
			ft_putstr("sb");
		else if ((op->operators)[i] == SS)
			ft_putstr("ss");
		else if ((op->operators)[i] == PA)
			ft_putstr("pa");
		else if ((op->operators)[i] == PB)
			ft_putstr("pb");
		else if ((op->operators)[i] == RA)
			ft_putstr("ra");
		else if ((op->operators)[i] == RB)
			ft_putstr("rb");
		else if ((op->operators)[i] == RR)
			ft_putstr("rr");
		else if ((op->operators)[i] == RRA)
			ft_putstr("rra");
		else if ((op->operators)[i] == RRB)
			ft_putstr("rrb");
		else if ((op->operators)[i] == RRR)
			ft_putstr("rrr");
		ft_putstr("\n");
		i++;
	}
	return (i);
}

void			ft_show_operator(t_sw_operator oper)
{
	if (oper == SA)
		ft_putstr("sa");
	else if (oper == SB)
		ft_putstr("sb");
	else if (oper == SS)
		ft_putstr("ss");
	else if (oper == PA)
		ft_putstr("pa");
	else if (oper == PB)
		ft_putstr("pb");
	else if (oper == RA)
		ft_putstr("ra");
	else if (oper == RB)
		ft_putstr("rb");
	else if (oper == RR)
		ft_putstr("rr");
	else if (oper == RRA)
		ft_putstr("rra");
	else if (oper == RRB)
		ft_putstr("rrb");
	else if (oper == RRR)
		ft_putstr("rrr");
	ft_putstr("\n");
}