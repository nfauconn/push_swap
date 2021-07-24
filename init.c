/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:58:26 by nfauconn          #+#    #+#             */
/*   Updated: 2021/07/24 17:40:21 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *data, char **argv)
{
	if (!(data = (t_data*)malloc(sizeof(t_data))))
		exit(1);
	data->start_a = NULL;
	data->start_b = NULL;
	data->stack_len = 0;
	data->argv = argv;
	write(1, "init ok\n", 8);
}