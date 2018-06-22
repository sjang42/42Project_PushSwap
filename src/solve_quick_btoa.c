/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quick_btoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 16:38:57 by sjang             #+#    #+#             */
/*   Updated: 2016/12/29 16:38:58 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static int              ft_future_rb(t_swstacks *sts, int length)
{
    int             count_rb;
    int             count_pa;
    int             pivot;
    t_stack_node    *cur;

    pivot = ft_get_pivot(sts->b, length);
    count_rb = 0;
    count_pa = 0;
    cur = sts->b->head;
    while (cur->next && (count_pa < ((length % 2 == 0) ?
                            (length / 2) : (length / 2 + 1))))
    {
        if (cur->data >= pivot)
            count_pa++;
        else
            count_rb++;
        cur = cur->next;
    }
    return (count_rb);
}

static t_quick_tool     *ft_tool_new_b(t_swstacks *sts, int length)
{
    t_quick_tool    *tool;

    tool = (t_quick_tool *)malloc(sizeof(t_quick_tool));
    tool->count_pa = 0;
    tool->count_ra = 0;
    tool->count_rb = 0;
    tool->future_rb = ft_future_rb(sts, length);
    tool->pivot = ft_get_pivot(sts->b, length);
    tool->ram = ft_get_ram(sts->b, length);
    tool->length = length;
    return (tool);
}

static void             send_half(
                        t_swstacks *sts, t_quick_tool *tool, int length)
{
    int i;

    i = 0;
    while (i < length && (tool->count_pa < ((length % 2 == 0) ?
                                            (length / 2) :
                                            (length / 2 + 1))))
    {
        if (ft_stack_peek(sts->b) >= tool->pivot)
        {
            tool->count_ra += ft_rpa(sts, tool);
            (tool->count_pa)++;
        }
        else
        {
            if (rb_or_rr(sts, tool) == RR)
            {
                ft_op_store_do(sts, RR);
                (tool->count_ra)++;
            }
            else
                ft_op_store_do(sts, RB);
            (tool->count_rb)++;
        }
        i++;
    }
}

static void             restore(t_swstacks *sts, t_quick_tool *tool, int length)
{
    while (tool->count_rb && ft_stack_size(sts->b) != length - tool->count_pa)
    {
        if (tool->count_ra > 0)
        {
            ft_op_store_do(sts, RRR);
            (tool->count_ra)--;
        }
        else
            ft_op_store_do(sts, RRB);
        (tool->count_rb)--;
    }
    while (tool->count_ra > 0)
    {
        ft_op_store_do(sts, RRA);
        (tool->count_ra)--;
    }
}

void                    solve_quick_btoa(t_swstacks *sts, int length, int rpb)
{
    t_quick_tool    *tool;
    int             count_pa;

    if (length <= 3)
    {
        under3_b(sts, length);
        return ;
    }
    tool = ft_tool_new_b(sts, length);
    send_half(sts, tool, length);
    restore(sts, tool, length);
    count_pa = tool->count_pa;
    free(tool);
    solve_quick_atob(sts, count_pa, rpb);
    solve_quick_btoa(sts, length - count_pa, rpb);
}
