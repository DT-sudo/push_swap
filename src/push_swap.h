/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:12:44 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/01 21:09:58 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERR_MEMORY_FAIL 4
# define ERR_INPUT_FAIL 5

typedef struct s_nums
{
	int				number;
	int				position;
	int				top_price;
	bool			first_half;
	int				push_price;
	bool			cheapest;
	struct s_nums	*target;
	struct s_nums	*next;
}					t_nums;

// del
void				print_stack(const char *name, t_nums *stack);
void				print_stacks_summary(t_nums *stack_a, t_nums *stack_b);

// parse input
int					dublicate_check(t_nums *node, char **argv,
						bool argv_is_string);
int					ft_strlen(char *s);
int					count_ptr(char *s);
int					pawr(int len);
char				*alloc_space_for_num(char *src);
char				**ft_split(char *src);
bool				check_validity(char *c);
long				str_to_num(char *num, char **argv, t_nums **a,
						bool argv_is_string);
void				str_to_num_cleaner(char **argv, t_nums **a,
						bool argv_is_string);

// stack funcs
t_nums				**do_stack(t_nums **a, char **argv, bool argv_is_string);
t_nums				*do_node(int number);
size_t				stack_len(t_nums *node);
t_nums				*find_last_num(t_nums *lst);
t_nums				*find_lowest_number(t_nums *stack);
t_nums				*find_biggest_number(t_nums *stack);
void				append_num(t_nums **head, t_nums *num_to_add);
int					stack_is_sorted(t_nums *node);

// setting stack
void				set_odd_position(t_nums *stack, int median, int len, int i);
void				set_even_position(t_nums *stack, int median, int len,
						int i);
void				set_position(t_nums *stack);
void				calc_push_price(t_nums *b);
void				set_cheapest(t_nums *b);
void				find_target_a(t_nums *a, t_nums *b);
void				find_target_b(t_nums *a, t_nums *b);
void				settle_funcs_a(t_nums *a, t_nums *b);
void				settle_funcs_b(t_nums *a, t_nums *b);

// sorting
void				two_sort(t_nums **a);
void				three_sort(t_nums **a);
void				push_swap(t_nums **a, t_nums **b);
void				push_swap_logic_a(t_nums **stack1, t_nums **stack2,
						t_nums *num);
void				push_swap_logic_b(t_nums **stack1, t_nums **stack2,
						t_nums *num);
void				get_top_dif_half_a(t_nums **stack1, t_nums **stack2,
						t_nums *num, t_nums *trgt);
void				get_top_same_half_a(t_nums **stack1, t_nums **stack2,
						t_nums *num, t_nums *trgt);
void				get_top_dif_half_b(t_nums **stack1, t_nums **stack2,
						t_nums *num, t_nums *trgt);
void				get_top_same_half_b(t_nums **stack1, t_nums **stack2,
						t_nums *num, t_nums *trgt);
void				last_sort(t_nums **stack_1);

// rules
void				sa(t_nums **a);
void				sb(t_nums **b);
void				ss(t_nums **a, t_nums **b);
void				pa(t_nums **a, t_nums **b);
void				pb(t_nums **a, t_nums **b);
void				ra(t_nums **a);
void				rb(t_nums **b);
void				rr(t_nums **a, t_nums **b);
void				rrr(t_nums **a, t_nums **b);
void				rra(t_nums **a);
void				rrb(t_nums **b);

// free funcs
void				free_malloced_input(char **malloced_argv);
void				clear_stack(t_nums **head, void (*f)(t_nums **));
void				del(t_nums **node);

#endif