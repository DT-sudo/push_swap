/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:04:40 by dtereshc          #+#    #+#             */
/*   Updated: 2025/06/14 20:07:10 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift down all elements of stack a by 1.
void rra(t_nums **a)
{
    t_nums *last;
    t_nums *before_lust;
    int i;

    if (!a || !*a || !(*a)->next)
        return;
    i = -1;
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
    t_nums *lust;
    t_nums *before_lust;
    int i;

    i = -1;
    lust = *b;
    before_lust = *b;
    while (lust->next != NULL)
    {
        lust = lust->next;
        i++;
    }
    while (i--)
        before_lust = before_lust->next;
    before_lust->next = NULL;
    lust->next = *b;
    *b = lust; 
	write(1, "rra\n", 4);
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
