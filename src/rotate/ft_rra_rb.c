/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:09:06 by nick              #+#    #+#             */
/*   Updated: 2022/01/31 02:51:51 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra_rb(t_prime *prime, t_stack *elem)
{
	while (elem->rra-- > 0)
		ft_rra(prime, TRUE);
	while (elem->rb-- > 0)
		ft_rb(prime, TRUE);
}
