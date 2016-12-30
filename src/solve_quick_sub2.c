/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quick_sub2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 16:10:40 by sjang             #+#    #+#             */
/*   Updated: 2016/12/29 16:10:41 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static int		ra_or_not(t_swstacks *sts, t_quick_tool *tool)
{
	if (ft_stack_peek(sts->a) > tool->ram ||
		tool->count_ra >= tool->future_rb ||
		ft_stack_size(sts->b) == tool->length - tool->count_pa)
		return (0);
	else
		return (1);
}

int				ft_rpa(t_swstacks *sts,	t_quick_tool *tool)
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

int				rb_or_rr(t_swstacks *sts, t_quick_tool *tool)
{
	if (ft_stack_peek(sts->a) < tool->ram &&
		tool->count_ra < tool->future_rb &&
		ft_stack_size(sts->b) != tool->length - tool->count_pa)
		return (RR);
	else
		return (RB);
}
