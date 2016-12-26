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

#include "main.h"

void			ftssau_deal_4(t_operators *op, int arr[])
{
	if (ft_arr_order(1234 ,arr, 4))
		;
	else if (ft_arr_order(1243 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(1324 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(1423 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
	}

	else if (ft_arr_order(1342 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(1432 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}

	else if (ft_arr_order(2134 ,arr, 4))
	{
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(2143 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(2314 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(2413 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}

	else if (ft_arr_order(2341 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(2431 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(3214 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(3241 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	 	ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	 	ft_store_operator(op, SA);
	}

	else if (ft_arr_order(3124 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(3421 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, PB);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	 	ft_store_operator(op, SA);
		ft_store_operator(op, PA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(3142 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}

	else if (ft_arr_order(3412 ,arr, 4))
	{

		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, PB);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, PA);
	}

	else if (ft_arr_order(4213 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, PB);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, PA);
	}
	else if (ft_arr_order(4231 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(4123 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(4321 ,arr, 4))
	{
	
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, PB);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, PA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(4132 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(4312 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, PB);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, PA);
	}
}

void			ftssau_deal_4_note(t_operators *op, int arr[])
{
	if (ft_arr_order(1234 ,arr, 4))
		;
	else if (ft_arr_order(1243 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(1324 ,arr, 4))
	{

		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(1423 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
	}

	else if (ft_arr_order(1342 ,arr, 4))
	{
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(1432 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}

	else if (ft_arr_order(2134 ,arr, 4))
	{
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(2143 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(2314 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(2413 ,arr, 4))
	{
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}

	else if (ft_arr_order(2341 ,arr, 4))
	{
		ft_store_operator(op, RRA);
	}
	else if (ft_arr_order(2413 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
	}
	
	else if (ft_arr_order(3214 ,arr, 4))
	{
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(3241 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
	}

	else if (ft_arr_order(3124 ,arr, 4))
	{
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, RA);
	}
	else if (ft_arr_order(3421 ,arr, 4))
	{
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);

	}
	else if (ft_arr_order(3142 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}

	else if (ft_arr_order(3412 ,arr, 4))
	{
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
	}

	else if (ft_arr_order(4213 ,arr, 4))
	{
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(4231 ,arr, 4))
	{
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
	}
	else if (ft_arr_order(4123 ,arr, 4))
	{
		ft_store_operator(op, RA);
	}
	else if (ft_arr_order(4321 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(4132 ,arr, 4))
	{
		ft_store_operator(op, RRA);
		ft_store_operator(op, SA);
		ft_store_operator(op, RA);
		ft_store_operator(op, SA);
	}
	else if (ft_arr_order(4312 ,arr, 4))
	{
		ft_store_operator(op, SA);
		ft_store_operator(op, RRA);
		ft_store_operator(op, RRA);
	}
}

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


// void		ftssau_deal_3(t_operators *op, int arr[],
// 							t_stack *b, int count_b)
// {
// 	if (arr[2] >= arr[1])
// 		{
// 			if (arr[1] >= arr[0])
// 				;
// 			else if (arr[2] >= arr[0])		//bac
// 				ft_store_operator(op, sa_or_ss(b));
// 			else							//cab
// 			{
// 				ft_store_operator(op, sa_or_ss(b));
// 				ft_store_operator(op, ra_or_rr(b, count_b, rbm));
// 				ft_store_operator(op, sa_or_ss(b));
// 				ft_store_operator(op, RRA);
// 			}
// 		}
// 		else
// 		{
// 			if (arr[2] >= arr[0])			//acbDD
// 			{
// 				ft_store_operator(op, ra_or_rr(b, count_b, rbm));
// 				ft_store_operator(op, sa_or_ss(b));
// 				ft_store_operator(op, RRA);
// 			}
// 			else if (arr[1] >= arr[0])		//bcaDD
// 			{
// 				ft_store_operator(op, ra_or_rr(b, count_b, rbm));
// 				ft_store_operator(op, sa_or_ss(b));
// 				ft_store_operator(op, RRA);
// 				ft_store_operator(op, sa_or_ss(b));
// 			}
// 			else						//cbaDD
// 			{
// 				ft_store_operator(op, sa_or_ss(b));
// 				ft_store_operator(op, ra_or_rr(b, count_b, rbm));
// 				ft_store_operator(op, sa_or_ss(b));
// 				ft_store_operator(op, RRA);
// 				ft_store_operator(op, sa_or_ss(b));
// 			}
// 		}



// }