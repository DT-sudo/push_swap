/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:46:16 by dtereshc          #+#    #+#             */
/*   Updated: 2025/06/14 20:06:56 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of stack a by 1.
void	ra(t_nums **a)
{
	t_nums	*p_a;
	t_nums	*p_sec;

	p_a = *a;
	p_sec = (*a)->next;
	while (p_a->next != NULL)
		p_a = p_a->next;
	p_a->next = *a;
	(*a)->next = NULL;
	*a = p_sec;
	write(1, "ra\n", 3);
	set_position(*a);
}

// Shift up all elements of stack b by 1
void	rb(t_nums **b)
{
	t_nums	*p_b;
	t_nums	*p_sec;

	p_b = *b;
	p_sec = (*b)->next;
	while (p_b->next != NULL)
		p_b = p_b->next;
	p_b->next = *b;
	(*b)->next = NULL;
	*b = p_sec;
	write(1, "rb\n", 3);
	set_position(*b);
}

// ra and rb at the same time.
void	rr(t_nums **a, t_nums **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
	set_position(*a);
	set_position(*b);
}