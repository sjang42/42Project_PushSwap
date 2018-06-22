/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_solve_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 09:26:59 by sjang             #+#    #+#             */
/*   Updated: 2016/12/21 09:27:00 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void            ft_calculate_ij(t_stack *a, t_stack *b, t_operators *op, int i[])
{
    int start;
    int finish;

    start = i[0];
    finish = i[1];
    while (start < finish)
    {
        sw_operate(a, b, (op->operators)[start]);
        ft_stack_display_cos(a, b);
        start++;
    }
    ft_putstr("\n\n");
}

// int              sw_add_pa(t_operators *op)
// {
//  int i;
//  int fix_idx;
    
//  i = 0;
//  fix_idx = op->idx;
//  while (i < fix_idx)
//  {
//      if ((op->operators)[i] == PB)
//          ft_store_operator(op, PA);
//      i++;
//  }
//  return (j - fix_idx - 1);
// }

void            sw_add_pa(t_operators *op, t_stack *a, t_stack *b)
{
    int i;
    int fix_idx;
    
    i = 0;
    fix_idx = op->idx;
    while (i < fix_idx)
    {
        if ((op->operators)[i] == PB)
            ft_op_store_do_show(op, PA, a, b);
        i++;
    }
}

t_operators     *sw_solve(t_stack *a, t_stack *b)
{
    t_operators *op;
    t_sdata     least_a;
    int         size_a;
    int         where_least;
    
    op = ft_operators_new(100);
    ft_stack_display_cos(a, b);
    ft_putstr("\n\n");

    while ((size_a = ft_stack_size(a)) > 1)
    {
        least_a = ft_stack_least(a);
        where_least = ft_stack_where_data(a, least_a);

        if (where_least == 2)
            ft_op_store_do_show(op, SA, a, b);

        else if (where_least >= 3)
        {
            if (where_least <= size_a / 2)
            {
                while (ft_stack_peek(a) != least_a)
                    ft_op_store_do_show(op, RA, a, b);
            }
            else
            {
                while (ft_stack_peek(a) != least_a)
                    ft_op_store_do_show(op, RRA, a, b);
            }
        }

        if (ft_stack_issort(a))
            break ;
        ft_op_store_do_show(op, PB, a, b);
    }
    sw_add_pa(op, a, b);
    return (op);
}

