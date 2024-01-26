/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:27:30 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 20:19:26 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_data *data)
{
	if (data->start_a)
		data->start_a = data->start_a->prev;
	if (data->do_write)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_data *data)
{
	if (data->start_b)
		data->start_b = data->start_b->prev;
	if (data->do_write)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_a_b(t_data *data)
{
	data->do_write = 0;
	reverse_rotate_a(data);
	reverse_rotate_b(data);
	data->do_write = 1;
	if (data->do_write)
		write(1, "rrr\n", 4);
}
