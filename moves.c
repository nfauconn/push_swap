/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:15:14 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/11 22:02:33 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		big_to_end(t_elem *end, int max)
{
	t_elem	*tmp;
	int		nb_rra;

	nb_rra = 0;
	if (end)
	{
		tmp = end->prev;
		while (tmp->value != max)
		{
			nb_rra++;
			tmp = tmp->prev;
		}
		nb_rra++;
	}
	return (nb_rra);
}