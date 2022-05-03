/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:29:57 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/25 11:41:30 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_duplicate(t_data *data, int val)
{
	t_elem	*elem;
	t_elem	*end;

	elem = data->start_a;
	end = data->start_a;
	while (elem->next != end)
	{
		if (elem->value == val)
			error(data);
		elem = elem->next;
	}
}

static void	put_in_pile(t_data *data, char *nb, int neg)
{
	int	val;

	val = ft_atoi(data, nb, neg);
	insert_end(data, 'a', val);
	data->pile_len++;
	find_duplicate(data, val);
	free(nb);
}

static void	fill_a(t_data *data, char *s)
{
	int		neg;
	char	*tmp;
	char	*buf;

	tmp = NULL;
	while (*s)
	{
		neg = 0;
		while (*s == '+' || *s == '-' || *s == ' ')
		{	
			if (*s == '-')
				neg = 1;
			s++;
		}
		if (ft_isdigit(*s))
		{
			tmp = s;
			while (ft_isdigit(*s))
				s++;
			buf = ft_substr(tmp, 0, s - tmp);
			put_in_pile(data, buf, neg);
			if (*s && ((*s != ' ')))
				error(data);
		}
	}
}

static void	check_valid_args(t_data *data, char	*s)
{
	while (*s == ' ')
		s++;
	if (!*s)
		error(data);
	while (*s)
	{
		if (*s == ' ' || ft_isdigit(*s))
			s++;
		else if (*s == '-' || *s == '+')
		{
			s++;
			if (!ft_isdigit(*s))
				error(data);
			s++;
		}
		else
			error(data);
	}
}

void	parse(t_data *data)
{
	int	i;

	i = 1;
	while (data->argv[i])
	{
		check_valid_args(data, data->argv[i]);
		fill_a(data, data->argv[i]);
		i++;
	}
}
