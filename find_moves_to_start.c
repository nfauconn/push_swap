/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves_to_start.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:17:09 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/13 16:24:42 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Calculates number of moves to top of list
*/

static void	max_to_start(t_data *data, char pile_name)
{
	t_elem	*tmp;

	if (pile_name == 'a')
		tmp = data->start_a;
	else if (pile_name == 'b')
		tmp = data->start_b;
	if (tmp)
	{
		while (tmp->value != data->max_to_start)
		{
			data->max_to_start++;
			tmp = tmp->next;
		}
		data->max_to_start++;
	}
}

static void	min_to_start(t_data *data, char pile_name)
{
	t_elem	*tmp;

	if (pile_name == 'a')
		tmp = data->start_a;
	else if (pile_name == 'b')
		tmp = data->start_b;
	if (tmp)
	{
		while (tmp->value != data->min)
		{
			data->min_to_start++;
			tmp = tmp->next;
		}
		data->min_to_start++;
	}
}

void		moves_to_start(t_data *data, char pile_name, int min_or_max)
{
	if (min_or_max == 1)
		min_to_start(data, pile_name);
	else if (min_or_max == 2)
		max_to_start(data, pile_name);
}
