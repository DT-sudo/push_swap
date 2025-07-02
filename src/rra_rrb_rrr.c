/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:04:40 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/02 21:44:42 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_b(t_nums **stack, int i)
{
	t_nums	*last;
	t_nums	*before_lust;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	before_lust = *stack;
	while (last->next)
	{
		before_lust = last;
		last = last->next;
	}
	before_lust->next = NULL;
	last->next = *stack;
	*stack = last;
	if(i == 0)
		write(1, "rra\n", 4);
	else if (i == 1)
		write(1, "rrb\n", 4);
	set_position(*stack);
}

void	rrr(t_nums **a, t_nums **b)
{
	rra_b(a, 3);
	rra_b(b, 3);
	write(1, "rrr\n", 4);
}
