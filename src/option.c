/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 18:20:55 by sjang             #+#    #+#             */
/*   Updated: 2016/12/26 18:20:57 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

t_swoptions ft_get_swoption(char *str)
{
	t_swoptions	ret;

	ret = NOTHING;
	if (!ft_strcmp("-s", str))
		ret |= OP_DISPLAY;
	if (!ft_strcmp("-m", str))
		ret |= OP_SIZE_OPER;
	return (ret);
}
