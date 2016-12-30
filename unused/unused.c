/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unused.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 16:12:12 by sjang             #+#    #+#             */
/*   Updated: 2016/12/26 16:12:14 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			ft_op_store_do_show_ch(t_operators *op, t_sw_operator operator,
								t_stack *a, t_stack *b)
{
	ft_store_operator(op, operator);
	sw_operate(a, b, operator);
	ft_stack_display_cos(a, b);
}

t_stack		*ft_stack_dup(t_stack *ps)
{
	t_stack			*ret;
	t_stack_node	*cur;
	t_stack_node	*cur_ret;

	if (ft_stack_isempty(ps))
		return (NULL);
	ret = ft_stack_new();
	ret->head = (t_stack_node*)malloc(sizeof(t_stack_node));
	ret->head->data = ps->head->data;
	ret->head->next = NULL;

	cur = ps->head;
	cur_ret = ret->head;
	while (cur->next)
	{
		cur = cur->next;
		cur_ret->next = (t_stack_node*)malloc(sizeof(t_stack_node));
		cur_ret->next->data = cur->data;
		cur_ret->next->next = NULL;
		cur_ret = cur_ret->next;
	}
	return (ret);
}


void			ft_calculate_from(t_stack *a, t_stack *b,
									t_operators *op, size_t from)
{
	int i;

	i = from;
	while (i < op->idx)
	{
		sw_operate(a, b, (op->operators)[i]);
		i++;
	}
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

void			ftssau_deal_4(t_operators *op, int arr[])
{
	if (ft_arr_order(1234 ,arr, 4))
		;
	else if (ft_arr_order(1243 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(1324 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(1423 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
	}

	else if (ft_arr_order(1342 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(1432 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}

	else if (ft_arr_order(2134 ,arr, 4))
	{
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(2143 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(2314 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(2413 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}

	else if (ft_arr_order(2341 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(2431 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(3214 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(3241 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	 	ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	 	ft_store_operator(op, SA);
	}

	else if (ft_arr_order(3124 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(3421 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, PB);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	 	ft_store_operator(op, SA);
		ft_store_operator(op, PA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(3142 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}

	else if (ft_arr_order(3412 ,arr, 4))
	{

		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, PB);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, PA);
	}

	else if (ft_arr_order(4213 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, PB);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, PA);
	}
	else if (ft_arr_order(4231 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(4123 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(4321 ,arr, 4))
	{
	
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, PB);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, PA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(4132 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(4312 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, PB);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, PA);
	}
}

void			ftssau_deal_4_note(t_operators *op, int arr[])
{
	if (ft_arr_order(1234 ,arr, 4))
		;
	else if (ft_arr_order(1243 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(1324 ,arr, 4))
	{

		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(1423 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
	}

	else if (ft_arr_order(1342 ,arr, 4))
	{
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(1432 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}

	else if (ft_arr_order(2134 ,arr, 4))
	{
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(2143 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(2314 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(2413 ,arr, 4))
	{
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}

	else if (ft_arr_order(2341 ,arr, 4))
	{
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(2413 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
	}
	
	else if (ft_arr_order(3214 ,arr, 4))
	{
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(3241 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}

	else if (ft_arr_order(3124 ,arr, 4))
	{
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
	}
	else if (ft_arr_order(3421 ,arr, 4))
	{
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);

	}
	else if (ft_arr_order(3142 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}

	else if (ft_arr_order(3412 ,arr, 4))
	{
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
	}

	else if (ft_arr_order(4213 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(4231 ,arr, 4))
	{
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
	}
	else if (ft_arr_order(4123 ,arr, 4))
	{
		ft_store_operator(op, RA);
	}
	else if (ft_arr_order(4321 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(4132 ,arr, 4))
	{
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(4312 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
	}
}

