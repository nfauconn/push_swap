/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdbll_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:43:27 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 20:19:32 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cdbll_len(t_data *data, char pile_name)
{
	t_elem	*tmp;
	t_elem	*end;
	int		len;

	len = 0;
	if (pile_name == 'a')
		tmp = data->start_a;
	else
		tmp = data->start_b;
	if (tmp)
	{
		if (pile_name == 'a')
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
