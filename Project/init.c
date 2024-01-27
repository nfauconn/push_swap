/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:58:26 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 20:18:13 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*init_data(t_data *data, char **argv)
{
	data = (t_data *)malloc(sizeof (t_data));
	if (!data)
		exit(1);
	data->start_a = NULL;
	data->start_b = NULL;
	data->pile_len = 0;
	data->argv = argv;
	data->median = 0;
	data->first_q = 0;
	data->third_q = 0;
	data->min = 0;
	data->max = 0;
	data->min_up_to_top = 0;
	data->min_down_to_top = 0;
	data->max_up_to_top = 0;
	data->max_down_to_top = 0;
	data->min_chosen = 0;
	data->max_chosen = 0;
	data->rotate_later = 0;
	data->do_write = 1;
	return (data);
}

void	reinitialize_moves(t_data *data)
{
	data->min = 0;
	data->max = 0;
	data->min_up_to_top = 0;
	data->min_down_to_top = 0;
	data->max_up_to_top = 0;
	data->max_down_to_top = 0;
	data->min_chosen = 0;
	data->max_chosen = 0;
}
