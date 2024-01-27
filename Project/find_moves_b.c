/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:18:28 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 20:18:29 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 17:51:28 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/14 10:46:27 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	moves_min(t_data *data)
{
	t_elem	*tmp;

	tmp = data->start_b;
	if (tmp)
	{
		moves_up_to_top(data, 'b', 1);
		moves_down_to_top(data, 'b', 1);
		if (data->min_up_to_top <= data->min_down_to_top)
			data->min_down_to_top = -1;
		else
			data->min_up_to_top = -1;
	}
}

static void	moves_max(t_data *data)
{
	t_elem	*tmp;

	tmp = data->start_b;
	if (tmp)
	{
		moves_up_to_top(data, 'b', 2);
		moves_down_to_top(data, 'b', 2);
		if (data->max_up_to_top <= data->max_down_to_top)
			data->max_down_to_top = -1;
		else
			data->max_up_to_top = -1;
	}
}

static void	find_chosen(t_data *data)
{
	int	mi_u;
	int	mi_d;
	int	ma_u;
	int	ma_d;

	mi_u = data->min_up_to_top;
	mi_d = data->min_down_to_top;
	ma_u = data->max_up_to_top;
	ma_d = data->max_down_to_top;
	if (ma_u != -1 && (ma_u >= mi_u && ma_u >= mi_d))
		data->max_up_to_top = -1;
	else if (ma_d != -1 && (ma_d >= mi_u && ma_d >= mi_d))
		data->max_down_to_top = -1;
	else if (mi_u != -1 && (mi_u >= ma_u && mi_u >= ma_d))
		data->min_up_to_top = -1;
	else if (mi_d != -1 && (mi_d >= ma_u && mi_d >= ma_d))
		data->min_down_to_top = -1;
}

void	find_shortest_move(t_data *data)
{
	moves_min(data);
	moves_max(data);
	find_chosen(data);
	if (data->min_up_to_top != -1 || data->min_down_to_top != -1)
		data->min_chosen = 1;
	else if (data->max_up_to_top != -1 || data->max_down_to_top != -1)
		data->max_chosen = 1;
}
