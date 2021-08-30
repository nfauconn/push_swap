/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:47:11 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/24 17:00:45 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top_b_to_a(t_data *data)
{
	int	tmp;

	if (data->start_b)
	{
		tmp = data->start_b->value;
		del_top(data, 'b');
		insert_top(data, 'a', tmp);
	}
	if (data->do_write)
		write(1, "pa\n", 3);
}

void	push_top_a_to_b(t_data *data)
{
	int	tmp;

	if (data->start_a)
	{
		tmp = data->start_a->value;
		del_top(data, 'a');
		insert_top(data, 'b', tmp);
	}
	if (data->do_write)
		write(1, "pb\n", 3);
}
