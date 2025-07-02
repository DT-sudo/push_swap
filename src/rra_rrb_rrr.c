/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:04:40 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/01 20:59:52 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift down all elements of stack a by 1.
void	rra(t_nums **a)
{
	t_nums	*last;
	t_nums	*before_lust;

	if (!a || !*a || !(*a)->next)
		return ;
	last = *a;
	before_lust = *a;
	while (last->next)
	{
		before_lust = last;
		last = last->next;
	}
	before_lust->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
	set_position(*a);
}

void	rrb(t_nums **b)
{
	t_nums	*last;
	t_nums	*before_lust;

	if (!b || !*b || !(*b)->next)
		return ;
	last = *b;
	before_lust = *b;
	while (last->next)
	{
		before_lust = last;
		last = last->next;
	}
	before_lust->next = NULL;
	last->next = *b;
	*b = last;
	write(1, "rrb\n", 4);
	set_position(*b);
}

void	rrr(t_nums **a, t_nums **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
	set_position(*a);
	set_position(*b);
}
