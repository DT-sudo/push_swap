/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:46:16 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/02 21:44:59 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_b(t_nums **stack, int i)
{
	t_nums	*p;
	t_nums	*p_sec;

	if (!stack || !*stack)
		return ;
	p = *stack;
	p_sec = (*stack)->next;
	while (p->next != NULL)
		p = p->next;
	p->next = *stack;
	(*stack)->next = NULL;
	*stack = p_sec;
	if(i == 0)
		write(1, "ra\n", 3);
	else if (i == 1)
		write(1, "rb\n", 3);
	set_position(*stack);
}

void	rr(t_nums **a, t_nums **b)
{
	ra_b(a, 3);
	ra_b(b, 3);
	write(1, "rr\n", 3);
}
