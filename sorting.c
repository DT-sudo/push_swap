/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:40:50 by dt                #+#    #+#             */
/*   Updated: 2025/06/14 20:03:34 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_top_dif_half(t_nums **stack1, t_nums **stack2, t_nums *num,
		t_nums *trgt)
{
	if (!stack1 || !stack2)
		return ;
	if (num->first_half == 1 && num->position != 0)
	{
		while (num->position != 0)
			ra(stack1);
	}
	else if (num->first_half == 0 && num->position != 0)
	{
		while (num->position != 0)
			rra(stack1);
	}
	if (trgt->first_half == 0 && trgt->position != 0)
	{
		while (trgt->position != 0)
			rrb(stack2);
	}
	else if (trgt->first_half == 1 && trgt->position != 0)
	{
		while (trgt->position != 0)
			rb(stack2);
	}
}

void	get_top_same_half(t_nums **stack1, t_nums **stack2, t_nums *num,
		t_nums *trgt)
{
	if (!stack1 || !stack2)
		return ;
	if (num->first_half == 1 && trgt->first_half == 1)
	{
		while (num->position != 0 && trgt->position != 0)
			rr(stack1, stack2);
		while (num->position != 0)
			ra(stack1);
		while (trgt->position != 0)
			rb(stack2);
	}
	else if (num->first_half == 0 && trgt->first_half == 0)
	{
		while (num->position != 0 && trgt->position != 0)
			rrr(stack1, stack2);
		while (num->position != 0)
			rra(stack1);
		while (trgt->position != 0)
			rrb(stack2);
	}
}

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
	t_nums	*tmp;

	tmp = *a;
	biggest = find_biggest_number(*a);
	set_position(*a);
	if (biggest->position == 0)
		ra(a);
	else if (biggest->position == 1)
		rra(a);
	if ((*a)->number > ((*a)->next)->number)
		sa(a);
	tmp = *a;
}
   
// printf("\nFrom three_sort func\nSTACK A:\n"); // DEL
// while (tmp != NULL)
// {
// 	printf("%d -> ", (tmp)->number);
// 	tmp = (tmp)->next;
// }
// printf("\n");