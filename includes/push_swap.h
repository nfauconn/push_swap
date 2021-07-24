/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:23:39 by nfauconn          #+#    #+#             */
/*   Updated: 2021/07/24 17:40:12 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_elem
{
	int				value;
	struct s_elem	*prev;
	struct s_elem	*next;
}				t_elem;

typedef struct	s_data
{
	t_elem			*start_a;
	t_elem			*start_b;
	int				stack_len;
	char			**argv;
}				t_data;

void	error(t_data *data);
void	fill_data(t_data *data, char **argv);
void	init_data(t_data *data, char **argv);
int		main(int argc, char **argv);

#endif