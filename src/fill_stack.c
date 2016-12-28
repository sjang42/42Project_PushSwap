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

void		ft_deal_arg(t_stack *a, char *argv[], int start)
{
	long long	n;
	char		**str;
	int			i;

	i = 0;
	str = ft_strsplit(argv[start + 1], ' ');
	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		n = ft_atoll(str[i]);
		if (!ft_isonly_digit(str[i]) || !ft_isint(n) ||
			ft_stack_where_data(a, n))
			ft_exit_error("Error");
		ft_stack_push(a, (int)n);
		i--;
	}
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

t_stack		*ft_get_stack_a(int argc, char *argv[], t_swoptions	option)
{
	int			i;
	long long	n;
	t_stack		*a;
	int			start;

	start = (option == NOTHING) ? 0 : 1;
	a = ft_stack_new();
	if (argc - start == 2 && !ft_isonly_digit(argv[start + 1]))
	{
		ft_deal_arg(a, argv, start);
		return (a);
	}
	i = argc - 1;
	while (i > start)
	{
		n = ft_atoll(argv[i]);
		if (!ft_isonly_digit(argv[i]) || !ft_isint(n))
			ft_exit_error("One or more input is not an int");
		if (ft_stack_where_data(a, n))
			ft_exit_error("One number used twice or more");
		ft_stack_push(a, (int)n);
		i--;
	}
	return (a);
}
