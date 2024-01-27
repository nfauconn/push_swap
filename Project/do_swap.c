/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 12:01:11 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 20:19:20 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_a(t_data *data)
{
	int	tmp;

	if (data->start_a && data->start_a->next != data->start_a)
	{
		tmp = data->start_a->value;
		data->start_a->value = data->start_a->next->value;
		data->start_a->next->value = tmp;
	}
	if (data->do_write)
		write(1, "sa\n", 3);
}

void	swap_top_b(t_data *data)
{
	int	tmp;

	if (data->start_b && data->start_b->next != data->start_b)
	{
		tmp = data->start_b->value;
		data->start_b->value = data->start_b->next->value;
		data->start_b->next->value = tmp;
	}
	if (data->do_write)
		write(1, "sb\n", 3);
}

void	swap_a_swap_b(t_data *data)
{
	data->do_write = 0;
	swap_top_a(data);
	swap_top_b(data);
	data->do_write = 1;
	if (data->do_write)
		write(1, "ss\n", 3);
}
