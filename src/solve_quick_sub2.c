/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quick_sub2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 16:10:40 by sjang             #+#    #+#             */
/*   Updated: 2016/12/29 16:10:41 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int             rb_or_rr(t_swstacks *sts, t_quick_tool *tool)
{
    if (ft_stack_peek(sts->a) < tool->ram &&
        tool->count_ra < tool->future_rb &&
        ft_stack_size(sts->b) != tool->length - tool->count_pa)
        return (RR);
    else
        return (RB);
}

t_sw_operator   ra_or_rr(t_swstacks *sts, t_quick_tool *tool)
{
    if (ft_stack_size(sts->b) <= 1)
        return (RA);
    if (ft_stack_size(sts->b) == tool->count_pb)
    {
        if (ft_stack_peek(sts->b) < tool->rbm)
            return (RR);
        else
            return (RA);
    }
    else if (tool->count_rb < tool->future_ra)
    {
        if (ft_stack_peek(sts->b) > tool->rbm)
            return (RR);
        else
            return (RA);
    }
    return (RA);
}
