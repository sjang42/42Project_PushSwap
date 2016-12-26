/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 09:25:19 by sjang             #+#    #+#             */
/*   Updated: 2016/12/21 09:25:20 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			ft_memcheck_operators(t_operators *op)
{
	if (op->idx >= op->size - 2)
	{
		op->operators =
		(t_sw_operator*)ft_realloc(op->operators, op->size * sizeof(t_sw_operator),
										(op->size + 100) * sizeof(t_sw_operator));

		op->size += 100;
	}
}

void			ft_store_operator(t_operators *op, t_sw_operator operator)
{
	ft_memcheck_operators(op);
	(op->operators)[op->idx] = operator;
	(op->idx)++;
}

t_operators		*ft_operators_new(size_t size)
{
	t_operators	*ret;

	ret = (t_operators*)malloc(sizeof(t_operators));
	ret->operators = (t_sw_operator*)malloc(sizeof(t_sw_operator) * size);
	ret->size = size;
	ret->idx = 0;
	return (ret);
}
