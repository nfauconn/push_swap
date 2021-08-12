/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:26:36 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/11 14:46:14 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_data *data)
{
	if (data->start_a)
		data->start_a = data->start_a->next;
	write(1, "ra\n", 3);
}

void	rotate_b(t_data *data)
{
	if (data->start_b)
		data->start_b = data->start_b->next;
	write(1, "rb\n", 3);
}
