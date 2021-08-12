/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdbll_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:43:27 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/11 17:01:39 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		cdbll_len(t_data *data, char stack)
{
	t_elem	*tmp;
	t_elem	*end;
	int		len;

	len = 0;
	if (stack == 'a')
		tmp = data->start_a;
	else
		tmp = data->start_b;
	if (tmp)
	{
		if (stack == 'a')
			end = data->start_a->prev;
		else
			end = data->start_b->prev;
	}
	while (tmp)
	{
		len++;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
	return (len);
}
