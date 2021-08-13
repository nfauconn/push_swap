/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:27:30 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/13 10:48:57 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_data *data)
{
	if (data->start_a)
		data->start_a = data->start_a->prev;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_data *data)
{
	if (data->start_b)
		data->start_b = data->start_b->prev;
	write(1, "rra\n", 4);
}
