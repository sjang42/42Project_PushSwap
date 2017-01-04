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

int				ft_get_swoption_sub(char *str, t_swoptions *ret)
{
	int count;

	count = 0;
	if (ft_strstr(str, "s"))
	{
		*ret |= OP_DISPLAY;
		count++;
	}
	if (ft_strstr(str, "m"))
	{
		*ret |= OP_SIZE_OPER;
		count++;
	}
	if (ft_strstr(str, "c"))
	{
		*ret |= OP_COLOR;
		*ret |= OP_DISPLAY;
		count++;
	}
	if (ft_strstr(str, "f"))
	{
		*ret |= OP_FILE;
		count++;
	}
	return (count);
}

t_swoptions		ft_get_swoption(char *str)
{
	t_swoptions	ret;
	int			count;

	ret = NOTHING;
	count = 1;
	if (!str || str[0] != '-')
		return (ret);
	count += ft_get_swoption_sub(str, &ret);
	if ((int)ft_strlen(str) != count)
		ft_exit_error(NULL);
	return (ret);
}

t_swoptions		get_option(int argc, char *argv[])
{
	t_swoptions	ret;

	ret = ft_get_swoption(argv[1]);
	if (ret != NOTHING && argc == 2)
	{
		ft_show_usage();
		ft_exit_error(NULL);
	}
	return (ret);
}
