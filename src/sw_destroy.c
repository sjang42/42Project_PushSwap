/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 10:21:53 by sjang             #+#    #+#             */
/*   Updated: 2016/12/29 10:21:54 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void            ft_destroy_operators(t_operators **op)
{
    free((*op)->operators);
    free(*op);
    *op = NULL;
}

void            ft_destroy_sts(t_swstacks *sts)
{
    ft_stack_destroy(&(sts->a));
    ft_stack_destroy(&(sts->b));
    ft_destroy_operators(&(sts->op));
    free(sts);
}

void            ft_destroy_sts_exit(t_swstacks *sts)
{
    ft_destroy_sts(sts);
    ft_exit_error(NULL);
}
