/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fewer_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:15:14 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/13 14:06:40 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	moves_min(t_data *data)
{
	t_elem	*tmp;

	tmp = data->start_b;
	if (tmp)
	{
		moves_to_start(data, 'b', 1);
		moves_to_end(data, 'b', 1);
		if (data->min_to_start <= data->min_to_end)
			data->min_to_end = -1;
		else
			data->min_to_start = -1;
	}
}

static void	moves_max(t_data *data)
{
	t_elem	*tmp;

	tmp = data->start_b;
	if (tmp)
	{
		moves_to_start(data, 'b', 2);
		moves_to_end(data, 'b', 2);
		if (data->max_to_start <= data->max_to_end)
			data->max_to_end = -1;
		else
			data->max_to_start = -1;
	}
}

/*
** Calculates which has fewest moves to push to list a:
** the data->max or data->min integer in list b,
** either by rotating to the top or reverse rotating to the end.
*/

void		find_fewer_moves_b(t_data *data)
{
	moves_min(data);
	moves_max(data);
	if (data->max_to_start != -1 && (data->max_to_start >= data->min_to_start && 
										data->max_to_start >= data->min_to_end))
		data->max_to_start = -1;
	else if (data->max_to_end != -1 && (data->max_to_end >= data->min_to_start &&
										data->max_to_end >= data->min_to_end))
		data->max_to_end = -1;
	else if (data->min_to_start != -1 && (data->min_to_start >= data->max_to_start &&
										data->min_to_start >= data->max_to_end))
		data->min_to_start = -1;
	else if (data->min_to_end != -1 && (data->min_to_end >= data->max_to_start &&
										data->min_to_end >= data->max_to_end))
		data->min_to_end = -1;
	if (data->min_to_start != -1 || data->min_to_end != -1)
		data->min_chosen = 1;
	else if (data->max_to_start != -1 || data->max_to_end != -1)
		data->max_chosen = 1;
}

