/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:05:30 by nick              #+#    #+#             */
/*   Updated: 2022/01/30 21:02:11 by gannemar         ###   ########.fr       */
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

typedef struct s_arg_tab
{
	char	**argv;
	int		argc;
	int		*ordered;
	int		*unordered;
}	t_arg_tab;

# define ERROR 0
# define SUCCESS 1

# define FALSE 0
# define TRUE 1

int		ft_isdigit(int c);
int		ft_atoi(const char *str, int *error);
int		ft_bsearch(int value, int *arr, int size);
void	ft_qsort(int *arr, int end_idx);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

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

int		ft_parse(int argc, char **argv, t_prime *prime, t_arg_tab *arg_tab);
char	**ft_argv_to_str_tab(int argc, char **argv, t_arg_tab *arg_tab);

int		ft_sort(t_prime *prime);
void	ft_sort_3(t_prime *prime);
int		ft_sort_5(t_prime *prime);
void	ft_set_all_score(t_prime *prime);
void	ft_set_all_ways(t_stack *stack_b, int stack_b_size);
int		ft_throw_elem_to_b(t_prime *prime, t_stack *elem);
void	ft_restore_stack_a(t_prime *prime);

void	ft_set_ra_rr_score(t_stack *stack_b, t_way_score *way_score);
void	ft_set_ra_rrb_score(t_stack *stack_b, t_way_score *way_score);
void	ft_set_rb_rr_score(t_stack *stack_b, t_way_score *way_score);
void	ft_set_rra_rb_score(t_stack *stack_b, t_way_score *way_score);
void	ft_set_rra_rrr_score(t_stack *stack_b, t_way_score *way_score);
void	ft_set_rrb_rrr_score(t_stack *stack_b, t_way_score *way_score);

void	ft_prime_init(t_prime *prime);
void	ft_prime_free(t_prime *prime);
void	ft_free_arg_tab(t_arg_tab *arg_tab);
void	ft_init_arg_tab(t_arg_tab *arg_tab);
void	ft_handle_error(t_prime *prime, t_arg_tab *arg_tab);

#endif
