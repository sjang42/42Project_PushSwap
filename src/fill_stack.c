/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 02:45:40 by sjang             #+#    #+#             */
/*   Updated: 2016/11/26 02:45:40 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void		destroy_split_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str[i]);
	free(str);
}

static void		push_to_a(t_swstacks *sts, char **str)
{
	int			i;
	long long	n;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		n = ft_atoll(str[i]);
		if (!ft_isonly_digit(str[i]) ||
			!ft_isint(n) ||
			ft_stack_where_data(sts->a, n))
		{
			if (ft_stack_where_data(sts->a, n))
			{
				destroy_split_str(str);
				ft_destroy_sts_exit(sts);
			}
		}
		ft_stack_push(sts->a, (int)n);
		i--;
	}
}

static void		ft_deal_arg(t_swstacks *sts, char *argv[], int start)
{
	char		**str;

	str = ft_strsplit(argv[start + 1], ' ');
	if (!str)
		ft_destroy_sts_exit(sts);
	push_to_a(sts, str);
	destroy_split_str(str);
}

void			ft_get_stack_a(int argc, char *argv[], t_swstacks *sts)
{
	int			i;
	long long	n;
	int			start;

	start = (sts->option == NOTHING) ? 0 : 1;
	if (argc - start == 2 && !ft_isonly_digit(argv[start + 1]))
	{
		ft_deal_arg(sts, argv, start);
		return ;
	}
	i = argc - 1;
	while (i > start)
	{
		n = ft_atoll(argv[i]);
		if (!ft_isonly_digit(argv[i]) || !ft_isint(n) ||
			ft_stack_where_data(sts->a, n))
			ft_destroy_sts_exit(sts);
		ft_stack_push(sts->a, (int)n);
		i--;
	}
}
