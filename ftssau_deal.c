/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftssau_deal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:46:19 by sjang             #+#    #+#             */
/*   Updated: 2016/12/23 17:46:20 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"


void		ftssau_deal_3(t_operators *op, int arr[],
							t_stack *b, int count_b, int rbm)
{
	if (ft_arr_order(213, arr, 3))
		ft_store_operator(op, sa_or_ss(b));
	else if (ft_arr_order(312, arr, 3))
	{
		ft_store_operator(op, sa_or_ss(b));
		ft_store_operator(op, ra_or_rr(b, count_b, rbm));
		ft_store_operator(op, sa_or_ss(b));
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(132, arr, 3))
	{
		ft_store_operator(op, ra_or_rr(b, count_b, rbm));
		ft_store_operator(op, sa_or_ss(b));
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(231, arr, 3))
	{
		ft_store_operator(op, ra_or_rr(b, count_b, rbm));
		ft_store_operator(op, sa_or_ss(b));
		ft_store_operator(op, RRA);
		ft_store_operator(op, sa_or_ss(b));
	}
	else if (ft_arr_order(321, arr, 3))
	{
		ft_store_operator(op, sa_or_ss(b));
		ft_store_operator(op, ra_or_rr(b, count_b, rbm));
		ft_store_operator(op, sa_or_ss(b));
		ft_store_operator(op, RRA);
		ft_store_operator(op, sa_or_ss(b));
	}
}

void		ftssau_deal_3_note(t_operators *op, int arr[],
							t_stack *b, int count_b, int rbm)
{
	if (ft_arr_order(213, arr, 3))
		ft_store_operator(op, sa_or_ss(b));
	else if (ft_arr_order(312, arr, 3))
		ft_store_operator(op, ra_or_rr(b, count_b, rbm));
	else if (ft_arr_order(132, arr, 3))
	{
		ft_store_operator(op, sa_or_ss(b));
		ft_store_operator(op, ra_or_rr(b, count_b, rbm));
	}
	else if (ft_arr_order(231, arr, 3))
		ft_store_operator(op, RRA);
	else if (ft_arr_order(321, arr, 3))
	{
		ft_store_operator(op, ra_or_rr(b, count_b, rbm));
		ft_store_operator(op, sa_or_ss(b));
	}
}
