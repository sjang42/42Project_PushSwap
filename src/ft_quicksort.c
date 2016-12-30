/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 19:53:56 by sjang             #+#    #+#             */
/*   Updated: 2016/12/20 19:53:57 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		qs_swap(int arr[], int idx1, int idx2)
{
	int tmp;

	tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
}

static int		ft_get_pivot(int arr[], int left, int right)
{
	int mid;

	mid = (left + right) / 2;
	if (arr[left] >= arr[right])
	{
		if (arr[left] >= arr[mid])
			return ((arr[mid] >= arr[right]) ? mid : right);
		else
			return (left);
	}
	else
	{
		if (arr[right] >= arr[mid])
			return ((arr[mid] >= arr[left]) ? mid : left);
		else
			return (right);
	}
}

static int		qs_partition(int arr[], int left, int right)
{
	int pivot;
	int low;
	int high;

	pivot = ft_get_pivot(arr, left, right);
	if (pivot != left)
		qs_swap(arr, pivot, left);
	pivot = left;
	low = left + 1;
	high = right;
	while (low <= high)
	{
		while (arr[pivot] >= arr[low] && low <= right)
			low++;
		while (arr[pivot] < arr[high] && high >= left)
			high--;
		if (low < high)
			qs_swap(arr, low, high);
	}
	qs_swap(arr, pivot, high);
	return (high);
}

void			ft_quicksort(int arr[], int left, int right)
{
	int pivot;

	if (left >= right)
		return ;
	pivot = qs_partition(arr, left, right);
	ft_quicksort(arr, left, pivot - 1);
	ft_quicksort(arr, pivot + 1, right);
}
