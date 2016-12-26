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

#include "main.h"

t_sw_operator	ft_decide_operator(char *line)
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

t_operators		*ft_get_operators_cos(t_stack *a, t_stack *b)
{
	int				i;
	int				err;
	char			*line;

	t_operators		*op;
	t_sw_operator	*tmp;

	i = 0;
	op = (t_operators*)malloc(sizeof(t_operators));
	op->size = 10;
	op->operators = (t_sw_operator*)malloc(sizeof(t_sw_operator) * op->size);
	ft_stack_display_cos(a, b);
	while ((line = ft_read_one()))
	{
		if (i == op->size)
		{
			op->operators = (t_sw_operator*)ft_realloc(op->operators,
							sizeof(t_sw_operator) * op->size,
							sizeof(t_sw_operator) * (op->size + 10));
			op->size += 10;
		}
		(op->operators)[i] = ft_decide_operator(line);
		free(line);
		if ((op->operators)[i] == 0)
		{
			ft_destroy_operators(&op);
			ft_exit_error("Wrong operator");
		}
		sw_operate(a, b, (op->operators)[i]);
		ft_stack_display_cos(a, b);
		i++;
	}
	op->operators = (t_sw_operator*)ft_realloc(op->operators,
					sizeof(t_sw_operator) * op->size,
					sizeof(t_sw_operator) * i);
	op->size = i;
	return (op);
}

// t_operators		*ft_get_operators(void)
// {
// 	int				i;
// 	int				err;
// 	char			*line;
// 	t_operators		*op;

// 	i = 0;
// 	op = (t_operators*)malloc(sizeof(t_operators));
// 	op->size = 10;
// 	op->operators = (t_sw_operator*)malloc(sizeof(t_sw_operator) * op->size);
// 	while ((err = get_next_line(0, &line)))
// 	{
// 		if (i == op->size)
// 		{
// 			op->operators = (t_sw_operator*)realloc(op->operators,
// 							sizeof(t_sw_operator) * (op->size + 10));
// 			// op->operators = (t_sw_operator*)ft_realloc(op->operators,
// 			// 				sizeof(t_sw_operator) * op->size,
// 			// 				sizeof(t_sw_operator) * (op->size + 10));
// 			op->size += 10;
// 		}
// 		(op->operators)[i] = ft_decide_operator(line);
// 		free(line);
// 		if ((op->operators)[i] == 0)
// 		{
// 			ft_destroy_operators(&op);
// 			ft_exit_error("Wrong operator");
// 		}
// 		i++;
// 	}
// 	op->operators = (t_sw_operator*)realloc(op->operators, sizeof(t_sw_operator) * i);

// 	// op->operators = (t_sw_operator*)ft_realloc(op->operators,
// 	// 				sizeof(t_sw_operator) * op->size,
// 	// 				sizeof(t_sw_operator) * i);
// 	// op->size = i;
// 	return (op);
// }

int				ft_display_operators(t_operators *op)
{
	size_t i;

	i = 0;
	while (i < op->idx)
	{
		if ((op->operators)[i] == SA)
			ft_putstr("sa");
		else if ((op->operators)[i] == SB)
			ft_putstr("sb");
		else if ((op->operators)[i] == SS)
			ft_putstr("ss");
		else if ((op->operators)[i] == PA)
			ft_putstr("pa");
		else if ((op->operators)[i] == PB)
			ft_putstr("pb");
		else if ((op->operators)[i] == RA)
			ft_putstr("ra");
		else if ((op->operators)[i] == RB)
			ft_putstr("rb");
		else if ((op->operators)[i] == RR)
			ft_putstr("rr");
		else if ((op->operators)[i] == RRA)
			ft_putstr("rra");
		else if ((op->operators)[i] == RRB)
			ft_putstr("rrb");
		else if ((op->operators)[i] == RRR)
			ft_putstr("rrr");
		else
		{
			printf("%d\n", (op->operators)[i]);
			ft_putstr("what the fuck");
		}
		ft_putstr("\n");
		i++;
	}
	return (i);
}

void			ft_destroy_operators(t_operators **op)
{
	free((*op)->operators);
	free(*op);
	*op = NULL;
}
