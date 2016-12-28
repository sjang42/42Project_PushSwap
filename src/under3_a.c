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

int				ft_arr_order(int order, int arr[], int size)
{
	int i;
	int copy_arr[10];
	int order_4[4];

	i = 0;
	while (i < size)
	{
		copy_arr[i] = arr[i];
		i++;
	}
	ft_quicksort(copy_arr, 0, size - 1);
	order_4[0] = order % 10;
	order_4[1] = order % 100 / 10;
	order_4[2] = order % 1000 / 100;
	order_4[3] = order / 1000;

	if (size == 4 &&
		arr[3] == copy_arr[order_4[0] - 1] &&
		arr[2] == copy_arr[order_4[1] - 1] &&
		arr[1] == copy_arr[order_4[2] - 1] &&
		arr[0] == copy_arr[order_4[3] - 1])
		return (1);
	else if (size == 3 &&
		arr[2] == copy_arr[order_4[0] - 1] &&
		arr[1] == copy_arr[order_4[1] - 1] &&
		arr[0] == copy_arr[order_4[2] - 1])
		return (1);
	else
		return (0);
}

void			ft_stack_to_arr(t_stack *ps, int arr[], int size)
{
	t_stack_node	*cur;
	int				count;
	int				i;

	count = ft_stack_size(ps);
	if (count < 0)
		return ;
	i = 0;
	cur = ps->head;
	while (i < count && i < size)
	{
		arr[i++] = cur->data;
		cur = cur->next;
	}
}

static void		deal3_a_sub(t_operators *op, int arr[])
{
	if (ft_arr_order(213, arr, 3))
		ft_store_operator(op, SA);
	else if (ft_arr_order(312, arr, 3))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(132, arr, 3))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(231, arr, 3))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(321, arr, 3))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
}

void			under3_a(t_swstacks *sts, int length)
{
	int			arr[4];

	if (length <= 1)
		return ;
	ft_stack_to_arr(sts->a, arr, length);
	if (length == 3)
		deal3_a_sub(sts->op, arr);
	else if (length == 2 && arr[0] > arr[1])
			ft_store_operator(sts->op, SA);
}
