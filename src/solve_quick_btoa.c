/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quick_btoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 16:38:57 by sjang             #+#    #+#             */
/*   Updated: 2016/12/29 16:38:58 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static int			ft_future_rb(t_swstacks *sts, int length)
{
	int				count_rb;
	int				count_pa;
	int				pivot;
	t_stack_node	*cur;

	// if(ft_stack_isempty(sts->b))
	// 	return (0);
	pivot = ft_get_pivot(sts->b, length);
	count_rb = 0;
	count_pa = 0;
	cur = sts->b->head;
	while (cur->next && (count_pa < length / 2))
	{
		if (cur->data >= pivot)
			count_pa++;
		else
			count_rb++;
		cur = cur->next;
	}
	return (count_rb);
}

static t_quick_tool		*ft_tool_new_b(t_swstacks *sts, int length)
{
	t_quick_tool	*tool;

	tool = (t_quick_tool *)malloc(sizeof(t_quick_tool));
	tool->count_pa = 0;
	tool->count_rb = 0;
	tool->future_rb = ft_future_rb(sts, length);
	tool->pivot = ft_get_pivot(sts->b, length);
	tool->ram = ft_get_ram(sts->b, length);
	tool->length = length;
	return (tool);
}

void		solve_quick_btoa(t_swstacks *sts, int length)
{
	t_quick_tool	*tool;
	int				i;

	if (length <= 3)
	{
		under3_b(sts, length);
		return ;
	}
	tool = ft_tool_new_b(sts, length);
	i = 0;
	tool->count_pa = 0;
	tool->future_rb = ft_future_rb(sts, length);
	while (i < length && (tool->count_pa < ((length % 2 == 0) ?
							(length / 2) : (length / 2 + 1))))
	{
		if (ft_stack_peek(sts->b) >= tool->pivot)
		{
			ft_op_store_do(sts->op, PA, sts->a, sts->b);
			(tool->count_pa)++;
		}
		else
		{
			ft_op_store_do(sts->op, RB, sts->a, sts->b);
			(tool->count_rb)++;
		}
		i++;
	}
	while (tool->count_rb && ft_stack_size(sts->b) != length - tool->count_pa)
	{
		ft_op_store_do(sts->op, RRB, sts->a, sts->b);
		(tool->count_rb)--;
	}
	solve_quick_atob(sts, tool->count_pa);
	solve_quick_btoa(sts, length - tool->count_pa);
	free(tool);
}
