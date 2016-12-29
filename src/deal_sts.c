/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_sts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 10:55:27 by sjang             #+#    #+#             */
/*   Updated: 2016/12/29 10:55:27 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

t_swstacks	*ft_stsnew(t_swoptions option)
{
	t_swstacks		*sts;

	sts = (t_swstacks*)malloc(sizeof(t_swstacks));
	sts->a = ft_stack_new();
	sts->b = ft_stack_new();
	sts->op = ft_operators_new(100);
	sts->option = option;
	return (sts);
}
