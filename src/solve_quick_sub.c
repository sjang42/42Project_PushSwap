/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quick_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:58:06 by sjang             #+#    #+#             */
/*   Updated: 2016/12/27 16:58:06 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static int		ft_get_midium(t_stack *a, size_t length)
{
	int				arr[length + 1];
	t_stack_node	*cur;
	size_t			i;

	i = 0;
	cur = a->head;
	while (i < length && cur)
	{
		arr[i] = cur->data;
		cur = cur->next;
		i++;
	}
	ft_quicksort(arr, 0, length - 1);
	if (length == 0)
		return (arr[0]);
	else
		return (arr[length / 2]);
}

int				ft_get_pivot(t_stack *a, size_t length)
{
	return (ft_get_midium(a, length));
}

int				ft_get_rbm(t_stack *a, size_t length)
{
	int				arr[length + 1];
	t_stack_node	*cur;
	size_t			i;
	int				idx;

	i = 0;
	cur = a->head;
	while (i < length && cur)
	{
		arr[i] = cur->data;
		cur = cur->next;
		i++;
	}
	ft_quicksort(arr, 0, length - 1);
	idx = length / 2;
	idx /= 2;
	if (length == 0)
		return (arr[0]);
	else
		return (arr[idx]);
}

// t_sw_operator	ra_or_rr(t_stack *b, int count_b, int rbm)
// {
// 	t_stack_node	*cur;
// 	t_sdata			data_first;
// 	t_sdata			data_last;

// 	if (ft_stack_size(b) <= 1)
// 		return (RA);
// 	cur = b->head;
// 	data_first = cur->data;
// 	while (cur->next)
// 		cur = cur->next;
// 	data_last = cur->data;
// 	if (ft_stack_size(b) == count_b &&
// 		rbm > data_first)
// 		return (RR);
// 	else
// 		return (RA);
// }

t_sw_operator	ra_or_rr(t_stack *b, int count_b, int rbm)
{
	if (ft_stack_size(b) <= 1 || ft_stack_size(b) != count_b)
		return (RA);
	if (ft_stack_peek(b) < rbm)
		return (RR);
	else
		return (RA);
}

static int		rb_or_not(t_stack *b, int count_b, int rbm)
{
	if (ft_stack_size(b) != count_b ||
		ft_stack_size(b) <= 1)
		return (0);
	if (b->head->next->data < rbm)
		return (0);
	if (ft_stack_peek(b) < rbm)
		return (1);
	else
		return (0);
}

int				ft_rpb(t_swstacks *sts,	int count_b, int rbm)
{
	int count;

	count = 0;
	if (rb_or_not(sts->b, count_b, rbm))
	{
		ft_op_store_do(sts->op, RB, sts->a, sts->b);
	}
	if (ft_stack_size(sts->b) != count_b &&
		ft_stack_peek(sts->b) > rbm)
	{
		ft_op_store_do(sts->op, RB, sts->a, sts->b);
		count++;
	}
	ft_op_store_do(sts->op, PB, sts->a, sts->b);
	return (count);
}

// int				ft_rpb(t_swstacks *sts,	int count_b, int rbm)
// {
// 	int count;

// 	count = 0;
// 	if (rb_or_not(sts->b, count_b, rbm))
// 		ft_op_store_do(sts->op, RB, sts->a, sts->b);
// 	ft_op_store_do(sts->op, PB, sts->a, sts->b);
// 	return (count);
// }
