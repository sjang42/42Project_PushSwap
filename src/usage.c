/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 18:14:36 by sjang             #+#    #+#             */
/*   Updated: 2016/12/26 18:14:37 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void        ft_show_usage(void)
{
    ft_putstr("Usage    :   ./checker [-option] num1 num2 num3 ...\n");
    ft_putstr("or       ./checker [-option] \"num1 num2 num3 ...\"\n");
    ft_putstr("or       ./checker [-f] \"filename\"\n");
    ft_putstr("Option   :   -s -c -m\n");
}

void        ft_show_usage_ps(void)
{
    ft_putstr("Usage    : ./push_swap [-option] num1 num2 num3 ...\n");
    ft_putstr("Option   : -s\n");
}
