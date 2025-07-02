/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:40:50 by dt                #+#    #+#             */
/*   Updated: 2025/07/02 21:20:45 by dt               ###   ########.fr       */
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
		ra_b(a, 0);
	else if (biggest->position == 1)
		rra_b(a, 0);
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
			ra_b(stack_a, 0);
	}
	else
	{
		while (smlst->position != 0)
			rra_b(stack_a, 0);
	}
}
