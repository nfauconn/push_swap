/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:26:36 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 20:19:23 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_data *data)
{
	if (data->start_a)
		data->start_a = data->start_a->next;
	if (data->do_write)
		write(1, "ra\n", 3);
}

void	rotate_b(t_data *data)
{
	if (data->start_b)
		data->start_b = data->start_b->next;
	if (data->do_write)
		write(1, "rb\n", 3);
}

void	rotate_a_b(t_data *data)
{
	data->do_write = 0;
	rotate_a(data);
	rotate_b(data);
	data->do_write = 1;
	if (data->do_write)
		write(1, "rr\n", 3);
}
