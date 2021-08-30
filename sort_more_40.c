/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_40.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:43:28 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/25 12:08:52 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b_quarters(t_data *data, t_elem *elem, int quarter)
{
	int		done;
	int		min_reached;
	int		n;
	t_elem	*end;

	end = data->start_a->prev;
	done = 0;
	find_max_min(data, 'a');
	n = elem->value;
	while (!done)
	{
		if (elem == end)
			done = 1;
		min_reached = selected_quarter_push(data, n, quarter);
		if (min_reached)
			break ;
		elem = data->start_a;
		n = elem->value;
	}
	reinitialize_moves(data);
}

void	sort_more_40(t_data *data)
{
	int	quarter;

	quarter = 1;
	find_quantiles(data, data->start_a, 'a');
	while (data->start_a)
	{
		push_to_b_quarters(data, data->start_a, quarter);
		while (data->start_b)
		{
			find_max_min(data, 'b');
			find_shortest_move(data);
			sorted_push_to_a(data, data->start_b, data->start_b->prev);
		}
		while (--data->rotate_later)
			rotate_a(data);
		quarter++;
		if (quarter == 5)
			break ;
	}
}
