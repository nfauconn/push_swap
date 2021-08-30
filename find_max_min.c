/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 10:19:05 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/24 17:02:36 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_min(t_data *data, t_elem *tmp, char pile_name)
{
	t_elem		*end;

	if (pile_name == 'a')
		end = data->start_a->prev;
	else
		end = data->start_b->prev;
	data->min = data->max;
	while (1)
	{
		if (tmp->value <= data->min)
			data->min = tmp->value;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

static void	find_max(t_data *data, t_elem *tmp, char pile_name)
{
	t_elem		*end;

	if (pile_name == 'a')
		end = data->start_a->prev;
	else
		end = data->start_b->prev;
	data->max = tmp->value;
	while (1)
	{
		if (tmp->value > data->max)
			data->max = tmp->value;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	find_max_min(t_data *data, char pile_name)
{
	t_elem	*top;

	if (pile_name == 'a')
		top = data->start_a;
	else
		top = data->start_b;
	find_max(data, top, pile_name);
	find_min(data, top, pile_name);
}
