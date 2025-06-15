/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:10:57 by dtereshc          #+#    #+#             */
/*   Updated: 2025/06/14 20:10:29 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// counts nums within the string input
int	count_ptr(char *s)
{
	int	within;
	int	res;

	within = 0;
	res = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if ((*s >= 0 && *s <= 32) || *s == 127)
			within = 0;
		else if ((*s >= 33 && *s <= 126) && !within)
		{
			within = 1;
			res++;
		}
		s++;
	}
	return (res);
}

// allocates pointers for nums within the **res
char	*alloc_space_for_num(char *src)
{
	int			i;
	int			len;
	char		*res;
	static int	curs = 0;

	i = -1;
	len = 0;
	while (src[curs] && (src[curs] < 33 || src[curs] > 126))
		curs++;
	while (src[curs] && src[curs] >= 33 && src[curs] <= 126)
	{
		curs++;
		len++;
	}
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (++i < len)
		res[i] = src[curs - len + i];
	res[len] = '\0';
	return (res);
}

char	**ft_split(char *src)
{
	char	**res;
	int		ptrs_qtt;
	int		i;

	i = 0;
	ptrs_qtt = count_ptr(src);
	res = malloc(sizeof(char *) * (ptrs_qtt + 2));
	res[i] = malloc(1);
	*res[i++] = '\0';
	while (ptrs_qtt--)
		res[i++] = alloc_space_for_num(src);
	res[i] = NULL;
	return (res);
}
