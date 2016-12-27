/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unused.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 16:12:12 by sjang             #+#    #+#             */
/*   Updated: 2016/12/26 16:12:14 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

