/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdbll_change_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:26:06 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/13 13:46:02 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_end(t_data *data, char pile_name, int val)
{
	t_elem	*new;
	t_elem	**end;

	if (pile_name == 'a')
		end = &data->start_a;
	else
		end = &data->start_b;
	if (*end)
	{
		new = (t_elem*)malloc(sizeof(t_elem));
		if (!new)
			error(data);
		new->next = (*end);
		new->prev = (*end)->prev;
		(*end)->prev = new;
		new->prev->next = new;
		new->value = val;
	}
	else
	{
		*end = (t_elem*)malloc(sizeof(t_elem));
		if (!*end)
			error(data);
		(*end)->next = *end;
		(*end)->prev = *end;
		(*end)->value = val;
	}
}
