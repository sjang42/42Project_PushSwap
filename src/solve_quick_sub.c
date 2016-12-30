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

static int		ft_get_midium(t_stack *a, int length)
{
	int				arr[length + 1];
	t_stack_node	*cur;
	int				i;

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

int				ft_get_pivot(t_stack *a, int length)
{
	return (ft_get_midium(a, length));
}

int				ft_get_rbm(t_stack *a, int length)
{
	int				arr[length + 1];
	t_stack_node	*cur;
	int				i;
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

int				ft_get_ram(t_stack *b, int length)
{
	int				arr[length + 1];
	t_stack_node	*cur;
	int				i;
	int				idx;

	i = 0;
	cur = b->head;
	while (i < length && cur)
	{
		arr[i] = cur->data;
		cur = cur->next;
		i++;
	}
	ft_quicksort(arr, 0, length - 1);
	idx = length / 2;
	if (length % 2 != 0)
		idx += 1;
	idx /= 2;
	idx += length / 2;
	return (arr[idx]);
}
