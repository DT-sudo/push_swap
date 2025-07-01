/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:55:07 by dt                #+#    #+#             */
/*   Updated: 2025/07/01 17:47:49 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_push_price(t_nums *stack)
{
	int	res;

	while (stack)
	{
		if (stack->first_half == stack->target->first_half)
		{
			if (stack->top_price > stack->target->top_price)
				res = (stack->top_price - stack->target->top_price)
					+ stack->target->top_price;
			else
				res = (stack->target->top_price - stack->top_price)
					+ stack->top_price;
			stack->push_price = res;
		}
		else
			stack->push_price = stack->top_price + stack->target->top_price;
		stack = stack->next;
	}
}

// find closets smaller target for every a from b find_target_a
void	find_target_a(t_nums *a, t_nums *b)
{
	t_nums	*cur_a;
	t_nums	*cur_b;
	t_nums	*target;

	cur_a = a;
	// printf("\nFrom find_target_func:");
	while (cur_a)
	{
		cur_b = b;
		target = NULL;
		while (cur_b)
		{
			if (cur_a->number > cur_b->number)
			{
				if (!target || cur_b->number > target->number)
					target = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (!target)
			target = find_biggest_number(b);
		cur_a->target = target;
		// printf("\ntarget of %d: %d", cur_a->number, cur_a->target->number);
		// 	// del
		cur_a = cur_a->next;
	}
}

// find closest bigger target for every b from a find_target_b
void	find_target_b(t_nums *a, t_nums *b)
{
	t_nums	*cur_a;
	t_nums	*cur_b;
	t_nums	*target;

	cur_b = b;
	// printf("\nFrom find_target_func:");
	while (cur_b)
	{
		cur_a = a;
		target = NULL;
		while (cur_a)
		{
			if (cur_b->number < cur_a->number)
			{
				if (!target || cur_a->number < target->number)
					target = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (!target)
			target = find_lowest_number(a);
		cur_b->target = target;
		// printf("\ntarget of %d: %d", cur_b->number, cur_b->target->number);
		// 	// del
		cur_b = cur_b->next;
	}
}

void	settle_funcs_a(t_nums *a, t_nums *b)
{
	find_target_a(a, b);
	calc_push_price(a);
	set_cheapest(a);
}

void	settle_funcs_b(t_nums *a, t_nums *b)
{
	find_target_b(a, b);
	calc_push_price(b);
	set_cheapest(b);
}
