/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under3_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:03:01 by sjang             #+#    #+#             */
/*   Updated: 2016/12/27 16:03:02 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void		deal3_b_sub(t_operators *op, int arr[])
{
	if (ft_arr_order(123, arr, 3))		//abc
	{
		ft_store_operator(op, RB);
		ft_store_operator(op, SB);
		ft_store_operator(op, PA);
		ft_store_operator(op, PA);
		ft_store_operator(op, RRB);
		ft_store_operator(op, PA);
	}
	else if (ft_arr_order(213, arr, 3))	//bac
	{
		ft_store_operator(op, RB);
		ft_store_operator(op, SB);
		ft_store_operator(op, PA);
		ft_store_operator(op, RRB);
		ft_store_operator(op, PA);
		ft_store_operator(op, PA);
	}
	else if (ft_arr_order(312, arr, 3))	//cab
	{
		ft_store_operator(op, PA);
		ft_store_operator(op, SB);
		ft_store_operator(op, PA);
		ft_store_operator(op, PA);
	}
	else if (ft_arr_order(132, arr, 3))	//acb
	{
		ft_store_operator(op, SB);
		ft_store_operator(op, PA);
		ft_store_operator(op, SB);
		ft_store_operator(op, PA);
		ft_store_operator(op, PA);
	}
	else if (ft_arr_order(231, arr, 3))	//bca
	{
		ft_store_operator(op, SB);
		ft_store_operator(op, PA);
		ft_store_operator(op, PA);
		ft_store_operator(op, PA);
	}
	else if (ft_arr_order(321, arr, 3))	//cba
	{
		ft_store_operator(op, PA);
		ft_store_operator(op, PA);
		ft_store_operator(op, PA);
	}
}

void			under3_b(t_swstacks *sts, int length)
{
	int			arr[4];

	if (length <= 0)
		return ;
	ft_stack_to_arr(sts->b, arr, length);
	if (length == 3)
		deal3_b_sub(sts->op, arr);
	else if (length == 2 && arr[1] > arr[0])	//ba
	{
		ft_store_operator(sts->op, SB);
		ft_store_operator(sts->op, PA);
		ft_store_operator(sts->op, PA);
	}
	else if (length == 2)
	{
		ft_store_operator(sts->op, PA);
		ft_store_operator(sts->op, PA);
	}
	else if (length == 1)
			ft_store_operator(sts->op, PA);
}
