/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under3_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:03:01 by sjang             #+#    #+#             */
/*   Updated: 2016/12/27 16:03:02 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void     deal3_b_sub3(t_swstacks *sts, int arr[])
{
    if (ft_arr_order(231, arr, 3))
    {
        ft_op_store_do(sts, SB);
        ft_op_store_do(sts, PA);
        ft_op_store_do(sts, PA);
        ft_op_store_do(sts, PA);
    }
    else if (ft_arr_order(321, arr, 3))
    {
        ft_op_store_do(sts, PA);
        ft_op_store_do(sts, PA);
        ft_op_store_do(sts, PA);
    }
}

static void     deal3_b_sub2(t_swstacks *sts, int arr[])
{
    if (ft_arr_order(312, arr, 3))
    {
        ft_op_store_do(sts, PA);
        ft_op_store_do(sts, SB);
        ft_op_store_do(sts, PA);
        ft_op_store_do(sts, PA);
    }
    else if (ft_arr_order(132, arr, 3))
    {
        ft_op_store_do(sts, SB);
        ft_op_store_do(sts, PA);
        ft_op_store_do(sts, SB);
        ft_op_store_do(sts, PA);
        ft_op_store_do(sts, PA);
    }
    else
        deal3_b_sub3(sts, arr);
}

static void     deal3_b_sub(t_swstacks *sts, int arr[])
{
    if (ft_arr_order(123, arr, 3))
    {
        ft_op_store_do(sts, RB);
        ft_op_store_do(sts, SB);
        ft_op_store_do(sts, PA);
        ft_op_store_do(sts, PA);
        ft_op_store_do(sts, RRB);
        ft_op_store_do(sts, PA);
    }
    else if (ft_arr_order(213, arr, 3))
    {
        ft_op_store_do(sts, RB);
        ft_op_store_do(sts, SB);
        ft_op_store_do(sts, PA);
        ft_op_store_do(sts, RRB);
        ft_op_store_do(sts, PA);
        ft_op_store_do(sts, PA);
    }
    else
        deal3_b_sub2(sts, arr);
}

void            under3_b(t_swstacks *sts, int length)
{
    int         arr[4];

    if (length <= 0)
        return ;
    ft_stack_to_arr(sts->b, arr, length);
    if (length == 3)
        deal3_b_sub(sts, arr);
    else if (length == 2 && arr[1] > arr[0])
    {
        ft_op_store_do(sts, SB);
        ft_op_store_do(sts, PA);
        ft_op_store_do(sts, PA);
    }
    else if (length == 2)
    {
        ft_op_store_do(sts, PA);
        ft_op_store_do(sts, PA);
    }
    else if (length == 1)
        ft_op_store_do(sts, PA);
}
