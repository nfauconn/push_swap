/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_40_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:21:28 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 20:17:33 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_first_quarter(t_data *data, int n)
{
	if (n > data->first_q)
	{
		rotate_a(data);
		return ;
	}
	push_top_a_to_b(data);
}

static void	push_second_quarter(t_data *data, int n)
{
	if (n <= data->first_q || n > data->median)
	{
		rotate_a(data);
		return ;
	}
	push_top_a_to_b(data);
}

static void	push_third_quarter(t_data *data, int n)
{
	if (n <= data->median || n > data->third_q)
	{
		rotate_a(data);
		return ;
	}
	push_top_a_to_b(data);
}

static void	push_fourth_quarter(t_data *data, int n)
{
	if (n <= data->third_q)
	{
		rotate_a(data);
		return ;
	}
	push_top_a_to_b(data);
}

int	selected_quarter_push(t_data *data, int n, int quarter)
{
	if (quarter == 1)
		push_first_quarter(data, n);
	if (quarter == 2)
		push_second_quarter(data, n);
	if (quarter == 3)
		push_third_quarter(data, n);
	if (quarter == 4)
	{
		if (n == data->min)
			return (1);
		push_fourth_quarter(data, n);
	}
	return (0);
}
