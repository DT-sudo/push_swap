/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:12:32 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/01 21:11:26 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

int	pawr(int len)
{
	int	i;
	int	pawr;

	i = 1;
	pawr = 1;
	while (i++ < len)
		pawr *= 10;
	return (pawr);
}

int	stack_is_sorted(t_nums *node)
{
	t_nums	*next_node;

	if (!node)
		return (0);
	while (node->next != NULL)
	{
		next_node = node->next;
		if (!(node->number < next_node->number))
			return (0);
		else
		{
			node = node->next;
			next_node = node->next;
		}
	}
	return (1);
}

t_nums	*find_lowest_number(t_nums *stack)
{
	t_nums	*lowest;

	lowest = stack;
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
		if (lowest->number > stack->number)
			lowest = stack;
	}
	return (lowest);
}

t_nums	*find_biggest_number(t_nums *stack)
{
	t_nums	*biggest;

	biggest = stack;
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
		if (biggest->number < stack->number)
			biggest = stack;
	}
	return (biggest);
}
