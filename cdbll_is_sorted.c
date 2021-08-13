/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdbll_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:05:36 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/13 10:51:24 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_data *data)
{
	t_elem	*tmp;

	if (!data->start_a || data->start_b)
		error(data);
	tmp = data->start_a;
	while (tmp->next != data->start_a)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
