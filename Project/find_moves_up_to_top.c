/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves_up_to_top.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 21:20:21 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 20:18:23 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	max_up_to_top_moves(t_data *data, char pile_name)
{
	t_elem	*tmp;

	tmp = NULL;
	if (pile_name == 'a')
		tmp = data->start_a;
	else if (pile_name == 'b')
		tmp = data->start_b;
	if (tmp)
	{
		while (tmp->value != data->max)
		{
			data->max_up_to_top++;
			tmp = tmp->next;
		}
	}
}

static void	min_up_to_top_moves(t_data *data, char pile_name)
{
	t_elem	*tmp;

	tmp = NULL;
	if (pile_name == 'a')
		tmp = data->start_a;
	else if (pile_name == 'b')
		tmp = data->start_b;
	if (tmp)
	{
		while (tmp->value != data->min)
		{
			data->min_up_to_top++;
			tmp = tmp->next;
		}
	}
}

void	moves_up_to_top(t_data *data, char pile_name, int s_or_b)
{
	if (s_or_b == 1)
		min_up_to_top_moves(data, pile_name);
	else if (s_or_b == 2)
		max_up_to_top_moves(data, pile_name);
}
