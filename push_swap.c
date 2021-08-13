/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:25:39 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/13 13:47:54 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_swap(t_data *data, char **argv)
{
	t_elem	*tmp_a;
	t_elem	*tmp_b;

	parse(data, argv);
	if (is_sorted(data))
	{
		printf("data already sorted\n");
		return ;
	}
	if (data->pile_len <= 5)
		sort_less_5(data);
	else if (data->pile_len <= 100)
		sort_less_100(data);



	tmp_a = data->start_a;
	printf("start_a value :%d\n", tmp_a->value);
	while (tmp_a->next != data->start_a)
	{
		tmp_a = tmp_a->next;
		printf("next_a value :%d\n", tmp_a->value);
	}
	printf("\n------------------------------------------------------------\n");
	if (data->start_b)
	{
		tmp_b = data->start_b;
		printf("start_b value :%d\n", tmp_b->value);
		while (tmp_b->next != data->start_b)
		{
			tmp_b = tmp_b->next;
			printf("next_b value :%d\n", tmp_b->value);
		}
	}

/*	
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
