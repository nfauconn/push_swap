/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:50:12 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/13 13:47:54 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_median(t_data *data, char pile_name)
{
	int	*sorted_array;

	data->pile_len = cdbll_len(data, pile_name);
	sorted_array = annex_sorted_array(data, data->pile_len, pile_name);
	data->median = sorted_array[data->pile_len / 2];
}
