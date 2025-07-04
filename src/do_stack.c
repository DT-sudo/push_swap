/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:04:40 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/01 21:17:12 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_validity(char *c)
{
	int	i;

	i = 0;
	if (*c == '-' || *c == '+' || (*c >= '0' && *c <= '9'))
		c++;
	else
		return (false);
	while (*c)
	{
		i++;
		if (*c >= '0' && *c <= '9')
		{
			c++;
			continue ;
		}
		else if (!(*c >= '0' && *c <= '9'))
			return (false);
		c++;
	}
	if (i >= 11 || (i == 0 && (*(c - 1) == '-' || *(c - 1) == '+')))
		return (false);
	return (true);
}

long	str_to_num_logic(char *num, long res)
{
	int	sign;
	int	pwr;

	sign = 1;
	while (*num)
	{
		if (*num == '-')
		{
			num++;
			sign *= -1;
		}
		else if (*num == '+')
			num++;
		pwr = pawr(ft_strlen(num));
		while (*num)
		{
			res += (*num++ - '0') * pwr;
			pwr /= 10;
		}
	}
	res *= sign;
	return (res);
}

long	str_to_num(char *num, char **argv, t_nums **a, bool argv_is_string)
{
	long	res;

	res = 0;
	if (!num)
		return (0);
	if (!check_validity(num))
		str_to_num_cleaner(argv, a, argv_is_string);
	res = str_to_num_logic(num, res);
	if (res < INT_MIN || res > INT_MAX)
		str_to_num_cleaner(argv, a, argv_is_string);
	return (res);
}

t_nums	**do_stack(t_nums **a, char **argv, bool argv_is_string)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		append_num(a, do_node((int)str_to_num(argv[i++], argv, a,
					argv_is_string)));
	}
	dublicate_check(*a, argv, argv_is_string);
	if (argv_is_string)
		free_malloced_input(argv);
	return (a);
}
