/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_quantiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:24:45 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/24 17:26:19 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_tab(int *tab, int len)
{
	long	tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (i < len - 1)
	{
		if (tab[i] <= tab[i + 1])
			i++;
		else
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
	}
}

void	find_quantiles(t_data *data, t_elem *elem, char pile_name)
{
	int	*tab;
	int	i;
	int	quarter_len;

	i = 0;
	data->pile_len = cdbll_len(data, pile_name);
	quarter_len = data->pile_len / 4;
	tab = (int *)malloc(sizeof (int) * (data->pile_len + 1));
	if (!tab)
		error(data);
	while (i < data->pile_len)
	{
		tab[i++] = elem->value;
		elem = elem->next;
	}
	sort_tab(tab, data->pile_len);
	data->first_q = tab[quarter_len];
	data->median = tab[quarter_len * 2];
	data->third_q = tab[quarter_len * 3];
	free(tab);
}
