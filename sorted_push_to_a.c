/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_push_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:51:48 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/24 17:55:28 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_and_push_to_a(t_data *data)
{
	if (data->min_up_to_top > -1)
		while (data->min_up_to_top--)
			rotate_b(data);
	else if (data->min_down_to_top > -1)
		while (data->min_down_to_top--)
			reverse_rotate_b(data);
	else if (data->max_up_to_top > -1)
		while (data->max_up_to_top--)
			rotate_b(data);
	else if (data->max_down_to_top > -1)
		while (data->max_down_to_top--)
			reverse_rotate_b(data);
	push_top_b_to_a(data);
	if (data->min_chosen)
		rotate_a(data);
	if (data->max_chosen || !data->start_b)
		data->rotate_later++;
	reinitialize_moves(data);
}

void	sorted_push_to_a(t_data *data, t_elem *tmp, t_elem *end)
{
	while (1)
	{
		while (tmp->value != data->min && tmp->value != data->max)
			tmp = tmp->next;
		if (tmp->value == data->min || tmp->value == data->max)
		{
			rotate_and_push_to_a(data);
			break ;
		}
		else
			tmp = tmp->next;
		if (tmp == end)
			break ;
		tmp = data->start_b;
	}
}
