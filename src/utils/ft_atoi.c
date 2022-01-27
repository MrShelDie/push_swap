/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:34:29 by gannemar          #+#    #+#             */
/*   Updated: 2022/01/19 13:30:03 by gannemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_get_sign(const char **str, int *error)
{
	int	sign;

	sign = 0;
	if (**str == '-')
	{
		(*str)++;
		sign = 1;
	}
	else if (**str == '+')
		(*str)++;
	if (!ft_isdigit(**str))
		*error = ERROR;
	return (sign);
}

static long int	ft_str_to_num(const char **str, int *ndigit, int *error)
{
	long int	num;

	num = 0;
	while (ft_isdigit(**str))
	{
		num = num * 10 + (**str - '0');
		(*ndigit)++;
		(*str)++;
	}
	if (!ft_isdigit(**str) && **str != '\0')
		*error = ERROR;
	return (num);
}

int	ft_atoi(const char *str, int *error)
{
	int			is_neg;
	int			ndigit;
	long int	num;

	num = 0;
	is_neg = 0;
	ndigit = 0;
	is_neg = ft_get_sign(&str, error);
	num = ft_str_to_num(&str, &ndigit, error);
	if (ndigit > 10 || num > (long int)is_neg + INT_MAX)
		*error = ERROR;
	if (*error == ERROR)
		return (0);
	if (is_neg)
		num *= -1;
	return ((int)num);
}
