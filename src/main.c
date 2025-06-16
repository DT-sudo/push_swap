/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:11:30 by dtereshc          #+#    #+#             */
/*   Updated: 2025/06/16 12:39:22 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (argc == 2 && (*argv[1] is not valid num))
//check_validity(argv[1])


int	main(int argc, char *argv[])
{
	t_nums *a;
	t_nums *b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (argc == 2)
	{
		validate_second_argc(argv[1]);
		argv = ft_split(argv[1]);
	}
	do_stack(&a, argv, 2 == argc);
	if (!stack_is_sorted(a))
	{
		if (stack_len(a) == 2)
			two_sort(&a);
		else if (stack_len(a) == 3)
			three_sort(&a);
		else
			push_swap(&a, &b);
	}
	clear_stack(&a, del);
	return (0);
}
