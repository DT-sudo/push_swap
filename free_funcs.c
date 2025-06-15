/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:10:47 by dtereshc          #+#    #+#             */
/*   Updated: 2025/06/14 20:10:13 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// frees malloced **res input
void	free_malloced_input(char **malloced_argv)
{
	int	i;

	i = 0;
	while (malloced_argv[i])
		free(malloced_argv[i++]);
	free(malloced_argv);
}

// frees stack if input is wrong
void	str_to_num_cleaner(char **argv, t_nums **a, bool argv_is_string)
{
	if (argv_is_string)
		free_malloced_input(argv);
	clear_stack(a, del);
	write(1, "Error\n", 6);
	exit(ERR_INPUT_FAIL);
}

// freeing func for clear_stack
void	del(t_nums **node)
{
	if (!node || !*node)
		return ;
	free(*node);
	*node = NULL;
}

// frees the stack
void	clear_stack(t_nums **head, void (*del)(t_nums **))
{
	t_nums	*tmp;

	if (!head || !*head)
		return ;
	while (*head)
	{
		tmp = (*head)->next;
		del(head);
		*head = tmp;
	}
}
