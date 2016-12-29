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

int			ft_future_ra(t_swstacks *sts, int length)
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

// int			ft_future_rb(t_swstacks *sts, int length)
// {
// 	int				count_rb;
// 	int				count_pa;
// 	int				pivot;
// 	t_stack_node	*cur;

// 	// if(ft_stack_isempty(sts->b))
// 	// 	return (0);
// 	pivot = ft_get_pivot(sts->a, length);
// 	count_ra = 0;
// 	count_pb = 0;
// 	cur = sts->a->head;
// 	while (cur->next && (count_pb < length / 2))
// 	{
// 		if (cur->data < pivot)
// 			count_pb++;
// 		else
// 			count_ra++;
// 		cur = cur->next;
// 	}
// 	return (count_ra);
// }

void		solve_quick_atob(t_swstacks *sts, int length)
{
	t_quick_tool *tool;
	int i;

	if (length <= 3)
	{
		// pivot = ft_get_pivot(sts->a, length);
		under3_a(sts, length);
		return ;
	}
	tool = (t_quick_tool *)malloc(sizeof(t_quick_tool));
	tool->count_pb = 0;
	tool->count_ra = 0;
	tool->count_rb = 0;
	tool->future_ra = ft_future_ra(sts, length);
	tool->pivot = ft_get_pivot(sts->a, length);
	tool->rbm = ft_get_rbm(sts->a, length);
	tool->length = length;
	i = 0;
	while (i < length && (tool->count_pb < length / 2))
	{
		if (ft_stack_peek(sts->a) < tool->pivot)
		{
			if (tool->count_rb < tool->future_ra ||
				ft_stack_size(sts->b) == tool->count_pb)
				tool->count_rb += ft_rpb(sts, tool);
			else
				ft_op_store_do(sts->op, PB, sts->a, sts->b);
			(tool->count_pb)++;
		}
		else
		{
			if ((tool->count_rb < tool->future_ra ||
				ft_stack_size(sts->b) == tool->count_pb) &&
				ra_or_rr(sts->b, tool->count_pb, tool->rbm) == RR)
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
}

void		solve_quick_btoa(t_swstacks *sts, int length)
{
	int count_pa;
	int count_rb;
	int pivot;
	int i;
	int future_rb;

	count_rb = 0;
	if (length <= 3)
	{
		pivot = ft_get_pivot(sts->b, length);
		under3_b(sts, length);
		return ;
	}
	pivot = ft_get_pivot(sts->b, length);
	i = 0;
	count_pa = 0;

	while (i < length && (count_pa < ((length % 2 == 0) ?
							(length / 2) : (length / 2 + 1))))
	{
		if (ft_stack_peek(sts->b) >= pivot)
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
	while (count_rb && ft_stack_size(sts->b) != length - count_pa)
	{
		ft_op_store_do(sts->op, RRB, sts->a, sts->b);
		count_rb--;
	}
	solve_quick_atob(sts, count_pa);
	solve_quick_btoa(sts, length - count_pa);
}

// void		solve_quick_atob(t_swstacks *sts, int length)
// {
// 	int count_pb;
// 	int count_ra;
// 	int rbm;
// 	int pivot;
// 	int i;
// 	int	count_rb;
// 	int future_ra;

// 	count_pb = 0;
// 	count_ra = 0;
// 	count_rb = 0;
// 	rbm = ft_get_rbm(sts->a, length);
// 	if (length <= 3)
// 	{
// 		// pivot = ft_get_pivot(sts->a, length);
// 		under3_a(sts, length);
// 		return ;
// 	}
// 	future_ra = ft_future_ra(sts, length);
// 	pivot = ft_get_pivot(sts->a, length);
// 	rbm = ft_get_rbm(sts->a, length);
// 	i = 0;
// 	while (i < length && (count_pb < length / 2))
// 	{
// 		if (ft_stack_peek(sts->a) < pivot)
// 		{
// 			if (count_rb < future_ra)
// 				count_rb += ft_rpb(sts, count_pb, rbm);
// 			else
// 				ft_op_store_do(sts->op, PB, sts->a, sts->b);
// 			count_pb++;
// 		}
// 		else
// 		{
// 			if (count_rb < future_ra && ra_or_rr(sts->b, count_pb, rbm) == RR)
// 			{
// 				ft_op_store_do(sts->op, RR,	sts->a, sts->b);
// 				count_rb++;
// 			}
// 			else
// 				ft_op_store_do(sts->op, RA,	sts->a, sts->b);
// 			count_ra++;
// 		}
// 	}

// 	while (count_ra && ft_stack_size(sts->a) != length - count_pb)
// 	{
// 		if (count_rb > 0)
// 		{
// 			ft_op_store_do(sts->op, RRR, sts->a, sts->b);
// 			count_rb--;
// 		}
// 		else
// 			ft_op_store_do(sts->op, RRA, sts->a, sts->b);
// 		count_ra--;
// 	}
// 	while (count_rb > 0)
// 	{
// 		ft_op_store_do(sts->op, RRB, sts->a, sts->b);
// 		count_rb--;
// 	}
// 	solve_quick_atob(sts, length - count_pb);
// 	solve_quick_btoa(sts, count_pb);
// }

// void		solve_quick_btoa(t_swstacks *sts, int length)
// {
// 	int count_pa;
// 	int count_rb;
// 	int pivot;
// 	int i;

// 	count_rb = 0;
// 	if (length <= 3)
// 	{
// 		pivot = ft_get_pivot(sts->b, length);
// 		under3_b(sts, length);
// 		return ;
// 	}
// 	pivot = ft_get_pivot(sts->b, length);
// 	i = 0;
// 	count_pa = 0;

// 	while (i < length && (count_pa < ((length % 2 == 0) ?
// 							(length / 2) : (length / 2 + 1))))
// 	{
// 		if (ft_stack_peek(sts->b) >= pivot)
// 		{
// 			ft_op_store_do(sts->op, PA, sts->a, sts->b);
// 			count_pa++;
// 		}
// 		else
// 		{
// 			ft_op_store_do(sts->op, RB, sts->a, sts->b);
// 			count_rb++;
// 		}
// 		i++;
// 	}
// 	while (count_rb && ft_stack_size(sts->b) != length - count_pa)
// 	{
// 		ft_op_store_do(sts->op, RRB, sts->a, sts->b);
// 		count_rb--;
// 	}
// 	solve_quick_atob(sts, count_pa);
// 	solve_quick_btoa(sts, length - count_pa);
// }

// void		solve_quick_atob(t_swstacks *sts, int length)
// {
// 	int count_pb;
// 	int count_ra;
// 	int rbm;
// 	int pivot;
// 	int i;

// 	// printf("len of atob: %d\n", length);
// 	count_pb = 0;
// 	count_ra = 0;
// 	rbm = ft_get_rbm(sts->a, length);
// 	if (length <= 3)
// 	{
// 		under3_a(sts, length, count_pb, rbm);
// 		// ft_putstr("yup\n");
// 		// ft_putnbr(length);
// 		// ft_putstr("yup\n");

// 		return ;
// 	}
// 	pivot = ft_get_pivot(sts->a, length);
// 	// printf("pivot of a: %d\n", pivot);
// 	// printf("rbm: %d\n", rbm);


// 	rbm = ft_get_rbm(sts->a, length);
// 	i = 0;
// 	// while (i < length && (count_pb < length / 2))
// 	while (i < length && (count_pb < length / 2))
// 	{
// 		if (ft_stack_peek(sts->a) < pivot)
// 		{
// 			// ft_op_store_do(sts->op, PB, sts->a, sts->b);
// 			ft_rpb(sts, count_pb, rbm);
// 			count_pb++;
// 		}
// 		else
// 		{
// 			ft_op_store_do(sts->op, ra_or_rr(sts->b, count_pb, rbm),
// 											sts->a, sts->b);
// 			count_ra++;
// 		}
// 		i++;
// 	}
// 	while (count_ra && ft_stack_size(sts->a) != length - count_pb)
// 	{
// 		ft_op_store_do(sts->op, RRA, sts->a, sts->b);
// 		count_ra--;
// 	}
// 	// printf("count_pb : %d\n", count_pb);
// 	solve_quick_atob(sts, length - count_pb);
// 	solve_quick_btoa(sts, count_pb);
// }

// void		solve_quick_btoa(t_swstacks *sts, int length)
// {
// 	int count_pa;
// 	int count_rb;
// 	int pivot;
// 	int i;

// 	// printf("len of btoa: %d\n", length);
// 	count_rb = 0;
// 	if (length <= 3)
// 	{
// 		under3_b(sts, length);
// 		return ;
// 	}
// 	pivot = ft_get_pivot(sts->b, length);
// 	// printf("pivot of b: %d\n", pivot);
// 	i = 0;
// 	count_pa = 0;

// 	while (i < length && (count_pa < ((length % 2 == 0) ?
// 							(length / 2) : (length / 2 + 1))))
// 	{
// 		if (ft_stack_peek(sts->b) >= pivot)
// 		{
// 			count_pa++;
// 			ft_op_store_do(sts->op, PA, sts->a, sts->b);
// 			// ft_putstr("\npapapa\n");
// 		}
// 		else
// 		{
// 			ft_op_store_do(sts->op, RB, sts->a, sts->b);
// 			count_rb++;
// 		}
// 		i++;
// 	}
// 	while (count_rb && ft_stack_size(sts->b) != length - count_pa)
// 	{
// 		ft_op_store_do(sts->op, RRB, sts->a, sts->b);
// 		count_rb--;
// 	}
// 	// printf("count_pa : %d\n", count_pa);
// 	solve_quick_atob(sts, count_pa);
// 	solve_quick_btoa(sts, length - count_pa);
// }



// void		solve_quick_atob(t_swstacks *sts, int length)
// {
// 	int count_pb;
// 	int count_ra;
// 	int rbm;
// 	int pivot;
// 	int i;

// 	count_pb = 0;
// 	count_ra = 0;
// 	rbm = ft_get_rbm(sts->a, length);
// 	if (length <= 3)
// 	{
// 		under3_a(sts, length, count_pb, rbm);
// 		return ;
// 	}
// 	pivot = ft_get_pivot(sts->a, length);
// 	rbm = ft_get_rbm(sts->a, length);
// 	i = 0;
// 	while (i < length && (count_pb < length / 2))
// 	{
// 		if (ft_stack_peek(sts->a) < pivot)
// 		{
// 			ft_rpb(sts, count_pb, rbm);
// 			// ft_op_store_do(sts->op, PB, sts->a, sts->b);
// 			count_pb++;
// 		}
// 		else
// 		{
// 			ft_op_store_do(sts->op, ra_or_rr(sts->b, count_pb, rbm), sts->a, sts->b);
// 			count_ra++;
// 		}
// 		i++;
// 	}
// 	while (count_ra && ft_stack_size(sts->a) != length - count_pb)
// 	{
// 		ft_op_store_do(sts->op, RRA, sts->a, sts->b);
// 		count_ra--;
// 	}
// 	solve_quick_atob(sts, length - count_pb);
// 	solve_quick_btoa(sts, count_pb);
// }

// void		solve_quick_btoa(t_swstacks *sts, int length)
// {
// 	int count_pa;
// 	int count_rb;
// 	int pivot;
// 	int i;

// 	count_pa = 0;
// 	count_rb = 0;
// 	if (length <= 3)
// 	{
// 		under3_b(sts, length);
// 		return ;
// 	}
// 	pivot = ft_get_pivot(sts->b, length);
// 	i = 0;
// 	while (i < length && (count_pa < ((length % 2 == 0) ?
// 							(length / 2 - 1) : (length / 2))))
// 	{
// 		if (ft_stack_peek(sts->b) > pivot)
// 		{
// 			ft_op_store_do(sts->op, PA, sts->a, sts->b);
// 			count_pa++;
// 		}
// 		else
// 		{
// 			ft_op_store_do(sts->op, RB, sts->a, sts->b);
// 			count_rb++;
// 		}
// 		i++;
// 	}
// 	while (count_rb && ft_stack_size(sts->b) != length - count_pa)
// 	{
// 		ft_op_store_do(sts->op, RRB, sts->a, sts->b);
// 		count_rb--;
// 	}
// 	solve_quick_atob(sts, count_pa);
// 	solve_quick_btoa(sts, length - count_pa);
// }

// void		solve_quick_atob(t_swstacks *sts, int length)
// {
// 	int count_pb;
// 	int count_ra;
// 	int rbm;
// 	int pivot;
// 	int i;

// 	count_pb = 0;
// 	count_ra = 0;
// 	rbm = ft_get_rbm(sts->a, length);
// 	if (length <= 3)
// 	{
// 		under3_a(sts, length, count_pb, rbm);
// 		return ;
// 	}
// 	pivot = ft_get_pivot(sts->a, length);
// 	rbm = ft_get_rbm(sts->a, length);
// 	i = 0;
// 	while (i < length && (count_pb < ((length % 2 == 0) ?
// 							(length / 2) : (length / 2))))
// 	{
// 		if (ft_stack_peek(sts->a) < pivot)
// 		{
// 			ft_rpb(sts, count_pb, rbm);
// 			count_pb++;
// 		}
// 		else
// 		{
// 			ft_op_store_do(sts->op, ra_or_rr(sts->b, count_pb, rbm),
// 												sts->a, sts->b);
// 			count_ra++;
// 		}
// 		i++;
// 	}
// 	while (count_ra && ft_stack_size(sts->a) != length - count_pb)
// 	{
// 		ft_op_store_do(sts->op, RRA, sts->a, sts->b);
// 		count_ra--;
// 	}
// 	solve_quick_atob(sts, length - count_pb);
// 	solve_quick_btoa(sts, count_pb);
// }

// void		solve_quick_btoa(t_swstacks *sts, int length)
// {
// 	int count_pa;
// 	int count_rb;
// 	int pivot;
// 	int i;

// 	count_pa = 0;
// 	count_rb = 0;
// 	if (length <= 3)
// 	{
// 		under3_b(sts, length);
// 		return ;
// 	}
// 	pivot = ft_get_pivot(sts->b, length);
// 	i = 0;
// 	while (i < length && (count_pa < ((length % 2 == 0) ?
// 							(length / 2 - 1) : (length / 2))))
// 	{
// 		if (ft_stack_peek(sts->b) > pivot)
// 		{
// 			ft_op_store_do(sts->op, PA, sts->a, sts->b);
// 			count_pa++;
// 		}
// 		else
// 		{
// 			ft_op_store_do(sts->op, RB, sts->a, sts->b);
// 			count_rb++;
// 		}
// 		i++;
// 	}
// 	while (count_rb && ft_stack_size(sts->b) != length - count_pa)
// 	{
// 		ft_op_store_do(sts->op, RRB, sts->a, sts->b);
// 		count_rb--;
// 	}
// 	solve_quick_atob(sts, count_pa);
// 	solve_quick_btoa(sts, length - count_pa);
// }
