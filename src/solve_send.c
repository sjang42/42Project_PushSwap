/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_send.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 18:33:46 by sjang             #+#    #+#             */
/*   Updated: 2016/12/23 18:33:48 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"


int				where_data(t_stack *ps, t_sdata data)//0: front, 1: back
{
	t_stack_node	*cur;
	int				i;

	cur = ps->head;
	i = 0;
	while (cur->next)
	{
		if (cur->data == data)
			return (i);
		cur = cur->next;
		i++;
	}
	if (cur->data == data)
		return (i);
	return (-1);
}


int				ft_is_descending(t_stack *ps, int length)
{
	t_stack_node	*cur;
	int				i;

	i = 0;
	cur = ps->head;
	while (cur->next && i < length)
	{
		if (cur->data < cur->next->data)
			return (0);
		cur = cur->next;
		i++;
	}
	return (1);
}

int				ft_stack_last(t_stack *ps)
{
	t_stack_node	*cur;

	cur = ps->head;
	while (cur->next)
		cur = cur->next;
	return (cur->data);
}



void			rem_check(int size, int *rem_front, int *rem_back)
{
	if (*rem_front == size || *rem_back == size)
	{
		*rem_front = 0;
		*rem_back = 0;
	}
}

void			rem_plus(int size, int *rem)
{
	if (*rem == size)
		*rem = 0;
	(*rem)++;
	if (*rem == size)
		*rem = 0;
}

void			rem_minus(int size, int *rem)
{
	if (*rem == size)
		*rem = 0;
	if (*rem == 0)
		*rem = size - 1;
	else
		(*rem)--;
	if (*rem == size)
		*rem = 0;
}

int				ft_find_spot(t_sdata data, t_stack *b, int rem_front)
{
	t_stack_node	*cur;
	int				count;

	/**/
	ft_putstr("data: ");
	ft_putnbr(data);
	ft_putstr("\n");
	/**/

	if (ft_stack_size(b) == 0)
		return (0);

	else if (ft_stack_size(b) == 1)
		return ((ft_stack_peek(b) < data) ? 0 : 1);

	// else if (!rem_front && data > ft_stack_peek(b))
	// 	return (0);

	cur = b->head;
	count = 1;
	while (cur->next)
	{
		if (rem_front == count &&
			(cur->data > data ||
			cur->next->data < data))
		{
			ft_putstr("rem_front: ");
			ft_putnbr(rem_front);
			ft_putstr("\n");
			ft_putstr("data: ");
			ft_putnbr(data);
			ft_putstr("\n");

			ft_putstr("h2\n");
			return (count);
		}
		else if (cur->data > data &&
			cur->next->data < data)
		{
			ft_putstr("rem_front: ");
			ft_putnbr(rem_front);
			ft_putstr("\n");
			ft_putstr("data: ");
			ft_putnbr(data);
			ft_putstr("\n");
			
			ft_putstr("h3\n");
			return (count);
		}
		cur = cur->next;
		count++;
	}
	return (count);
}




/*rem_back 작업 해야됨. result3.txt 1458라인을 보면 됨*/

t_operators		*sw_solve_send(t_stack *a, t_stack *b, t_operators *op)
{
	int size_a;
	int spot;
	int rem_front;
	int	op_tmp;
	int	k;
	int i;

	i = 0;
	rem_front = 0;
	size_a = ft_stack_size(a);

	while (i < size_a)
	{
		spot = ft_find_spot(ft_stack_peek(a), b, rem_front);

		if (spot == 0)								//맨앞
		{
			ft_op_store_do_show(op, PB, a, b);
			if (rem_front)
				rem_plus(ft_stack_size(b), &rem_front);
		}

		else if (spot == 1)
		{
			ft_op_store_do_show(op, PB, a, b);
			if (ft_stack_size(b) == 2)
				rem_plus(ft_stack_size(b), &rem_front);
			else
			{
				if (ft_stack_peek(b) < ft_stack_last(b))
					rem_plus(ft_stack_size(b), &rem_front);
				ft_op_store_do_show(op, SB, a, b);	
			}
		}

		else if (spot == ft_stack_size(b))			//맨뒤
		{
			ft_op_store_do_show(op, PB, a, b);
			rem_plus(ft_stack_size(b), &rem_front);
		}

		else										//중간
		{
			op_tmp = (spot > ft_stack_size(b) / 2) ? RRB : RB;
			k = (op_tmp == RB) ? spot : ft_stack_size(b) - spot;

			while (k)
			{
				ft_op_store_do_show(op, op_tmp, a, b);
				if (op_tmp == RB)
					rem_minus(ft_stack_size(b), &rem_front);
				if (op_tmp == RRB)
					rem_plus(ft_stack_size(b), &rem_front);
				k--;
			}

			ft_op_store_do_show(op, PB, a, b);
			if (ft_stack_peek(b) < ft_stack_last(b))
				rem_plus(ft_stack_size(b), &rem_front);
		}
		i++;
	}
	op_tmp = (rem_front > ft_stack_size(b) / 2) ? RRB : RB;
	k = (op_tmp == RB) ? rem_front : ft_stack_size(b) - rem_front;
	while (k)
	{
		ft_op_store_do_show(op, op_tmp, a, b);
		if (op_tmp == RB)
			rem_minus(ft_stack_size(b), &rem_front);
		if (op_tmp == RRB)
			rem_plus(ft_stack_size(b), &rem_front);
		k--;
	}

	size_a = ft_stack_size(b);
	while (size_a)
	{
		ft_op_store_do_show(op, PA, a, b);
		size_a--;
	}








	return (op);
}
