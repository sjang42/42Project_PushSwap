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

void		solve_quick_atob(t_swstacks *sts, int length)
{
	int count_pb;
	int count_ra;
	int rbm;
	int pivot;
	int i;

	count_pb = 0;
	count_ra = 0;
	if (length <= 3)
	{
		under3_a(sts, length);
		return ;
	}
	pivot = ft_get_pivot(sts->a, length);
	rbm = ft_get_rbm(sts->a, length);
	i = 0;
	while (i < length && count_pb < length / 2)
	{
		if (ft_stack_peek(sts->a) < pivot)
		{
			ft_rpb(sts, count_pb, rbm);
			count_pb++;
		}
		else
		{
			ft_op_store_do(sts->op, ra_or_rr(sts->b, count_pb, rbm),
												sts->a, sts->b);
			count_ra++;
		}
		i++;
	}
	while (count_ra)
	{
		ft_op_store_do(sts->op, RA, sts->a, sts->b);
		count_ra--;
	}
	solve_quick_atob(sts, length - count_pb);
	solve_quick_btoa(sts, count_pb);
}

void		solve_quick_btoa(t_swstacks *sts, int length)
{
	int count_pa;
	int count_rb;
	int pivot;
	int i;

	count_pa = 0;
	count_rb = 0;
	if (length <= 3)
	{
		under3_b(sts, length);
		return ;
	}
	pivot = ft_get_pivot(sts->b, length);
	i = 0;
	while (i < length && count_pa < length / 2)
	{
		if (ft_stack_peek(sts->b) > pivot)
		{
			ft_op_store_do(sts->op, PA, sts->a, sts->b);
			count_pa++;
		}
		else
		{
			ft_op_store_do(sts->op, RB, sts->a, sts->b);
			count_rb++;
		}
		i++;
	}
	while (count_rb)
	{
		ft_op_store_do(sts->op, RA, sts->a, sts->b);
		count_rb--;
	}
	solve_quick_atob(sts, count_pa);
	solve_quick_btoa(sts, length - count_pa);
}
