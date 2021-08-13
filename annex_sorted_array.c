/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_sorted_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:18:28 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/13 13:42:44 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*annex_sorted_array(t_data *data, int len, char pile_name)
{
	int		i;
	int		*sorted_array;
	t_elem	*tmp;

	i = 0;
	sorted_array = (int*)malloc(sizeof(int) * (len));
	if (!sorted_array)
		error(data);
	if (pile_name == 'a')
		tmp = data->start_a;
	else
		tmp = data->start_b;
	while (i < len)
	{	
		sorted_array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	sorted_array = sort_int_tab(sorted_array, len);
	return (sorted_array);
}
