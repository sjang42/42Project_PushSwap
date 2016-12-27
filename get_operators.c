/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 03:48:34 by sjang             #+#    #+#             */
/*   Updated: 2016/11/26 03:48:35 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void				ft_read_rest(void)
{
	char	buf[300];
	int		i;

	i = 0;
	while (read(0, buf, 300))
	{
		i = 0;
		while (i < 300)
		{
			if (buf[i] == '\n')
				return ;
			i++;
		}
	}
}

static char				*ft_read_one(t_stack *a, t_stack *b,
									t_operators *op)
{
	char	arr[4];
	char	*ret;
	int		size;

	ft_bzero(arr, 4);
	size = read(0, arr, 3);
	if (size == 0)
		return (NULL);
	else if (size == 1)
	{
		ft_destroy_operators(&op);
		ft_stack_destroy(&a);
		ft_stack_destroy(&b);
		ft_exit_error("Wrong operator");
	}
	if (size != 2 && arr[2] != '\n')
	{
		size = read(0, arr + 3, 1);
		if (size != 0 && arr[3] != '\n')
		{
			ft_destroy_operators(&op);
			ft_stack_destroy(&a);
			ft_stack_destroy(&b);
			ft_read_rest();
			ft_exit_error("Wrong operator");
		}
		arr[3] = 0;
	}
	else
		arr[2] = 0;
	ret = ft_strdup(arr);
	return (ret);
}

static t_sw_operator	ft_decide_operator(char *line)
{
	if (!line)
		return (0);
	if (!ft_strcmp(line, "sa"))
		return (SA);
	else if (!ft_strcmp(line, "sb"))
		return (SB);
	else if (!ft_strcmp(line, "ss"))
		return (SS);
	else if (!ft_strcmp(line, "pa"))
		return (PA);
	else if (!ft_strcmp(line, "pb"))
		return (PB);
	else if (!ft_strcmp(line, "ra"))
		return (RA);
	else if (!ft_strcmp(line, "rb"))
		return (RB);
	else if (!ft_strcmp(line, "rr"))
		return (RR);
	else if (!ft_strcmp(line, "rra"))
		return (RRA);
	else if (!ft_strcmp(line, "rrb"))
		return (RRB);
	else if (!ft_strcmp(line, "rrr"))
		return (RRR);
	return (0);
}

t_operators				*ft_get_operators(t_stack *a, t_stack *b,
											t_swoptions option)
{
	char			*line;
	t_operators		*op;
	t_sw_operator	oper;

	op = ft_operators_new(100);
	if (option & CHECKER_SHOW_OP)
		ft_stack_display_cos(a, b);
	while ((line = ft_read_one(a, b, op)))
	{
		oper = ft_decide_operator(line);
		if (!oper)
		{
			ft_destroy_operators(&op);
			ft_stack_destroy(&a);
			ft_stack_destroy(&b);
			ft_exit_error("Wrong Operator");
		}
		if (option & CHECKER_SHOW_OP)
			ft_op_store_do_show_ch(op, oper, a, b);
		else
			ft_op_store_do(op, oper, a, b);
		free(line);
	}
	return (op);
}
