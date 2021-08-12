/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:08:54 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/12 09:02:43 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_2(t_data *data)
{
	t_elem	*tmp;

	tmp = data->start_a;
	if (tmp->value > tmp->next->value)
		swap_2first_a(data);
}

static void		sort_3(t_data *data)
{
	t_elem	*end;
	t_elem	*tmp;
	int		nb_rra;

	find_max(data, 'a');
	nb_rra = big_to_end(data->start_a, data->max);
	if (nb_rra >= 1)
		while (nb_rra-- > 1)
			reverse_rotate_a(data);
	end = data->start_a;
	tmp = end->next;
	if (end->value > tmp->value)
		swap_2first_a(data);
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
	t_elem	*end_a;
	t_elem	*tmp;

	end_a = data->start_a->prev;
	find_median(data, 'a');
	printf("median : %d\n", data->median);
	while (1)
	{
		if (data->start_a->value < data->median)
			push_top_a_to_b(data);
		else
			rotate_a(data);
		printf("data->start_a->value : %d\n", data->start_a->value);
		if (data->start_a == end_a)
		{
			if (data->start_a->value < data->median)
				push_top_a_to_b(data);
			break;
		}
	}
	sort_3(data);
	if (data->start_b)
	{
		tmp = data->start_b->next;
		if (data->start_b->value < tmp->value)
			swap_2first_b(data);
		push_top_b_to_a(data);
		push_top_b_to_a(data);
	}
}

void			sort_less_5(t_data *data)
{
	if (data->stack_len == 2)
		sort_2(data);
	else if (data->stack_len == 3)
		sort_3(data);
	else if (data->stack_len == 4)
		sort_4(data);
	else if (data->stack_len <= 5)
		sort_5(data);
}