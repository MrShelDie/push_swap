/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsearch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:23:28 by gannemar          #+#    #+#             */
/*   Updated: 2022/01/20 19:23:30 by gannemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_bsearch(int value, int *arr, int size)
{
	int	start;
	int	end;
	int	mid;

	start = 0;
	end = size - 1;
	while (start <= end)
	{
		mid = (end + start) / 2;
		if (arr[mid] == value)
			return (mid);
		if (value < arr[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return (-1);
}
