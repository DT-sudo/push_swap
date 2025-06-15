/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:46:27 by dtereshc          #+#    #+#             */
/*   Updated: 2025/06/14 20:07:25 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack a.
void	sa(t_nums **a)
{
	t_nums	*tmp;

	if (!a || !*a)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "sa\n", 3);
	set_position(*a);
}

// Swap the first 2 elements at the top of stack b.
void	sb(t_nums **b)
{
	t_nums	*tmp;

	if (!b || !*b)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "sb\n", 3);
	set_position(*b);
}

void	ss(t_nums **a, t_nums **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
	set_position(*a);
	set_position(*b);
}
