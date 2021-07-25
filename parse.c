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

/*static int		duplicate(t_data *data)
{
	
}*/

static void		put_in_stack(t_data *data, char *nb, int neg)
{
	int	val;

	val = atoi_push_swap(data, nb, neg);
	printf("val = %d\n", val);
//	data->stack_len++ segfault??????????????!!!!!!!!!!!!;
}

static void		fill_a(t_data *data, char *s)
{
	int		neg;
	char	*tmp;
	
	neg = 0;
	tmp = NULL;
	while (*s)
	{
		printf("boucle ok'\n");
		while (*s == '+' || *s == '-' || *s == 32 || (*s >= 9 && *s <= 13))
		{	
			if (*s == '-')
				neg = 1;
			s++;
		}
		if (ft_isdigit(*s))
		{
			tmp = s;
			while(ft_isdigit(*s))
				s++;
			put_in_stack(data, ft_substr(tmp, 0, s - tmp), neg);
			printf("reste a parser : %s\n", s);
		}
	}
}

static void		check_valid_char(t_data *data, char *s)
{
	int	i;

	i = 0;
	while (s[i] && (ft_isdigit(s[i])
				|| (s[i] == '+' && ft_isdigit(s[i+1])) 
				|| (s[i] == '-' && ft_isdigit(s[i+1]))
				|| s[i] == 32 || (s[i] >= 9 && s[i] <= 13)))
		i++;
	if (s[i])
		error(data);
	return ;
}

void			parse(t_data *data, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		check_valid_char(data, argv[i]);
		fill_a(data, argv[i]);
		i++;
	}
}