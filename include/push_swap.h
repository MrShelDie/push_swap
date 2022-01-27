/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:05:30 by nick              #+#    #+#             */
/*   Updated: 2022/01/28 00:45:54 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef enum e_push_way
{
	RA_RR,
	RB_RR,
	RRA_RRR,
	RRB_RRR,
	RRA_RB,
	RA_RRB,
	NONE
}	t_push_way;

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	long int		value;
	int				rb_score;
	int				rrb_score;
	int				ra_score;
	int				rra_score;
	t_push_way		push_way;
}	t_stack;

typedef struct s_prime
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_prime;

# define ERROR 0
# define SUCCESS 1

int		ft_isdigit(int c);
int		ft_atoi(const char *str, int *error);
int		ft_bsearch(int value, int *arr, int size);
void	ft_qsort(int *arr, int end_idx);
void	*ft_memcpy(void *dst, const void *src, size_t n);

t_stack	*ft_stack_new(t_stack **stack, int value);
t_stack	*ft_stack_push(t_stack **stack, int value);
void	ft_stack_free(t_stack **stack);
void	ft_stack_pop(t_stack **stack);
void	ft_stack_swap(t_stack *stack);

int		ft_parse(int argc, char **argv, t_prime *prime);

#endif
