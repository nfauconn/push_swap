/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdbll_change_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:52:41 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/13 13:46:02 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_top(t_data *data, char pile_name)
{
	t_elem	*tmp;
	t_elem	**top;

	if (pile_name == 'a')
		top = &data->start_a;
	else
		top = &data->start_b;
	if (*top)
	{
		if ((*top)->next == *top)
		{
			free(*top);
			*top = NULL;
		}
		else
		{
			tmp = *top;
			*top = (*top)->next;
			tmp->prev->next = *top;
			(*top)->prev = tmp->prev;
			free(tmp);
		}
	}
}

void	insert_top(t_data *data, char pile_name, int val)
{
	t_elem	*new;
	t_elem	**top;

	if (pile_name == 'a')
		top = &data->start_a;
	else
		top = &data->start_b;
	if (*top)
	{
		new = (t_elem *)malloc(sizeof(t_elem));
		if (!new)
			error(data);
		new->next = *top;
		new->prev = (*top)->prev;
		(*top)->prev = new;
		new->prev->next = new;
		new->value = val;
		*top = (*top)->prev;
	}
	else
	{
		*top = (t_elem *)malloc(sizeof(t_elem));
		if (!top)
			error(data);
		(*top)->next = *top;
		(*top)->prev = *top;
		(*top)->value = val;
	}
}
