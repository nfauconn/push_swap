/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 15:49:56 by nfauconn          #+#    #+#             */
/*   Updated: 2021/07/24 17:56:48 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		check_duplicate(t_data *data, t_elem *elem, int val)
{
	while (elem->next != data->start_a)
	{
		if (elem->value == val)
			error(data);
		elem = elem->next;
	}
}

static void		put_in_stack(t_data *data, char *nb, int neg)
{
	int	val;

	val = atoi_pushswap(data, nb, neg);
	insert_end(data, 'a', val);
	if (data->pile_len++ > 1)
		check_duplicate(data, data->start_a, val);
}

static void		fill_a(t_data *data, char *s)
{
	int		neg;
	char	*tmp;
	
	neg = 0;
	tmp = NULL;
	while (*s)
	{
		while (*s == '+' || *s == '-' || *s == 32 || (*s >= 9 && *s <= 13))
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
			put_in_stack(data, ft_substr(tmp, 0, s - tmp), neg);
			if (*s && ((*s != 32) || (*s < 9 && *s > 13)))
				error(data);
		}
	}
}

static void		check_valid_char(t_data *data)
{
	int		i;
	char	*s;

	i = 1;
	s = data->argv[i];
	while (s)
	{
		while (*s)
		{
			if (*s == ' ' || ft_isdigit(*s))
				s++;
			else if (*s == '-' && ft_isdigit(*(s + 1)) &&
						(s == data->argv[i] || *(s - 1) == ' '))
				s++;
			else if (*s == '+' && ft_isdigit(*(s + 1)) &&
						(s == data->argv[i] || *(s - 1) == ' '))
				s++;
			else
				error(data);
		}
		s = data->argv[++i];
	}
}

void			parse(t_data *data, char **argv)
{
	int	i;

	i = 1;
	check_valid_char(data);
	while (argv[i])
	{
		fill_a(data, argv[i]);
		i++;
	}
}