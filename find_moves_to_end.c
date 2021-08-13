/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves_to_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:46:10 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/13 16:22:33 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Calculates moves to bottom of list
*/

static void	max_to_end(t_data *data, char pile_name)
{
	t_elem	*tmp;

	if (pile_name == 'a')
		tmp = data->start_a->prev;
	else if (pile_name == 'b')
		tmp = data->start_b->prev;
	if (tmp)
	{
		while (tmp->value != data->max)
		{
			data->max_to_end++;
			tmp = tmp->prev;
		}
		data->max_to_end++;
	}
}

static void	min_to_end(t_data *data, char pile_name)
{
	t_elem	*tmp;

	if (pile_name == 'a')
		tmp = data->start_a->prev;
	else if (pile_name == 'b')
		tmp = data->start_b->prev;
	if (tmp)
	{
		while (tmp->value != data->min)
		{
			data->min_to_end++;
			tmp = tmp->prev;
		}
		data->min_to_end++;
	}
}

void		moves_to_end(t_data *data, char pile_name, int min_or_max)
{
	if (min_or_max == 1)
		min_to_end(data, pile_name);
	else if (min_or_max == 2)
		max_to_end(data, pile_name);
}
