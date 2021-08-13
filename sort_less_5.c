/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:08:54 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/13 15:22:53 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_2(t_data *data)
{
	t_elem	*tmp;

	tmp = data->start_a;
	if (tmp->value > tmp->next->value)
		swap_top_a(data);
}

static void		sort_3(t_data *data)
{
	t_elem	*end;
	t_elem	*tmp;

	find_max(data, 'a');
	moves_to_end(data, 'a', 2);
	if (data->max_to_end >= 1)
		while (data->max_to_end-- > 1)
			reverse_rotate_a(data);
	end = data->start_a;
	tmp = end->next;
	if (end->value > tmp->value)
		swap_top_a(data);
}

static void		sort_4(t_data *data)
{
	t_elem 	*tmp;

	tmp = data->start_a;
	find_max_min(data, 'a');
	while (tmp->value != data->min)
	{
		rotate_a(data);
		tmp = tmp->next;
	}
	push_top_a_to_b(data);
	sort_3(data);
	push_top_b_to_a(data);
}

static void		sort_5(t_data *data)
{
	int		done;
	t_elem	*end_a;
	t_elem	*tmp;

	done = 0;
	end_a = data->start_a->prev;
	find_median(data, 'a');
	while (!done)
	{
		if (data->start_a == end_a)
			done = 1;
		if (data->start_a->value < data->median)
			push_top_a_to_b(data);
		else
			rotate_a(data);
	}
	sort_3(data);
	tmp = data->start_b->next;
	if (data->start_b->value < tmp->value)
		swap_top_b(data);
	push_top_b_to_a(data);
	push_top_b_to_a(data);
}

void			sort_less_5(t_data *data)
{
	if (data->pile_len == 2)
		sort_2(data);
	else if (data->pile_len == 3)
		sort_3(data);
	else if (data->pile_len == 4)
		sort_4(data);
	else if (data->pile_len <= 5)
		sort_5(data);
}