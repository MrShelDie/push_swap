/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:57:42 by nick              #+#    #+#             */
/*   Updated: 2022/01/31 02:51:15 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb_rr(t_prime *prime, t_stack *elem)
{
	while (elem->ra > 0)
	{
		ft_rr(prime, TRUE);
		elem->ra--;
		elem->rb--;
	}
	while (elem->rb-- > 0)
		ft_rb(prime, TRUE);
}
