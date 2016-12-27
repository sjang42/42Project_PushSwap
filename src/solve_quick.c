/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 19:41:39 by sjang             #+#    #+#             */
/*   Updated: 2016/12/20 19:41:39 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int				*ft_stack_to_arr(t_stack *ps, int arr[], size_t size)
{
	t_stack_node	*cur;
	int				count;
	int				i;

	count = ft_stack_size(ps);
	if (count < 0)
		return (NULL);
	i = 0;
	cur = ps->head;
	while (i < count && i < size)
	{
		arr[i++] = cur->data;
		cur = cur->next;
	}
	return (arr);
}

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

static int		ft_get_rbm(t_stack *a, size_t length)
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
		return (arr[(length / 2) / 2]);
}


///////////고쳐야돼..
//ra로만 하는게 더 ㅅ빠르다 . . .

t_sw_operator ra_or_rra(t_stack *a, int pivot, int length)
{
	int				arr[length];
	int				front;
	int				back;
	int				i;

	if (ft_stack_size(a) != length)
		return (RA);
	i = 0;
	front = 0;
	back = 0;
	while (arr[i] < pivot)
		i++;
	while (arr[i + front] >= pivot)
		front++;//7
	i = ft_stack_size(a) - 1;//99
	while (arr[i - back] >= pivot)
		back++;//2
	if (front > back)
		return (RRA);
	else
		return (RA);
}

t_sw_operator sa_or_ss(t_stack *b)
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

t_sw_operator sb_or_ss(t_stack *a)
{
	t_stack_node	*cur;

	if (ft_stack_size(a) <= 1)
		return (SB);
	cur = a->head;
	if (cur->data > cur->next->data)
		return (SS);
	else
		return (SB);
}

t_sw_operator	ra_or_rr(t_stack *b, int count_b, int rbm)
{
	t_stack_node	*cur;
	t_sdata			data_first;
	t_sdata			data_last;

	if (ft_stack_size(b) <= 1)
		return (RA);
	cur = b->head;
	data_first = cur->data;
	while (cur->next)
		cur = cur->next;
	data_last = cur->data;
	if (ft_stack_size(b) == count_b &&
		rbm > data_first)
		return (RR);
	else
		return (RA);
}

int				rb_or_not(t_stack *b, int count_b, int rbm)
{
	if (ft_stack_size(b) != count_b ||
		ft_stack_size(b) == 0)
		return (0);
	if (ft_stack_peek(b) < rbm)
		return (1);
	else
		return (0);
}

void			ft_rpb(t_operators *op, t_sw_operator operator,
						t_stack *a, t_stack *b,	int count_b, int rbm)
{
	if (rb_or_not(b, count_b, rbm))
		ft_op_store_do_show(op, RB, a, b);
	ft_op_store_do_show(op, PB, a, b);
}



// t_sw_operator rb_or_rr(t_stack *a, int count_a)
// {
// 	t_stack_node	*cur;
// 	t_sdata			data_first;
// 	t_sdata			data_last;

// 	if (ft_stack_size(a) <= 1 || ft_stack_size(a) != count_a)
// 		return (RB);
// 	cur = a->head;
// 	data_first = cur->data;
// 	while (cur->next)
// 		cur = cur->next;
// 	data_last = cur->data;
// 	if (ft_get_midium(a, count_a) > data_first)
// 		return (RR);
// 	else
// 		return (RB);
// }

// t_sw_operator rb_or_rr(t_stack *a)
// {
// 	t_stack_node	*cur;
// 	t_sdata			data_first;
// 	t_sdata			data_last;

// 	if (ft_stack_size(a) <= 1)
// 	{
// 		printf("rb_or_rr : RB\n");
// 		return (RB);
// 	}
// 	cur = a->head;
// 	data_first = cur->data;
// 	while (cur->next)
// 		cur = cur->next;
// 	data_last = cur->data;

// 	if (data_first > data_last)
// 	{
// 		printf("rb_or_rr : RR\n");
// 		return (RR);
// 	}
// 	else
// 	{
// 		printf("rb_or_rr : RB\n");
// 		return (RB);
// 	}
// }





int				ft_get_pivot(t_stack *a, size_t length)
{
	return (ft_get_midium(a, length));
}

int				ft_arr_order(int order, int arr[], size_t size)
{
	size_t i;
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

t_operators			*ft_stack_sort_a_under3(t_stack *a, t_stack *b,
											int count_b, int length, int rbm)
{
	t_operators	*op;
	int			arr[4];

	op = ft_operators_new(10);
	ft_stack_to_arr(a, arr, length);
	if (length == 3)
		ftssau_deal_3(op, arr, b, count_b, rbm);
	else if (length == 2 && arr[0] > arr[1])	//ba
			ft_store_operator(op, sa_or_ss(b));
	return (op);
}

// t_operators			*ft_stack_sort_a_under3(t_stack *a, t_stack *b,
// 											int count_b, int length)
// {
// 	t_operators	*op;
// 	int			arr[3];

// 	op = ft_operators_new(10);
// 	ft_stack_to_arr(a, arr);
// 	if (length == 3)
// 	{
// 		if (arr[2] >= arr[1])
// 		{
// 			if (arr[1] >= arr[0])
// 				;
// 			else if (arr[2] >= arr[0])		//bac
// 				ft_store_operator(op, sa_or_ss(b));
// 			else							//cab
// 			{
// 				ft_store_operator(op, sa_or_ss(b));
// 				ft_store_operator(op, ra_or_rr(b, count_b, rbm));
// 				ft_store_operator(op, sa_or_ss(b));
// 				ft_store_operator(op, RRA);
// 			}
// 		}
// 		else
// 		{
// 			if (arr[2] >= arr[0])			//acbDD
// 			{
// 				ft_store_operator(op, ra_or_rr(b, count_b, rbm));
// 				ft_store_operator(op, sa_or_ss(b));
// 				ft_store_operator(op, RRA);
// 			}
// 			else if (arr[1] >= arr[0])		//bcaDD
// 			{
// 				ft_store_operator(op, ra_or_rr(b, count_b, rbm));
// 				ft_store_operator(op, sa_or_ss(b));
// 				ft_store_operator(op, RRA);
// 				ft_store_operator(op, sa_or_ss(b));
// 			}
// 			else						//cbaDD
// 			{
// 				ft_store_operator(op, sa_or_ss(b));
// 				ft_store_operator(op, ra_or_rr(b, count_b, rbm));
// 				ft_store_operator(op, sa_or_ss(b));
// 				ft_store_operator(op, RRA);
// 				ft_store_operator(op, sa_or_ss(b));
// 			}
// 		}
// 	}
// 	else if (length == 2 && arr[0] > arr[1])	//ba
// 			ft_store_operator(op, sa_or_ss(b));
// 	return (op);
// }





t_operators			*ft_stack_sort_b_under3(t_stack *a, t_stack *b, int length)
{
	t_operators	*op;
	int			arr[3];

	op = ft_operators_new(10);
	ft_stack_to_arr(b, arr, length);
	if (length == 3)
	{
		if (arr[2] >= arr[1])
		{
			if (arr[1] >= arr[0])		//abc
			{
				ft_store_operator(op, RB);
				ft_store_operator(op, sb_or_ss(a));
				ft_store_operator(op, PA);
				ft_store_operator(op, PA);
				ft_store_operator(op, RRB);
				ft_store_operator(op, PA);
			}
			else if (arr[2] >= arr[0])		//bac
			{
				ft_store_operator(op, RB);
				ft_store_operator(op, sb_or_ss(a));
				ft_store_operator(op, PA);
				ft_store_operator(op, RRB);
				ft_store_operator(op, PA);
				ft_store_operator(op, PA);
			}
			else						//cab
			{
				ft_store_operator(op, PA);
				ft_store_operator(op, sb_or_ss(a));
				ft_store_operator(op, PA);
				ft_store_operator(op, PA);
			}
		}
		else
		{
			if (arr[2] >= arr[0])		//acb
			{
				ft_store_operator(op, sb_or_ss(a));
				ft_store_operator(op, PA);
				ft_store_operator(op, sb_or_ss(a));
				ft_store_operator(op, PA);
				ft_store_operator(op, PA);
			}
			else if (arr[1] >= arr[0])	//bca
			{
				ft_store_operator(op, sb_or_ss(a));
				ft_store_operator(op, PA);
				ft_store_operator(op, PA);
				ft_store_operator(op, PA);
			}
			else						//cba
			{
				ft_store_operator(op, PA);
				ft_store_operator(op, PA);
				ft_store_operator(op, PA);
			}
		}
	}
	else if (length == 2 && arr[1] > arr[0])	//ba
	{
		ft_store_operator(op, sb_or_ss(a));
		ft_store_operator(op, PA);
		ft_store_operator(op, PA);
	}
	else if (length == 2)
	{
		ft_store_operator(op, PA);
		ft_store_operator(op, PA);
	}
	else if (length == 1)
			ft_store_operator(op, PA);
	return (op);
}


void			ft_opcat(t_operators *dst, t_operators *src)
{
	int i;

	i = 0;
	while (i < src->idx)
	{
		ft_store_operator(dst, (src->operators)[i]);
		i++;
	}
}

t_operators		*sw_solve_quick(t_stack *a, t_stack *b, t_operators *op,
								int order, int length)
{
	t_operators		*tmp;
	int				i;
	int				pivot;
	int				count_b;
	int				count_a;
	int				count_ra;
	int				count_rb;
	t_sw_operator	front_back;
	int				rbm;


	/*
	**				initialize
	*/
	count_b = 0;
	count_a = 0;
	count_ra = 0;
	count_rb = 0;


	/*
	**				deal under 3
	*/
	if (length <= 0)
		return (op);

	if (length <= 3 && order == 1)
	{
		tmp = ft_stack_sort_a_under3(a, b, count_b, length, rbm);
		ft_calculate_show(a, b, tmp);
		ft_opcat(op, tmp);
		ft_destroy_operators(&tmp);
		return (op);
	}
	if (length <= 3 && order == 2)
	{
		tmp = ft_stack_sort_b_under3(a, b, length);
		ft_calculate_show(a, b, tmp);
		ft_opcat(op, tmp);
		ft_destroy_operators(&tmp);
		return (op);
	}


	/*
	**				get a pivot and check the order of the stack
	*/
	pivot = (order == 1) ? ft_get_pivot(a, length) : ft_get_pivot(b, length);
	if(ft_check_stack(a, b))
		return (op);
	rbm = ft_get_rbm(a, length);
	/*
	**				do a quicksort
	*/

	// front_back = (ra_or_rra(a, pivot, length));
	front_back = RA;
	i = 0;
	while (i < length && length > 3 && order == 1 && count_b < length / 2)
	{
		if (ft_stack_peek(a) < pivot)
		{
			ft_rpb(op, PB, a, b, count_b, rbm);
			count_b++;
		}
		else
		{
			ft_op_store_do_show(op, ra_or_rr(b, count_b, rbm), a, b);
			count_ra++;
		}
		i++;
	}
	while (i < length && length > 3 && order == 2 &&
		(count_a < ((length % 2 == 0) ? (length / 2 - 1) : (length / 2))))
	{
		if (ft_stack_peek(b) > pivot)
		{
			ft_op_store_do_show(op, PA, a, b);
			count_a++;
		}
		else
		{
			ft_op_store_do_show(op, RB, a, b);
			ft_putstr("length: ");
			ft_putnbr(length);
			ft_putstr("\n");
			ft_putstr("i: ");
			ft_putnbr(i);
			ft_putstr("\n");
			ft_putstr("count_a: ");
			ft_putnbr(count_a);
			ft_putstr("\n");
			count_rb++;
		}
		i++;
	}


	/*
	**				restore the order
	*/
	while (count_ra && ft_stack_size(a) != length - count_b)
	{
		if (front_back == RA)
			ft_op_store_do_show(op, RRA, a, b);
		else
			ft_op_store_do_show(op, RA, a, b);
		count_ra--;
	}
	while (count_rb && ft_stack_size(b) != length - count_a)
	{
		ft_op_store_do_show(op, RRB, a, b);
		count_rb--;
	}


	/*
	**				repeat sorting
	*/
	if (order == 1)
	{
		sw_solve_quick(a, b, op, 1, length - count_b);
		sw_solve_quick(a, b, op, 2, count_b);
	}
	else
	{
		sw_solve_quick(a, b, op, 1, count_a);
		sw_solve_quick(a, b, op, 2, length - count_a);
	}
	return (op);
}
