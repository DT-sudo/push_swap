/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_top_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:02:17 by dt                #+#    #+#             */
/*   Updated: 2025/07/02 21:19:15 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_top_dif_half_a(t_nums **stack1, t_nums **stack2, t_nums *num,
		t_nums *trgt)
{
	if (!stack1 || !stack2)
		return ;
	if (num->first_half == 1 && num->position != 0)
	{
		while (num->position != 0)
			ra_b(stack1, 0);
	}
	else if (num->first_half == 0)
	{
		while (num->position != 0)
			rra_b(stack1, 0);
	}
	if (trgt->first_half == 0)
	{
		while (trgt->position != 0)
			rra_b(stack2, 1);
	}
	else if (trgt->first_half == 1 && trgt->position != 0)
	{
		while (trgt->position != 0)
			ra_b(stack2, 1);
	}
}

void	get_top_same_half_a(t_nums **stack1, t_nums **stack2, t_nums *num,
		t_nums *trgt)
{
	if (!stack1 || !stack2)
		return ;
	if (num->first_half == 1 && trgt->first_half == 1)
	{
		while (num->position != 0 && trgt->position != 0)
			rr(stack1, stack2);
		while (num->position != 0)
			ra_b(stack1, 0);
		while (trgt->position != 0)
			ra_b(stack2, 1);
	}
	else if (num->first_half == 0 && trgt->first_half == 0)
	{
		while (num->position != 0 && trgt->position != 0)
			rrr(stack1, stack2);
		while (num->position != 0)
			rra_b(stack1, 0);
		while (trgt->position != 0)
			rra_b(stack2, 1);
	}
}

void	get_top_dif_half_b(t_nums **stack1, t_nums **stack2, t_nums *num,
		t_nums *trgt)
{
	if (!stack1 || !stack2)
		return ;
	if (num->first_half == 1 && num->position != 0)
	{
		while (num->position != 0)
			ra_b(stack2, 1);
	}
	else if (num->first_half == 0)
	{
		while (num->position != 0)
			rra_b(stack2, 1);
	}
	if (trgt->first_half == 0)
	{
		while (trgt->position != 0)
			rra_b(stack1, 0);
	}
	else if (trgt->first_half == 1 && trgt->position != 0)
	{
		while (trgt->position != 0)
			ra_b(stack1, 0);
	}
}

void	get_top_same_half_b(t_nums **stack1, t_nums **stack2, t_nums *num,
		t_nums *trgt)
{
	if (!stack1 || !stack2)
		return ;
	if (num->first_half == 1 && trgt->first_half == 1)
	{
		while (num->position != 0 && trgt->position != 0)
			rr(stack1, stack2);
		while (num->position != 0)
			ra_b(stack2, 1);
		while (trgt->position != 0)
			ra_b(stack1, 0);
	}
	else if (num->first_half == 0 && trgt->first_half == 0)
	{
		while (num->position != 0 && trgt->position != 0)
			rrr(stack1, stack2);
		while (num->position != 0)
			rra_b(stack2, 1);
		while (trgt->position != 0)
			rra_b(stack1, 0);
	}
}
