/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under3_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:02:55 by sjang             #+#    #+#             */
/*   Updated: 2016/12/27 16:02:56 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void		deal3_a_sub2(t_swstacks *sts, int arr[])
{
	if (ft_arr_order(231, arr, 3))
	{
		ft_op_store_do(sts->op, RA, sts->a, sts->b);
		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
		ft_op_store_do(sts->op, RRA, sts->a, sts->b);
		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
	}
	else if (ft_arr_order(321, arr, 3))
	{
		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
		ft_op_store_do(sts->op, RA, sts->a, sts->b);
		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
		ft_op_store_do(sts->op, RRA, sts->a, sts->b);
		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
	}
}

static void		deal3_a_sub(t_swstacks *sts, int arr[])
{
	if (ft_arr_order(213, arr, 3))
		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
	else if (ft_arr_order(312, arr, 3))
	{
		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
		ft_op_store_do(sts->op, RA, sts->a, sts->b);
		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
		ft_op_store_do(sts->op, RRA, sts->a, sts->b);
	}
	else if (ft_arr_order(132, arr, 3))
	{
		ft_op_store_do(sts->op, RA, sts->a, sts->b);
		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
		ft_op_store_do(sts->op, RRA, sts->a, sts->b);
	}
	else
		deal3_a_sub2(sts, arr);
}

static void		deal3_a_sub_note(t_swstacks *sts, int arr[])
{
	if (ft_arr_order(123, arr, 3))
		;
	else if (ft_arr_order(213, arr, 3))
		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
	else if (ft_arr_order(312, arr, 3))
		ft_op_store_do(sts->op, RA, sts->a, sts->b);
	else if (ft_arr_order(132, arr, 3))
	{
		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
		ft_op_store_do(sts->op, RA, sts->a, sts->b);
	}
	else if (ft_arr_order(231, arr, 3))
		ft_op_store_do(sts->op, RRA, sts->a, sts->b);
	else if (ft_arr_order(321, arr, 3))
	{
		ft_op_store_do(sts->op, RA, sts->a, sts->b);
		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
	}
}

void			under3_a(t_swstacks *sts, int length)
{
	int			arr[4];

	if (length <= 1)
		return ;
	ft_stack_to_arr(sts->a, arr, length);
	if (length == 3)
		(ft_stack_size(sts->a) == length) ?
		deal3_a_sub_note(sts, arr) :
		deal3_a_sub(sts, arr);
	else if (length == 2 && arr[0] > arr[1])
		ft_op_store_do(sts->op, SA, sts->a, sts->b);
}
