/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 00:43:48 by sjang             #+#    #+#             */
/*   Updated: 2016/11/26 00:43:49 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap_base.h"
#include "../include/main.h"

static int		sw_operate_rr(t_stack *a, t_stack *b, t_sw_operator op)
{
	if (op == RA)
		return (sw_rotate(a));
	else if (op == RB)
		return (sw_rotate(b));
	else if (op == RR)
	{
		sw_rotate(a);
		return (sw_rotate(b));
	}
	else if (op == RRA)
		return (sw_rotate_rev(a));
	else if (op == RRB)
		return (sw_rotate_rev(b));
	else if (op == RRR)
	{
		sw_rotate_rev(a);
		return (sw_rotate_rev(b));
	}
	return (-1);
}

static int		sw_operate_sp(t_stack *a, t_stack *b, t_sw_operator op)
{
	if (op == SA)
		return (sw_swap(a));
	else if (op == SB)
		return (sw_swap(b));
	else if (op == SS)
	{
		sw_swap(a);
		return(sw_swap(b));
	}
	else if (op == PA)
		return (sw_push(b, a));
	else if (op == PB)
		return (sw_push(a, b));
	else
		return (-1);
}

int				sw_operate(t_stack *a, t_stack *b, t_sw_operator op)
{
	if (op == SA || op == SB || op == SS || op == PA || op == PB)
		return (sw_operate_sp(a, b, op));
	else if (op == RA || op == RB || op == RR ||
				op == RRA || op == RRB || op == RRR)
		return (sw_operate_rr(a, b, op));
	return (-1);
}

void			ft_calculate(t_stack *a, t_stack *b, t_operators *op)
{
	size_t i;

	i = 0;
	while (i < op->idx)
	{
		sw_operate(a, b, (op->operators)[i]);
		i++;
	}
}

void			ft_calculate_show(t_stack *a, t_stack *b, t_operators *op)
{
	size_t i;

	i = 0;
	ft_stack_display_cos(a, b);
	while (i < op->idx)
	{
		sw_operate(a, b, (op->operators)[i]);
		ft_show_operator((op->operators)[i]);
		ft_stack_display_cos(a, b);
		i++;
	}
}

void			ft_calculate_from(t_stack *a, t_stack *b,
									t_operators *op, size_t from)
{
	size_t i;

	i = from;
	while (i < op->idx)
	{
		sw_operate(a, b, (op->operators)[i]);
		i++;
	}
}
