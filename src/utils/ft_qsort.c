/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:14:57 by gannemar          #+#    #+#             */
/*   Updated: 2022/01/20 20:39:05 by gannemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_qsort(int *arr, int end_idx)
{
	int	size;
	int	start_iter;
	int	median;

	size = end_idx;
	start_iter = 0;
	median = arr[end_idx / 2];
	while (start_iter <= end_idx)
	{
		while (arr[start_iter] < median)
			start_iter++;
		while (arr[end_idx] > median)
			end_idx--;
		if (start_iter <= end_idx)
		{
			ft_swap(arr + start_iter, arr + end_idx);
			start_iter++;
			end_idx--;
		}
	}
	if (end_idx > 0)
		ft_qsort(arr, end_idx);
	if (start_iter < size)
		ft_qsort(arr + start_iter, size - start_iter);
}
