/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:41:34 by dtereshc          #+#    #+#             */
/*   Updated: 2025/06/15 17:38:41 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_nums **a, t_nums **b)
{
	t_nums	*a_tmp;
	t_nums	*b_tmp;

	a_tmp = NULL;//!
	b_tmp = NULL;//!
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
	while (!stack_is_sorted(*a))
		rra(a);
}

void	push_swap_logic_a(t_nums **stack1, t_nums **stack2, t_nums *num)
{
	settle_funcs_a(*stack1, *stack2);
	num = *stack1;
	while (num != NULL)
	{
		if (num->cheapest == 1)
		{
			if (num->first_half == num->target->first_half)
				get_top_same_half(stack1, stack2, num, num->target);
			else
				get_top_dif_half(stack1, stack2, num, num->target);
			pb(stack1, stack2);
			(num)->cheapest = 0;
			break ;
		}
		else
			num = num->next;
	}
}

void	push_swap_logic_b(t_nums **stack1, t_nums **stack2, t_nums *num)
{
	settle_funcs_b(*stack1, *stack2);
	num = *stack2;
	while (num != NULL)
	{
		if (num->cheapest == 1)
		{
			if (num->first_half == num->target->first_half)
				get_top_same_half(stack2, stack1, num, num->target);
			else
				get_top_dif_half(stack2, stack1, num, num->target);
			pa(stack1, stack2);
			(num)->cheapest = 0;
			break ;
		}
		else
			num = num->next;
	}
}
