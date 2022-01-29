/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:05:30 by nick              #+#    #+#             */
/*   Updated: 2022/01/29 20:37:32 by nick             ###   ########.fr       */
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
}	t_way;

typedef struct s_way_score
{
	int	ra_rr;
	int	rb_rr;
	int	rra_rrr;
	int	rrb_rrr;
	int	rra_rb;
	int	ra_rrb;
}	t_way_score;

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	long int		value;
	int				min_score;
	int				rb;
	int				rrb;
	int				ra;
	int				rra;
	t_way			way;
}	t_stack;

typedef struct s_prime
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_a_size;
	int		stack_b_size;
}	t_prime;

# define ERROR 0
# define SUCCESS 1

int		ft_isdigit(int c);
int		ft_atoi(const char *str, int *error);
int		ft_bsearch(int value, int *arr, int size);
void	ft_qsort(int *arr, int end_idx);
void	*ft_memcpy(void *dst, const void *src, size_t n);

t_stack	*ft_stack_new(t_stack **stack, int value, int *stack_size);
t_stack	*ft_stack_push(t_stack **stack, int value, int *stack_size);
void	ft_stack_free(t_stack **stack, int *stack_size);
void	ft_stack_pop(t_stack **stack, int *stack_size);
void	ft_stack_swap(t_stack *stack);

int		ft_pa(t_prime *prime);
int		ft_pb(t_prime *prime);
void	ft_ra(t_prime *prime);
void	ft_rb(t_prime *prime);
void	ft_rr(t_prime *prime);
void	ft_rra(t_prime *prime);
void	ft_rrb(t_prime *prime);
void	ft_rrr(t_prime *prime);
void	ft_sa(t_prime *prime);
void	ft_sb(t_prime *prime);

void	ft_ra_rr(t_prime *prime, t_stack *elem);
void	ft_rb_rr(t_prime *prime, t_stack *elem);
void	ft_rra_rrr(t_prime *prime, t_stack *elem);
void	ft_rrb_rrr(t_prime *prime, t_stack *elem);
void	ft_rra_rb(t_prime *prime, t_stack *elem);
void	ft_ra_rrb(t_prime *prime, t_stack *elem);

int		ft_parse(int argc, char **argv, t_prime *prime);

int		ft_sort(t_prime *prime);
void	ft_set_all_score(t_prime *prime);
void	ft_set_all_ways(t_stack *stack_b, int stack_b_size);
int		ft_throw_elem_to_b(t_prime *prime, t_stack *elem);
void	ft_final_sort(t_prime *prime);

void	ft_set_ra_rr_score(t_stack *stack_b, t_way_score *way_score);
void	ft_set_ra_rrb_score(t_stack *stack_b, t_way_score *way_score);
void	ft_set_rb_rr_score(t_stack *stack_b, t_way_score *way_score);
void	ft_set_rra_rb_score(t_stack *stack_b, t_way_score *way_score);
void	ft_set_rra_rrr_score(t_stack *stack_b, t_way_score *way_score);
void	ft_set_rrb_rrr_score(t_stack *stack_b, t_way_score *way_score);

#endif
