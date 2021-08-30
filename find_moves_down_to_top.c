/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves_down_to_top.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:46:10 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/24 17:11:32 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	max_down_to_top(t_data *data, char pile_name)
{
	t_elem	*tmp;

	if (pile_name == 'a')
		tmp = data->start_a->prev;
	else
		tmp = data->start_b->prev;
	if (tmp)
	{
		while (tmp->value != data->max)
		{
			data->max_down_to_top++;
			tmp = tmp->prev;
		}
		data->max_down_to_top++;
	}
}

static void	min_down_to_top(t_data *data, char pile_name)
{
	t_elem	*tmp;

	if (pile_name == 'a')
		tmp = data->start_a->prev;
	else
		tmp = data->start_b->prev;
	if (tmp)
	{
		while (tmp->value != data->min)
		{
			data->min_down_to_top++;
			tmp = tmp->prev;
		}
		data->min_down_to_top++;
	}
}

void	moves_down_to_top(t_data *data, char pile_name, int s_or_b)
{
	if (s_or_b == 1)
		min_down_to_top(data, pile_name);
	else if (s_or_b == 2)
		max_down_to_top(data, pile_name);
}
