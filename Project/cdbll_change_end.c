/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdbll_change_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:26:06 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 20:19:46 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_new(t_data *data, char pile_name, int val)
{
	t_elem	**end;
	t_elem	*new;

	if (pile_name == 'a')
		end = &data->start_a;
	else
		end = &data->start_b;
	new = (t_elem *)malloc(sizeof (t_elem));
	if (!new)
		error(data);
	new->next = (*end);
	new->prev = (*end)->prev;
	(*end)->prev = new;
	new->prev->next = new;
	new->value = val;
}

void	insert_end(t_data *data, char pile_name, int val)
{
	t_elem	**end;

	if (pile_name == 'a')
		end = &data->start_a;
	else
		end = &data->start_b;
	if (*end)
		insert_new(data, pile_name, val);
	else
	{
		*end = (t_elem *)malloc(sizeof (t_elem));
		if (!*end)
			error(data);
		(*end)->next = *end;
		(*end)->prev = *end;
		(*end)->value = val;
	}
}
