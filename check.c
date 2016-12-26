/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 01:15:37 by sjang             #+#    #+#             */
/*   Updated: 2016/11/26 01:15:38 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

int		ft_check_stack(t_stack *a, t_stack *b)
{
	if (ft_stack_isempty(b) && ft_stack_issort(a))
	{
		ft_putstr("OK\n");
		return (1);
	}
	else
	{
		ft_putstr("KO\n");
		return (0);
	}
}
