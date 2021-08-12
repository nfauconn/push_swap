/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_or_del_top_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:52:41 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/11 21:17:15 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_top(t_data *data, char stack)
{
	t_elem		**top;
	t_elem		*tmp;

	if (stack == 'a')
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

void	insert_top(t_data *data, char stack, int val)
{
	t_elem		**top;
	t_elem		*tmp;

	if (stack == 'a')
		top = &data->start_a;
	else
		top = &data->start_b;
	if (*top)
	{
		if (!(tmp = (t_elem *)malloc(sizeof(t_elem))))
			error(data);
		tmp->next = *top;
		tmp->prev = (*top)->prev;
		(*top)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->value = val;
		*top = (*top)->prev;
	}
	else
	{
		if (!(*top = (t_elem *)malloc(sizeof(t_elem))))
			error(data);
		(*top)->next = *top;
		(*top)->prev = *top;
		(*top)->value = val;
	}
}
