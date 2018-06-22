/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under3_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 13:53:39 by sjang             #+#    #+#             */
/*   Updated: 2016/12/30 13:53:40 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void     ft_copy_arr(int dest[], int src[], int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        dest[i] = src[i];
        i++;
    }
}

int             ft_arr_order(int order, int arr[], int size)
{
    int copy_arr[10];
    int order_4[4];

    ft_copy_arr(copy_arr, arr, size);
    ft_quicksort(copy_arr, 0, size - 1);
    order_4[0] = order % 10;
    order_4[1] = order % 100 / 10;
    order_4[2] = order % 1000 / 100;
    order_4[3] = order / 1000;
    if (size == 4 &&
        arr[3] == copy_arr[order_4[0] - 1] &&
        arr[2] == copy_arr[order_4[1] - 1] &&
        arr[1] == copy_arr[order_4[2] - 1] &&
        arr[0] == copy_arr[order_4[3] - 1])
        return (1);
    else if (size == 3 &&
        arr[2] == copy_arr[order_4[0] - 1] &&
        arr[1] == copy_arr[order_4[1] - 1] &&
        arr[0] == copy_arr[order_4[2] - 1])
        return (1);
    else
        return (0);
}

void            ft_stack_to_arr(t_stack *ps, int arr[], int size)
{
    t_stack_node    *cur;
    int             count;
    int             i;

    count = ft_stack_size(ps);
    if (count < 0)
        return ;
    i = 0;
    cur = ps->head;
    while (i < count && i < size)
    {
        arr[i++] = cur->data;
        cur = cur->next;
    }
}

t_sw_operator   sa_or_ss(t_stack *b)
{
    t_stack_node    *cur;

    if (ft_stack_size(b) <= 1)
        return (SA);
    cur = b->head;
    if (cur->data < cur->next->data)
        return (SS);
    else
        return (SA);
}
