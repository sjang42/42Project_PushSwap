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

static			t_sw_operator sa_or_ss(t_stack *b)
{
	t_stack_node	*cur;

	if (ft_stack_size(b) <= 1)
		return (SA);
	cur = b->head;
	if (cur->data < cur->next->data)
		return (SS);
	else
		return (SA);
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
	else if (ft_arr_order(231, arr, 3))
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

// static void		deal3_a_sub(t_swstacks *sts, int arr[],
// 							int count_b, int rbm)
// {
// 	rbm = count_b;
// 	if (ft_arr_order(213, arr, 3))
// 		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
// 	else if (ft_arr_order(312, arr, 3))
// 	{
// 		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
// 		ft_op_store_do(sts->op, RA, sts->a, sts->b);
// 		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
// 		ft_op_store_do(sts->op, RRA, sts->a, sts->b);
// 	}
// 	else if (ft_arr_order(132, arr, 3))
// 	{
// 		ft_op_store_do(sts->op, RA, sts->a, sts->b);
// 		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
// 		ft_op_store_do(sts->op, RRA, sts->a, sts->b);
// 	}
// 	else if (ft_arr_order(231, arr, 3))
// 	{
// 		ft_op_store_do(sts->op, RA, sts->a, sts->b);
// 		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
// 		ft_op_store_do(sts->op, RRA, sts->a, sts->b);
// 		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
// 	}
// 	else if (ft_arr_order(321, arr, 3))
// 	{
// 		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
// 		ft_op_store_do(sts->op, RA, sts->a, sts->b);
// 		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
// 		ft_op_store_do(sts->op, RRA, sts->a, sts->b);
// 		ft_op_store_do(sts->op, sa_or_ss(sts->b), sts->a, sts->b);
// 	}
// }

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
