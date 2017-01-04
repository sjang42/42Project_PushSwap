/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 10:41:09 by sjang             #+#    #+#             */
/*   Updated: 2016/12/22 10:41:10 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void		ft_stack_copy(t_stack *dest, t_stack *src)
{
	t_stack			*tmp;
	t_stack_node	*cur;

	if (ft_stack_isempty(src))
		return ;
	tmp = ft_stack_new();
	cur = src->head;
	while (cur)
	{
		ft_stack_push(tmp, cur->data);
		cur = cur->next;
	}
	while (!ft_stack_isempty(tmp))
		ft_stack_push(dest, ft_stack_pop(tmp));
	ft_stack_destroy(&tmp);
}

int			main(int argc, char *argv[])
{
	t_swstacks		*sts;
	t_swstacks		*sts2;
	t_swoptions		option;

	if (argc < 2)
		return (0);
	option = get_option(argc, argv);
	sts = ft_stsnew(option);
	sts2 = ft_stsnew(option);
	ft_get_stack_a(argc, argv, sts);
	ft_stack_copy(sts2->a, sts->a);
	if (ft_check_stack(sts->a, sts->b))
	{
		ft_destroy_sts(sts);
		return (0);
	}
	solve_quick_atob(sts, ft_stack_size(sts->a), 1);
	solve_quick_atob(sts2, ft_stack_size(sts2->a), 0);
	ft_display_operators(((sts->op->idx < sts2->op->idx) ?
							sts->op : sts2->op));
	ft_destroy_sts(sts);
	ft_destroy_sts(sts2);
	return (0);
}
