/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 23:57:34 by sjang             #+#    #+#             */
/*   Updated: 2016/11/25 23:57:35 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../libft/include/libft.h"

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

typedef struct		s_quick_tool
{
	int future_ra;
	int count_pa;
	int count_pb;
	int count_ra;
	int count_rb;
	int length;
	int pivot;
	int ram;
	int rbm;
	int future_rb;
}					t_quick_tool;
/*
**					check.c
*/
int					ft_check_stack(t_stack *a, t_stack *b);

/*
**					deal_sts.c
*/
t_swstacks			*ft_stsnew(t_swoptions option);
/*
**					fill_stack.c
*/
void				ft_get_stack_a(int argc, char *argv[], t_swstacks *sts);
/*
**					ft_op_store.c
*/
void				ft_store_operator(
					t_operators *op, t_sw_operator operator);
void				ft_op_store_do(
					t_operators *op, t_sw_operator operator,
					t_stack *a, t_stack *b);
void				ft_op_store_do_show(
					t_operators *op, t_sw_operator operator,
					t_stack *a, t_stack *b);
/*
**					ft_operators.c
*/
t_operators			*ft_operators_new(size_t size);
void				ft_show_operator(t_sw_operator oper);
int					ft_display_operators(t_operators *op);
/*
**					ft_quicksort.c
*/
void				ft_quicksort(int arr[], int left, int right);
/*
**					get_operators.c
*/
t_operators			*ft_get_operators(t_swstacks *sts, t_swoptions option);
/*
**					option.c
*/
t_swoptions			ft_get_swoption(char *str);
/*
**					solve_quick_btoa.c
*/
void				solve_quick_btoa(t_swstacks *sts, int length, int rpb);
/*
**					solve_quick_atob.c
*/
void				solve_quick_atob(t_swstacks *sts, int length, int rpb);
/*
**					solve_quick_sub.c
*/
int					ft_get_pivot(t_stack *a, int length);
int					ft_get_rbm(t_stack *a, int length);
int					ft_get_ram(t_stack *b, int length);
/*
**					solve_quick_sub2.c
*/
int					rb_or_rr(t_swstacks *sts, t_quick_tool *tool);
t_sw_operator		ra_or_rr(t_swstacks *sts, t_quick_tool *tool);
/*
**					solve_quick_sub3.c
*/
int					ft_rpb(t_swstacks *sts, t_quick_tool *tool);
int					ft_rpa(t_swstacks *sts, t_quick_tool *tool);
/*
**					stack_show.c
*/
void				ft_stack_display_cos(t_stack *a, t_stack *b);
/*
**					stack_show_sub.c
*/
int					ft_putnbr_sw(int nb);
void				ft_putstr_wd(char *str);
/*
**					stack_sw.c
*/
t_sdata				ft_stack_least(t_stack *pstack);
t_sdata				ft_stack_most(t_stack *pstack);
void				ft_stack_display(t_stack *pstack);
int					ft_stack_where_data(t_stack *ps, t_sdata q);
int					ft_stack_last(t_stack *ps);
/*
**					sw_destroy.c
*/
void				ft_destroy_operators(t_operators **op);
void				ft_destroy_sts(t_swstacks *sts);
void				ft_destroy_sts_exit(t_swstacks *sts);
/*
**					swap_operations.c
*/
int					sw_operate(
					t_stack *a, t_stack *b, t_sw_operator op);
void				ft_calculate(
					t_stack *a, t_stack *b, t_operators *op);
void				ft_calculate_show(
					t_stack *a, t_stack *b, t_operators *op);
/*
**					swap_operations_sub.c
*/
int					sw_swap(t_stack *pstack);
int					sw_push(t_stack *srcp, t_stack *destp);
int					sw_rotate(t_stack *pstack);
int					sw_rotate_rev(t_stack *pstack);
/*
**					under3_a.c
*/
void				under3_a(t_swstacks *sts, int length);
/*
**					under3_b.c
*/
void				under3_b(t_swstacks *sts, int length);
/*
**					under3_sub.c
*/
int					ft_arr_order(int order, int arr[], int size);
void				ft_stack_to_arr(t_stack *ps, int arr[], int size);
t_sw_operator		sa_or_ss(t_stack *b);
/*
**					usage.c
*/
void				ft_show_usage(void);
void				ft_show_usage_ps(void);
#endif
