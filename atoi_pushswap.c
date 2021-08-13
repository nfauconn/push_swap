/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 12:37:52 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/13 10:49:54 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atoi_pushswap(t_data *data, const char *s, int neg)
{
	int					sign;
	long long			nbr;

	sign = 1;
	nbr = 0;
	if (neg)
		sign *= -1;
	while (*s >= '0' && *s <= '9')
	{
		nbr = (nbr * 10) + (*s - '0');
		s++;
	}
	if (nbr > 2147483647)
	{
		if (nbr == 2147483648 && sign == -1)
			return(-2147483648);
		error(data);
	}
	return ((int)(nbr * sign));
}
