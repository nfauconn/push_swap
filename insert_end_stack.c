/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_end_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:26:06 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/11 14:46:14 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_end(t_data *data, char stack, int val)
{
	t_elem	**end;
	t_elem	*new;

	if (stack == 'a')
		end = &data->start_a;
	else
		end = &data->start_b;
	if (*end)
	{
		if (!(new = (t_elem*)malloc(sizeof(t_elem))))
			error(data);
		new->next = (*end);
		new->prev = (*end)->prev;
		(*end)->prev = new;
		new->prev->next = new;
		new->value = val;
	}
	else
	{
		if (!(*end = (t_elem*)malloc(sizeof(t_elem))))
			error(data);
		(*end)->next = *end;
		(*end)->prev = *end;
		(*end)->value = val;
	}
}
