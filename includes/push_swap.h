/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:23:39 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/12 14:33:32 by nfauconn         ###   ########.fr       */
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
	t_elem			*start_a;
	t_elem			*start_b;
	int				stack_len;
	char			**argv;
	int				*sorted_array;
	int				min;
	int				max;
	int				median;
}				t_data;

int			*annex_sorted_array(t_data *data, int len, char stack);
int			atoi_pushswap(t_data *data, const char *s, int neg);
int			big_to_end(t_elem *end, int max);
void		del_top(t_data *data, char stack);
void		error(t_data *data);
void		find_median(t_data *data, char stack);
void		find_min(t_data *data, char stack);
void		find_max(t_data *data, char stack);
void		find_max_min(t_data *data, char stack);
int			cdbll_len(t_data *data, char stack);
void		free_pushswap(t_data *data);
t_data		*init_data(t_data *data, char **argv);
void		insert_top(t_data *data, char stack, int val);
void		insert_end(t_data *data, char stack, int val);
int			main(int argc, char **argv);
void		parse(t_data *data, char **argv);
void		push_top_b_to_a(t_data *data);
void		push_top_a_to_b(t_data *data);
void		reverse_rotate_a(t_data *data);
void		rotate_a(t_data *data);
void		search_duplicates(t_data *data, int len);
void		sort_less_5(t_data *data);
void			sort_less_100(t_data *data);
int			sorted(t_data *data);
void		swap_2first_a(t_data *data);
void		swap_2first_b(t_data *data);


#endif