/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 12:37:52 by nfauconn          #+#    #+#             */
/*   Updated: 2021/07/25 12:50:41 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		atoi_push_swap(t_data *data, const char *s, int neg)
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
	if (nbr > 2147483647 || nbr < -2147483647)
		error(data);
	return ((int)(nbr * sign));
}