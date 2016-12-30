/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:44:59 by sjang             #+#    #+#             */
/*   Updated: 2016/12/27 16:45:00 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int					ft_future_ra(t_swstacks *sts, int length)
{
	int				count_ra;
	int				count_pb;
	int				pivot;
	t_stack_node	*cur;

	if(ft_stack_isempty(sts->b))
		return (0);
	pivot = ft_get_pivot(sts->a, length);
	count_ra = 0;
	count_pb = 0;
	cur = sts->a->head;
	while (cur->next && (count_pb < length / 2))
	{
		if (cur->data < pivot)
			count_pb++;
		else
			count_ra++;
		cur = cur->next;
	}
	return (count_ra);
}


t_quick_tool		*ft_tool_new_a(t_swstacks *sts, int length)
{
	t_quick_tool *tool;

	tool = (t_quick_tool *)malloc(sizeof(t_quick_tool));
	tool->count_pa = 0;
	tool->count_pb = 0;
	tool->count_ra = 0;
	tool->count_rb = 0;
	tool->future_ra = ft_future_ra(sts, length);
	tool->pivot = ft_get_pivot(sts->a, length);
	tool->rbm = ft_get_rbm(sts->a, length);
	tool->length = length;
	return (tool);
}

void				solve_quick_atob(t_swstacks *sts, int length)
{
	t_quick_tool *tool;
	int i;

	if (length <= 3)
	{
		under3_a(sts, length);
		return ;
	}
	tool = ft_tool_new_a(sts, length);
	i = 0;

	while (i < length && (tool->count_pb < length / 2))
	{
		if (ft_stack_peek(sts->a) < tool->pivot)
		{
			tool->count_rb += ft_rpb(sts, tool);
			(tool->count_pb)++;
		}
		else
		{
			// ft_op_store_do(sts->op, ra_or_rr(sts, tool), sts->a, sts->b);
			if (ra_or_rr(sts, tool) == RR)
			{
				ft_op_store_do(sts->op, RR,	sts->a, sts->b);
				(tool->count_rb)++;
			}
			else
				ft_op_store_do(sts->op, RA,	sts->a, sts->b);
			(tool->count_ra)++;
		}
	}
	while (tool->count_ra && ft_stack_size(sts->a) != length - tool->count_pb)
	{
		if (tool->count_rb > 0)
		{
			ft_op_store_do(sts->op, RRR, sts->a, sts->b);
			(tool->count_rb)--;
		}
		else
			ft_op_store_do(sts->op, RRA, sts->a, sts->b);
		(tool->count_ra)--;
	}

	while (tool->count_rb > 0 && ft_stack_size(sts->b) != tool->count_pb)
	{
		ft_op_store_do(sts->op, RRB, sts->a, sts->b);
		(tool->count_rb)--;
	}
	solve_quick_atob(sts, length - tool->count_pb);
	solve_quick_btoa(sts, tool->count_pb);
	free(tool);
}


