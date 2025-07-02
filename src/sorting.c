/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:40:50 by dt                #+#    #+#             */
/*   Updated: 2025/07/01 22:04:49 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_sort(t_nums **a)
{
	t_nums	*sec;

	sec = (*a)->next;
	if (!a || !*a)
		return ;
	if ((*a)->number > sec->number)
		sa(a);
}

void	three_sort(t_nums **a)
{
	t_nums	*biggest;

	biggest = find_biggest_number(*a);
	set_position(*a);
	if (biggest->position == 0)
		ra(a);
	else if (biggest->position == 1)
		rra(a);
	if ((*a)->number > ((*a)->next)->number)
		sa(a);
}

void	last_sort(t_nums **stack_a)
{
	t_nums	*smlst;

	smlst = find_lowest_number(*stack_a);
	if (smlst->first_half == 1)
	{
		while (smlst->position != 0)
			ra(stack_a);
	}
	else
	{
		while (smlst->position != 0)
			rra(stack_a);
	}
}
