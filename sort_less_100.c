/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:31:46 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/13 12:38:26 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b_upper_median(t_data *data)
{
	int		done;
	t_elem	*tmp;
	t_elem	*end_a;

	done = 0;
	tmp = data->start_a;
	end_a = data->start_a->prev;
	find_max_min(data, 'a');
	while (!done)
	{
		if (tmp == end_a)
			done = 1;
		if (tmp->value <= data->median)
			push_top_a_to_b(data);
		rotate_a(data);
		if (done)
			break ;
		tmp = data->start_a;
	}
}


void	sort_less_100(t_data *data)
{
	int		done;
	t_elem	*tmp;
	t_elem	*end_a;

	done = 0;
	tmp = data->start_a;
	end_a = data->start_a->prev;
	find_median(data, 'a');
	while (!done)
	{
		if (tmp == end_a)
			done = 1;
		push_to_b_upper_median(data);
		tmp = tmp->next;
		rotate_a(data);
	}
}
