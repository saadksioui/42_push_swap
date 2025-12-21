/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:25:11 by sksioui           #+#    #+#             */
/*   Updated: 2025/12/20 15:44:39 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// Swap Rules
void				sa(t_stack **a, int print);
void				sb(t_stack **b, int print);
void				ss(t_stack **a, t_stack **b);
// Push Rules
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
// Rotate Rules
void				ra(t_stack **a, int print);
void				rb(t_stack **b, int print);
void				rr(t_stack **a, t_stack **b);
// Rev-Rotate Rules
void				rra(t_stack **a, int print);
void				rrb(t_stack **b, int print);
void				rrr(t_stack **a, t_stack **b);

// List Utils
int					ft_lstsize(t_stack *stack);
t_stack				*ft_lstnew_dll(int value);
t_stack				*ft_lstlast(t_stack *stack);
void				ft_lstadd_back(t_stack **stack, t_stack *new);

// Checking Arguments
int					check_syntax(char *str_n);
int					check_duplicate(t_stack *a, int nbr);
int					ft_isdigit(int c);

// Stack Initializing
void				parse_and_add(t_stack **a, char *str_nbr, char **argv);
void				stack_init(t_stack **a, char **argv, int argc);

// Parsing Utils
long				ft_atol(char *arg);
void				free_argv(char **argv);
void				ft_error(void);
void				ft_error_and_free(t_stack **a, char **args);

// Finding Tools
int					get_pos(t_stack *stack, int index);
int					get_max_index(t_stack *stack);
int					get_min_index(t_stack *stack);

// Indexing
int					*fill_array(t_stack *a, int size);
void				sort_array(int *tab, int size);
void				index_stack(t_stack *a);

// Sorting 3-5 Elements
void				sort_three(t_stack **a);
void				sort_five(t_stack **a, t_stack **b);
int					find_min_val(t_stack *a);

// Split Func + Utils
char				**ft_split(const char *s, char c);
long				ft_atol(char *arg);

// Sorting utils
int					is_sorted(t_stack *a);
void				free_stack(t_stack **stack);
void				sort_stack(t_stack **a, t_stack **b);

// Sorting Algorithm For push_swap
void				push_to_b(t_stack **a, t_stack **b);
void				push_to_a(t_stack **a, t_stack **b);
void				chunk_sorting_algo(t_stack **a, t_stack **b);

#endif