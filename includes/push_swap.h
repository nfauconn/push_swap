/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:23:39 by nfauconn          #+#    #+#             */
/*   Updated: 2021/07/28 18:09:16 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct	s_elem
{
	int				value;
	struct s_elem	*prev;
	struct s_elem	*next;
}				t_elem;

typedef struct	s_data
{
	t_elem			*end_a;
	t_elem			*end_b;
	int				stack_len;
	char			**argv;
}				t_data;

void	insert_end(t_data *data, char stack, int val);
int		atoi_push_swap(t_data *data, const char *s, int neg);
void	error(t_data *data);
void	parse(t_data *data, char **argv);
t_data	*init_data(t_data *data, char **argv);
int		main(int argc, char **argv);

#endif