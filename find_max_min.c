/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:52:37 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/11 15:10:54 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min(t_data *data, char stack)
{
	t_elem		*top;
	t_elem		*tmp;
	t_elem		*end;

	if (stack == 'a')
	{
		top = data->start_a;
		end = data->start_a->prev;
	}
	else
	{
		top = data->start_b;
		end = data->start_b->prev;
	}
	tmp = top;
	data->min = data->max;
	while (tmp != end)
	{
		if (tmp->value <= data->min)
			data->min = tmp->value;
		tmp = tmp->next;
	}
}

void	find_max(t_data *data, char stack)
{
	t_elem		*top;
	t_elem		*tmp;
	t_elem		*end;

	if (stack == 'a')
	{
		top = data->start_a;
		end = data->start_a->prev;
	}
	else
	{
		top = data->start_b;
		end = data->start_b->prev;
	}
	tmp = top;
	data->max = tmp->value;
	while (tmp != end)
	{
		if (tmp->value > data->max)
			data->max = tmp->value;
		tmp = tmp->next;
	}
}

void	find_max_min(t_data *data, char stack)
{
	find_max(data, stack);
	find_min(data, stack);
}
