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

#include "../include/main.h"

t_operators     *ft_operators_new(size_t size)
{
    t_operators *ret;

    ret = (t_operators*)malloc(sizeof(t_operators));
    ret->operators = (t_sw_operator*)malloc(sizeof(t_sw_operator) * size);
    ret->size = size;
    ret->idx = 0;
    return (ret);
}

void            ft_show_operator(t_sw_operator oper)
{
    if (oper == SA)
        ft_putstr("sa");
    else if (oper == SB)
        ft_putstr("sb");
    else if (oper == SS)
        ft_putstr("ss");
    else if (oper == PA)
        ft_putstr("pa");
    else if (oper == PB)
        ft_putstr("pb");
    else if (oper == RA)
        ft_putstr("ra");
    else if (oper == RB)
        ft_putstr("rb");
    else if (oper == RR)
        ft_putstr("rr");
    else if (oper == RRA)
        ft_putstr("rra");
    else if (oper == RRB)
        ft_putstr("rrb");
    else if (oper == RRR)
        ft_putstr("rrr");
    ft_putstr("\n");
}

int             ft_display_operators(t_operators *op)
{
    int i;

    i = 0;
    while (i < op->idx)
    {
        ft_show_operator((op->operators)[i]);
        i++;
    }
    return (i);
}
