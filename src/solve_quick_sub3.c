/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quick_sub3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 14:53:10 by sjang             #+#    #+#             */
/*   Updated: 2016/12/30 14:53:11 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static int		rb_or_not_first(t_swstacks *sts, t_quick_tool *tool)
{
	if (ft_stack_size(sts->b) != tool->count_pb ||
		ft_stack_size(sts->b) <= 1 ||
		sts->b->head->next->data < tool->rbm ||
		ft_stack_peek(sts->b) >= tool->rbm)
		return (0);
	else
		return (1);
}

static int		rb_or_not(t_swstacks *sts, t_quick_tool *tool)
{
	if (ft_stack_size(sts->b) == tool->count_pb ||
		ft_stack_size(sts->b) <= 1 ||
		ft_stack_last(sts->b) > tool->rbm ||
		ft_stack_peek(sts->b) <= tool->rbm)
		return (0);
	else
		return (1);
}

int				ft_rpb(t_swstacks *sts, t_quick_tool *tool)
{
	int count;

	count = 0;
	if (ft_stack_size(sts->b) == tool->count_pb)
		count += rb_or_not_first(sts, tool);
	else if (tool->count_rb < tool->future_ra)
		count += rb_or_not(sts, tool);
	if (count)
		ft_op_store_do(sts->op, RB, sts->a, sts->b);
	ft_op_store_do(sts->op, PB, sts->a, sts->b);
	return (count);
}

static int		ra_or_not(t_swstacks *sts, t_quick_tool *tool)
{
	if (ft_stack_peek(sts->a) > tool->ram ||
		tool->count_ra >= tool->future_rb ||
		ft_stack_size(sts->b) == tool->length - tool->count_pa)
		return (0);
	else
		return (1);
}

int				ft_rpa(t_swstacks *sts, t_quick_tool *tool)
{
	int count;
	int i;

	i = sts->b->head->data;
	i = tool->ram;
	count = 0;
	count += ra_or_not(sts, tool);
	if (count)
		ft_op_store_do(sts->op, RA, sts->a, sts->b);
	ft_op_store_do(sts->op, PA, sts->a, sts->b);
	return (count);
}
