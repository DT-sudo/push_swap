/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:41:34 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/01 19:49:36 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// del
void	print_stack(const char *name, t_nums *stack)
{
	t_nums	*tmp = stack;

	printf("This stack %s:\n", name);
	while (tmp)
	{
		printf("Number: %4d | Pos: %2d | Top: %3d | Push: %3d | 1st_half: %d | "
			   "Cheapest: %d | Target number: %d\n",
			tmp->number, tmp->position, tmp->top_price, tmp->push_price,
			tmp->first_half, tmp->cheapest,
			tmp->target ? tmp->target->number : -99999999);
		tmp = tmp->next;
	}
	printf("\n");
}

// del
void	print_stacks_summary(t_nums *stack_a, t_nums *stack_b)
{
	t_nums	*tmp_a;
	t_nums	*tmp_b;

	tmp_a = stack_a;
	tmp_b = stack_b;
	printf("\nstackA:\n");
	while (tmp_a)
	{
		printf("%d", tmp_a->number);
		if (tmp_a->next)
			printf(" -> ");
		tmp_a = tmp_a->next;
	}
	printf(" -> NULL\n");
	printf("\nstackB:\n");
	while (tmp_b)
	{
		printf("%d", tmp_b->number);
		if (tmp_b->next)
			printf(" -> ");
		tmp_b = tmp_b->next;
	}
	printf(" -> NULL\n\n");
}
///////// 

void	last_sort(t_nums **stack_a)
{
	t_nums *smlst;

	smlst = find_lowest_number(*stack_a);
	if (smlst->first_half == 1)
	{
		while(smlst->position != 0)
			ra(stack_a);
	}
	else
	{
		while(smlst->position != 0)
			rra(stack_a);
	}	
}

void	push_swap_logic_a(t_nums **stack1, t_nums **stack2, t_nums *num)
{
	settle_funcs_a(*stack1, *stack2);
	num = *stack1;
	/////
	// print_stacks_summary(*stack1, *stack2); // del
	// print_stack("A", *stack1);              // del
	// print_stack("B", *stack2);              // del
	/////
	while (num != NULL)
	{
		if (num->cheapest == 1)
		{
			if (num->first_half == num->target->first_half)
				get_top_same_half_a(stack1, stack2, num, num->target);
			else
				get_top_dif_half_a(stack1, stack2, num, num->target);
			pb(stack1, stack2);
			(num)->cheapest = 0;
			break ;
		}
		else
			num = num->next;
	}
	// printf("---------------------------------------");
}

void	push_swap_logic_b(t_nums **stack1, t_nums **stack2, t_nums *num)
{
	settle_funcs_b(*stack1, *stack2);
	num = *stack2;
	///
	// print_stacks_summary(*stack1, *stack2); // del
	// print_stack("A", *stack1);              // del
	// print_stack("B", *stack2);              // del
	///
	while (num != NULL)
	{
		if (num->cheapest == 1)
		{
			if (num->first_half == num->target->first_half)
				get_top_same_half_b(stack1, stack2, num, num->target);
			else
				get_top_dif_half_b(stack1, stack2, num, num->target);
			pa(stack1, stack2);
			(num)->cheapest = 0;
			break ;
		}
		else
			num = num->next;
	}
	// printf("---------------------------------------");
}

void	push_swap(t_nums **a, t_nums **b)
{
	t_nums	*a_tmp;
	t_nums	*b_tmp;

	// del
	// print_stacks_summary(*a, *b); // del
	// printf("---------------------------------------");
	//
	a_tmp = NULL;
	b_tmp = NULL;
	if (stack_len(*a) == 4)
		pb(a, b);
	else
	{
		pb(a, b);
		pb(a, b);
	}
	while (stack_len(*a) != 3)
		push_swap_logic_a(a, b, a_tmp);
	three_sort(a);
	while (*b)
		push_swap_logic_b(a, b, b_tmp);
	if (!stack_is_sorted(*a))
		last_sort(a);
	// del
	// print_stacks_summary(*a, *b); // del
	//
}