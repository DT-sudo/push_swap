/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:12:44 by dtereshc          #+#    #+#             */
/*   Updated: 2025/06/14 20:11:08 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nums	*do_node(int number)
{
	t_nums	*node;

	node = malloc(sizeof(t_nums));
	if (!node)
		exit(ERR_MEMORY_FAIL);
	node->number = number;
	node->position = 0;
	node->top_price = 0;
	node->push_price = 0;
	node->first_half = false;
	node->cheapest = false;
	node->target = NULL;
	node->next = NULL;
	return (node);
}

t_nums	*find_last_num(t_nums *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

size_t	stack_len(t_nums *node)
{
	size_t i;

	i = 0;
	while(node != NULL)
	{
		i++;	
		node = node->next;
	}
	return i;
}

void	append_num(t_nums **head, t_nums *num_to_add)
{
	if (!num_to_add)
		return ;
	if (!*head)
	{
		*head = num_to_add;
		return ;
	}
	find_last_num(*head)->next = num_to_add;
}

int		dublicate_check(t_nums *node, char **argv, bool argv_is_string)
{
	t_nums *tmp;
	t_nums	*compare;
	size_t	len;

	if (!node)
		return (0);
	len = stack_len(node);
	tmp = node;
	compare = node->next;
	while (--len)
	{
		while (compare != NULL)
		{
			if (tmp->number == compare->number)
				str_to_num_cleaner(argv, &node, argv_is_string);
			compare = compare->next;
		}
		tmp = tmp->next;
		compare = tmp->next;
	}
	return (1);
}
