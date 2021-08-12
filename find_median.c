/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:50:12 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/11 16:56:13 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		find_median(t_data *data, char stack)
{
	int		*sorted_array;

	data->stack_len = cdbll_len(data, stack);
	sorted_array = annex_sorted_array(data, data->stack_len, stack);
	data->median = sorted_array[data->stack_len/2];
}