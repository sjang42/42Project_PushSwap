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

#include "main.h"

void	ft_putstr_wd(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 3);
		i += 3;
	}
}

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

void	ft_stack_display(t_stack *pstack)
{
	t_stack_node *cur;

	if (ft_stack_isempty(pstack))
		return ;
	cur = pstack->head;
	while (cur)
	{
		ft_putnbr(cur->data);
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

void	ft_stack_display_cos(t_stack *a, t_stack *b)
{
	t_stack_node	*cur;
	int				i;
	int				count;

	ft_putstr_wd("┌──────────────────────────────────────────────────  \n│");

	ft_putstr("	a :	");
	i = 0;
	cur = a->head;
	count = 0;
	while (cur)
	{
		if (i != 0)
			ft_putstr(", "); 
		if ((count + ft_digitcount(cur->data)) > 33)
		{
			write(1, "\n│		", 6);
			count = 0;
		}
		count += ft_putnbr(cur->data) + 2;
		cur = cur->next;
		i++;
	}
	ft_putstr("\n");
	ft_putstr_wd("│──────────────────────────────────────────────────  \n│");
	ft_putstr("	b :	");
	i = 0;
	cur = b->head;
	count = 0;
	while (cur)
	{
		if (i != 0)
			ft_putstr(", "); 
		if ((count + ft_digitcount(cur->data)) > 33)
		{
			write(1, "\n│		", 6);
			count = 0;
		}
		count += ft_putnbr(cur->data) + 2;
		cur = cur->next;
		i++;
	}
	ft_putstr("\n");
	ft_putstr_wd("└──────────────────────────────────────────────────  \n");
}
