/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:58:26 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/13 15:32:14 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*init_data(t_data *data, char **argv)
{
	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
		exit(1);
	data->start_a = NULL;
	data->start_b = NULL;
	data->pile_len = 0;
	data->argv = argv;
	data->sorted_array = NULL;
	data->min = 0;
	data->max = 0;
	data->min_to_start = 0;
	data->max_to_start = 0;
	data->min_to_end = 0;
	data->max_to_end = 0;
	data->min_chosen = 0;
	data->max_chosen = 0;
	return (data);
}
