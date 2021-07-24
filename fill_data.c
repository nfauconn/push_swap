/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 15:49:56 by nfauconn          #+#    #+#             */
/*   Updated: 2021/07/24 17:56:48 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		duplicate(t_data *data, )
{
	
}

static void		fill_a(t_data *data, char *s)
{
	while(duplicate(data))
	data->stack_len++;
}

static void		check_valid_char(t_data *data, char *s)
{
	while (*s && ((ft_isdigit(*s)) || *s == '+' || *s == '-' 
								|| *s == 32 || (*s >= 9 && *s <= 13)))
		s++;
	if (*s)
		error(data);
	return ;
}

static void		parse(t_data *data, char *s)
{
	check_valid_char(data, s);
	fill_a(data, s);
}

void			fill_data(t_data *data, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		parse(data, argv[i]);
		i++;
	}
}