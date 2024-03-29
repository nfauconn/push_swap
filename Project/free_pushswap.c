/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:43:32 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 20:18:16 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_list(t_elem *list)
{
	t_elem	*tmp;
	t_elem	*to_free;

	tmp = list->next;
	while (tmp != list)
	{
		to_free = tmp;
		tmp = tmp->next;
		free(to_free);
	}
	free(tmp);
}

void	free_pushswap(t_data *data)
{
	if (data)
	{
		if (data->start_a)
			free_list(data->start_a);
		if (data->start_b)
			free_list(data->start_b);
		free(data);
	}
}
