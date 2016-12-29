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
# include "swap_base.h"
# include <stdio.h>//

// typedef struct		s_quick_tool
// {
// 	int count_p;
// 	int count_r;
// 	int length;
// 	int rbm;
// }					t_quick_tool;


void				ft_get_stack_a(int argc, char *argv[], t_swstacks *sts);
/*
**					add_libft.c
*/
int					ft_isint(long long n);
int					ft_isonly_digit(const char *str);
int					ft_digitcount(int nb);
void				ft_putstr_wd(char *str);
/*
**					sw_solve_min.c
*/
void				ft_calculate_ij(t_stack *a, t_stack *b, t_operators *op, int i[]);
t_operators			*sw_solve(t_stack *a, t_stack *b);
/*
**					ft_quicksort.c
*/
void				ft_quicksort(int arr[], int left, int right);
/*
**					ft_operators.c
*/
void				ft_store_operator(t_operators *op, t_sw_operator operator);
void				ft_op_store_do(t_operators *op, t_sw_operator operator, t_stack *a, t_stack *b);
void				ft_op_store_do_show(t_operators *op, t_sw_operator operator, t_stack *a, t_stack *b);
void				ft_op_store_do_show_ch(t_operators *op, t_sw_operator operator, t_stack *a, t_stack *b);
t_operators			*ft_operators_new(size_t size);
void				ft_show_operator(t_sw_operator oper);

/*
**					solve_quick.c
*/
// t_operators			*sw_solve_quick(t_swstacks *sts, int order, int length);
void				solve_quick_atob(t_swstacks *sts, int length);
void				solve_quick_btoa(t_swstacks *sts, int length);
/*
**					solve_quick_sub.c
*/
int					ft_get_pivot(t_stack *a, size_t length);
int					ft_get_rbm(t_stack *a, size_t length);
t_sw_operator		ra_or_rr(t_stack *b, int count_b, int rbm);
int					ft_rpb(t_swstacks *sts,	int count_b, int rbm);

// void				ft_rpb(t_swstacks *sts,	int count_b, int rbm);

/*
**					ftssau_deal.c
*/
int					ft_arr_order(int order, int arr[], int size);
void				ftssau_deal_4(t_operators *op, int arr[]);
void				ftssau_deal_4_note(t_operators *op, int arr[]);
void				ftssau_deal_3(t_operators *op, int arr[], t_stack *b, int count_b, int rbm);
void				ftssau_deal_3_note(t_operators *op, int arr[], t_stack *b, int count_b, int rbm);
/*
**					solve_send.c
*/
t_operators			*sw_solve_send(t_stack *a, t_stack *b, t_operators *op);
/*
**					option.c
*/
t_swoptions			ft_get_swoption(char *str);
/*
**					usage.c
*/
void				ft_show_usage(void);
void				ft_show_usage_ps(void);

/*
**					under3_a.c, under3_b.c
*/
void				ft_stack_to_arr(t_stack *ps, int arr[], int size);
void				under3_a(t_swstacks *sts, int length);
void				under3_b(t_swstacks *sts, int length);
/*
**					deal_sts.c
*/
t_swstacks			*ft_stsnew(t_swoptions option);

#endif