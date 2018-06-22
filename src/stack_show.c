/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_show.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 14:03:19 by sjang             #+#    #+#             */
/*   Updated: 2016/12/30 14:03:19 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void     print_a(t_stack *a, int i, int count)
{
    t_stack_node    *cur;

    cur = a->head;
    ft_putstr("    a : ");
    while (cur)
    {
        if (i != 0)
            ft_putstr(", ");
        if ((count + ft_digitcount(cur->data)) > 40)
        {
            count = 42 - count;
            write(1, "                                              ", count);
            write(1, "│\n│         ", 15);
            count = 0;
        }
        count += ft_putnbr_sw(cur->data) + 2;
        cur = cur->next;
        i++;
    }
    if (count)
    {
        count = 44 - count;
        write(1, "                                                  ", count);
        write(1, "│                 ", 9);
    }
}

static void     print_b(t_stack *b, int i, int count)
{
    t_stack_node    *cur;

    cur = b->head;
    ft_putstr("    b : ");
    while (cur)
    {
        if (i != 0)
            ft_putstr(", ");
        if ((count + ft_digitcount(cur->data)) > 40)
        {
            count = 42 - count;
            write(1, "                                              ", count);
            write(1, "│\n│         ", 15);
            count = 0;
        }
        count += ft_putnbr_sw(cur->data) + 2;
        cur = cur->next;
        i++;
    }
    if (count || i == 0)
    {
        count = ((i == 0) ? (42 - count) : (44 - count));
        write(1, "                                                 ", count);
        write(1, "│                 ", 9);
    }
}

void            ft_stack_display_cos(t_stack *a, t_stack *b)
{
    ft_putstr_wd("┌──────────────────────────────────────────────────┐  \n│");
    print_a(a, 0, 0);
    ft_putstr("\n");
    ft_putstr_wd("├──────────────────────────────────────────────────┤  \n│");
    print_b(b, 0, 0);
    ft_putstr("\n");
    ft_putstr_wd("└──────────────────────────────────────────────────┘  \n");
}
