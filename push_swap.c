/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:25:39 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/11 21:16:31 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_swap(t_data *data, char **argv)
{
	t_elem*tmp;

	parse(data, argv);
	if (sorted(data))
	{
		printf("data already sorted\n");
		return ;
	}
	if (data->stack_len <= 5)
		sort_less_5(data);

	tmp = data->start_a;
	printf("tmp value :%d\n", tmp->value);
	while (tmp->next != data->start_a)
	{
		tmp = tmp->next;
		printf("tmp value :%d\n", tmp->value);
	}
/*	else if (data->stack_len <= 100)
		insertion_solve_half(data);
	else
		insertion_solve_quarters(data);*/
}

int		main(int argc, char **argv)
{
	t_data	*data;
	
	data = NULL;
	if (argc >= 2)
	{
		data = init_data(data, argv);
		push_swap(data, argv);
	}
	free_pushswap(data);
	return (0);
}
