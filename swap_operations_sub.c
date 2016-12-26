/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations_sub.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 01:14:41 by sjang             #+#    #+#             */
/*   Updated: 2016/11/26 01:14:42 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "stack.h"
# include "swap_base.h"
# include "main.h"

int		sw_swap(t_stack *pstack)
{
	t_sdata tmp;

	if (ft_stack_isempty(pstack) ||
		pstack->head->next == NULL)
		return (0);
	tmp = pstack->head->next->data;
	pstack->head->next->data = pstack->head->data;
	pstack->head->data = tmp;
	return (1);
}

int		sw_push(t_stack *srcp, t_stack *destp)
{
	t_sdata		tmp;

	if (ft_stack_isempty(srcp))
		return (0);
	tmp = ft_stack_pop(srcp);
	ft_stack_push(destp, tmp);
	return (1);
}

int		sw_rotate(t_stack *pstack)
{
	if (ft_stack_isempty(pstack) ||
		pstack->head->next == NULL)
		return (0);
	pstack->tail->next = pstack->head;
	pstack->tail = pstack->head;
	pstack->head = pstack->head->next;
	pstack->tail->next = NULL;
	return (1);
}

int		sw_rotate_rev(t_stack *pstack)
{
	t_stack_node *pretail;

	if (ft_stack_isempty(pstack) ||
		pstack->head->next == NULL)
		return (0);

	pretail = pstack->head;
	while (pretail->next != pstack->tail)
		pretail = pretail->next;
	pstack->tail->next = pstack->head;
	pstack->head = pstack->tail;
	pstack->tail = pretail;
	pstack->tail->next = NULL;
	return (1);
}
