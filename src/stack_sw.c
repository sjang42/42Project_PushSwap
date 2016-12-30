/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:37:14 by sjang             #+#    #+#             */
/*   Updated: 2016/11/27 20:37:15 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

t_sdata		ft_stack_least(t_stack *pstack)
{
	t_stack_node	*cur;
	t_sdata			least;

	if (ft_stack_isempty(pstack))
		return (0);
	cur = pstack->head;
	least = cur->data;
	while (cur)
	{
		if (cur->data < least)
			least = cur->data;
		cur = cur->next;
	}
	return (least);
}

t_sdata		ft_stack_most(t_stack *pstack)
{
	t_stack_node	*cur;
	t_sdata			most;

	if (ft_stack_isempty(pstack))
		return (0);
	cur = pstack->head;
	most = cur->data;
	while (cur)
	{
		if (cur->data > most)
			most = cur->data;
		cur = cur->next;
	}
	return (most);
}

void		ft_stack_display(t_stack *pstack)
{
	t_stack_node *cur;

	if (ft_stack_isempty(pstack))
		return ;
	cur = pstack->head;
	while (cur)
	{
		ft_putnbr_sw(cur->data);
		ft_putstr("\n");
		cur = cur->next;
	}
}

int			ft_stack_where_data(t_stack *ps, t_sdata q)
{
	t_stack_node	*cur;
	int				count;

	if (ft_stack_isempty(ps))
		return (0);
	count = 0;
	cur = ps->head;
	while (cur)
	{
		count++;
		if (cur->data == q)
			return (count);
		cur = cur->next;
	}
	return (0);
}

int			ft_stack_last(t_stack *ps)
{
	t_stack_node	*cur;

	cur = ps->head;
	while (cur->next)
		cur = cur->next;
	return (cur->data);
}
