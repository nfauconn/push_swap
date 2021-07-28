/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:26:06 by nfauconn          #+#    #+#             */
/*   Updated: 2021/07/28 18:17:46 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_end(t_data *data, char stack, int val)
{
	t_elem	**end;
	t_elem	*new;


	if (stack == 'a')
		end = &data->end_a;
	else
		end = &data->end_b;
	if (*end == NULL)
	{
		if (!(*end = (t_elem*)malloc(sizeof(t_elem))))
			error(data);
		(*end)->value = val;
		(*end)->next = *end;
		(*end)->prev = *end;
	}
	if (*end != NULL)
	{
		if (!(new = (t_elem*)malloc(sizeof(t_elem))))
			error(data);
		new->value = val;
		(*end)->prev->next = new;
		new->prev = (*end)->prev;
		new->next = (*end);
		(*end)->prev = new;
		(*end) = new;
	}
}
