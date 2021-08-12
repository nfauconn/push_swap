/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 12:01:11 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/11 17:02:56 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_2first_a(t_data *data)
{
	int	tmp;

	if (data->start_a && data->start_a->next != data->start_a)
	{
		tmp = data->start_a->value;
		data->start_a->value = data->start_a->next->value;
		data->start_a->next->value = tmp;
	}
	write(1, "sa\n", 3);
}

void	swap_2first_b(t_data *data)
{
	int	tmp;

	if (data->start_b && data->start_b->next != data->start_b)
	{
		tmp = data->start_b->value;
		data->start_b->value = data->start_b->next->value;
		data->start_b->next->value = tmp;
	}
	write(1, "sb\n", 3);
}
