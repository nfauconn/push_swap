/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:25:39 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 20:18:10 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_data *data)
{
	parse(data);
	if (is_sorted(data))
		return ;
	if (data->pile_len <= 5)
		sort_less_5(data);
	else if (data->pile_len <= 40)
		sort_less_40(data);
	else
		sort_more_40(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc >= 2)
	{
		data = init_data(data, argv);
		push_swap(data);
	}
	free_pushswap(data);
	return (0);
}
