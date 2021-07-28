/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:58:26 by nfauconn          #+#    #+#             */
/*   Updated: 2021/07/28 18:18:00 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*init_data(t_data *data, char **argv)
{
	if (!(data = (t_data*)malloc(sizeof(t_data))))
		exit(1);
	data->end_a = NULL;
	data->end_b = NULL;
	data->stack_len = 0;
	data->argv = argv;
	return(data);
}