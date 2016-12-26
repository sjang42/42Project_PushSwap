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

# include "stack.h"
# include "swap_base.h"
# include "./libft/libft.h"
# include "stdio.h"//

t_stack				*ft_get_stack_a(int argc, char *argv[]);
/*
**					add_libft.c
*/
int					ft_isint(long long n);
int					ft_isonly_digit(const char *str);
int					ft_digitcount(int nb);
void				ft_putstr_wd(char *str);
/*
**					???
*/
char				*ft_read_one(void);
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
void				ft_memcheck_operators(t_operators *op);
void				ft_store_operator(t_operators *op, t_sw_operator operator);
t_operators			*ft_operators_new(size_t size);
/*
**					solve_quick.c
*/
t_operators			*sw_solve_quick(t_stack *a, t_stack *b, t_operators *op, int order, int length);
void				ft_op_store_do(t_operators *op, t_sw_operator operator, t_stack *a, t_stack *b);
void				ft_op_store_do_show(t_operators *op, t_sw_operator operator, t_stack *a, t_stack *b);
void				ft_show_operator(t_sw_operator oper);
t_sw_operator		ra_or_rr(t_stack *b, int count_b, int rbm);
t_sw_operator		sa_or_ss(t_stack *b);
/*
**					ftssau_deal.c
*/
int					ft_arr_order(int order, int arr[], size_t size);
void				ftssau_deal_4(t_operators *op, int arr[]);
void				ftssau_deal_4_note(t_operators *op, int arr[]);
void				ftssau_deal_3(t_operators *op, int arr[], t_stack *b, int count_b, int rbm);
void				ftssau_deal_3_note(t_operators *op, int arr[], t_stack *b, int count_b, int rbm);
/*
**					solve_send.c
*/
t_operators			*sw_solve_send(t_stack *a, t_stack *b, t_operators *op);

#endif