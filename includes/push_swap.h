/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:23:39 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/13 15:38:22 by nfauconn         ###   ########.fr       */
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
	int				pile_len;
	char			**argv;
	int				*sorted_array;
	int				min;
	int				max;
	int				median;
	int				min_to_start;
	int				max_to_start;
	int				min_to_end;
	int				max_to_end;
	int				min_chosen;
	int				max_chosen;
}				t_data;

int			*annex_sorted_array(t_data *data, int len, char pile_name);
int			atoi_pushswap(t_data *data, const char *s, int neg);
int			big_to_end(t_elem *end, int max);
int			cdbll_len(t_data *data, char pile_name);
void		del_top(t_data *data, char pile_name);
void		error(t_data *data);
void		find_median(t_data *data, char pile_name);
void		find_min(t_data *data, char pile_name);
void		find_max(t_data *data, char pile_name);
void		find_max_min(t_data *data, char pile_name);
void		free_pushswap(t_data *data);
t_data		*init_data(t_data *data, char **argv);
void		insert_top(t_data *data, char pile_name, int val);
void		insert_end(t_data *data, char pile_name, int val);
int			is_sorted(t_data *data);
int			main(int argc, char **argv);
void		moves_to_end(t_data *data, char pile_name, int min_or_max);
void		moves_to_start(t_data *data, char pile_name, int min_or_max);
void		parse(t_data *data, char **argv);
void		push_top_b_to_a(t_data *data);
void		push_top_a_to_b(t_data *data);
void		push_to_b_upper_median(t_data *data);
void		reverse_rotate_a(t_data *data);
void		rotate_a(t_data *data);
void		search_duplicates(t_data *data, int len);
void		sort_less_5(t_data *data);
void		sort_less_100(t_data *data);
void		swap_top_a(t_data *data);
void		swap_top_b(t_data *data);


#endif