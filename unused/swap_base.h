/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_base.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 23:23:51 by sjang             #+#    #+#             */
/*   Updated: 2016/11/25 23:23:52 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_BASE_H
# define SWAP_BASE_H

# include "../libft/include/stack.h"

typedef enum		e_sw_operator
{
	SA = 1,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}					t_sw_operator;

typedef struct		s_operators
{
	int				size;
	int				idx;
	t_sw_operator	*operators;
}					t_operators;

typedef enum		e_swoptions
{
	NOTHING = 0,
	OP_DISPLAY = 1,
	OP_SIZE_OPER = 2,
}					t_swoptions;

typedef struct		s_swstacks
{
	t_stack		*a;
	t_stack		*b;
	t_operators	*op;
	t_swoptions	option;
}					t_swstacks;

/*
**					swap_operations_sub.c
*/
int					sw_swap(t_stack *pstack);
int					sw_push(t_stack *srcp, t_stack *destp);
int					sw_rotate(t_stack *pstack);
int					sw_rotate_rev(t_stack *pstack);
void				ft_stack_display(t_stack *pstack);
/*
**					swap_operations.c
*/
int					sw_calculator(t_stack *a, t_stack *b, t_sw_operator op);
int					sw_operate(t_stack *a, t_stack *b, t_sw_operator op);
void				ft_calculate(t_stack *a, t_stack *b, t_operators *op);
void				ft_calculate_show(t_stack *a, t_stack *b, t_operators *op);
/*
**					check.c
*/
int					ft_stack_issort(t_stack *pstack);
int					ft_check_stack(t_stack *a, t_stack *b);
/*
**					get_operators.c
*/
t_operators			*ft_get_operators(t_swstacks *sts, t_swoptions option);
int					ft_display_operators(t_operators *op);
/*
**					sw_solve.c
*/
void				ft_calculate_ij(t_stack *a, t_stack *b, t_operators *op, int i[]);
t_operators			*sw_solve(t_stack *a, t_stack *b);
/*
**					stack_sw.c
*/
t_sdata				ft_stack_least(t_stack *pstack);
t_sdata				ft_stack_most(t_stack *pstack);
void				ft_stack_display(t_stack *pstack);
void				ft_stack_display_cos(t_stack *a, t_stack *b);
int					ft_stack_where_data(t_stack *ps, t_sdata q);
/*
**					sw_destroy.c
*/
void				ft_destroy_operators(t_operators **op);
void				ft_destroy_sts(t_swstacks *sts);
void				ft_destroy_sts_exit(t_swstacks *sts);

#endif