/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_40.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:31:46 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 20:17:46 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b_below_then_upper_median(t_data *data, int below_or_up)
{
	int		done;
	t_elem	*tmp;
	t_elem	*end;

	done = 0;
	tmp = data->start_a;
	end = data->start_a->prev;
	while (!done)
	{
		if (tmp == end)
			done = 1;
		if (below_or_up == 1 && (tmp->value <= data->median))
			push_top_a_to_b(data);
		else if (below_or_up == 2 && (tmp->value > data->median))
			push_top_a_to_b(data);
		else
			rotate_a(data);
		if (done)
			break ;
		tmp = data->start_a;
	}
	reinitialize_moves(data);
}

void	sort_less_40(t_data *data)
{
	int	below_or_up;

	below_or_up = 1;
	find_quantiles(data, data->start_a, 'a');
	while (data->start_a)
	{
		push_to_b_below_then_upper_median(data, below_or_up);
		while (data->start_b)
		{
			find_max_min(data, 'b');
			find_shortest_move(data);
			sorted_push_to_a(data, data->start_b, data->start_b->prev);
		}
		while (--data->rotate_later)
			rotate_a(data);
		below_or_up++;
		if (below_or_up == 3)
			break ;
	}
}
