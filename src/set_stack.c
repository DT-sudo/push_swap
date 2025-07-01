/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:31:16 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/01 17:59:24 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_odd_position(t_nums *stack, int median, int len, int i)
{
	if (i <= median)
	{
		stack->top_price = i;
		stack->first_half = true;
	}
	else
	{
		stack->top_price = len - i;
		stack->first_half = false;
	}
}

void	set_even_position(t_nums *stack, int median, int len, int i)
{
	if (i < median)
	{
		stack->top_price = i;
		stack->first_half = true;
	}
	else
	{
		stack->top_price = len - i;
		stack->first_half = false;
	}
}

//setting 1hlf, top, pos
void	set_position(t_nums *stack)
{
	int	median;
	int len;
	int	i;

	if (!stack)
		return ;
	i = 0;
	median = stack_len(stack) / 2;
	len =  stack_len(stack);
	while (stack != NULL)
	{
		if (median % 2 == 1)
			set_odd_position(stack, median, len, i);
		else 
			set_even_position(stack, median, len, i);
		stack->position = i++;
		stack = stack->next;
	}
}

// setting the cheapest
void	set_cheapest(t_nums *stack)
{
	t_nums	*cheapest_node;

	cheapest_node = stack;
	while (stack)
	{
		stack->cheapest = false;
		stack = stack->next;
	}
	stack = cheapest_node;
	while (stack)
	{
		if (stack->push_price < cheapest_node->push_price)
			cheapest_node = stack;
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}