/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:46:22 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/01 13:58:30 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Take the first element at the top of b and put it at the top of a.
void	pa(t_nums **a, t_nums **b)
{
	t_nums	*a_p;

	if (!a || !b || !*b)
		return ;
	a_p = *b;
	a_p->target = NULL;
	*b = (*b)->next;
	a_p->next = *a;
	*a = a_p;
	write(1, "pa\n", 3);
	set_position(*a);
	set_position(*b);
}

// Take the first element at the top of a and put it at the top of b.
void	pb(t_nums **a, t_nums **b)
{
	t_nums	*b_p;

	if (!a || !b || !*a)
		return ;
	b_p = *a;
	b_p->target = NULL;
	*a = (*a)->next;
	b_p->next = *b;
	*b = b_p;
	write(1, "pb\n", 3);
	set_position(*a);
	set_position(*b);
}
