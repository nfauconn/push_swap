/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:23:39 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/25 13:57:34 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_elem
{
	int				value;
	struct s_elem	*prev;
	struct s_elem	*next;
}				t_elem;

typedef struct s_data
{
	t_elem			*start_a;
	t_elem			*start_b;
	int				pile_len;
	char			**argv;
	int				min;
	int				max;
	int				median;
	int				first_q;
	int				third_q;
	int				min_up_to_top;
	int				min_down_to_top;
	int				max_up_to_top;
	int				max_down_to_top;
	int				min_chosen;
	int				max_chosen;
	int				rotate_later;
	int				do_write;
}				t_data;

int		cdbll_len(t_data *data, char pile_name);
void	del_top(t_data *data, char pile_name);
void	error(t_data *data);
void	find_shortest_move(t_data *data);
void	find_max_min(t_data *data, char pile_name);
void	find_quantiles(t_data *data, t_elem *elem, char pile_name);
void	free_pushswap(t_data *data);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_data	*init_data(t_data *data, char **argv);
void	insert_top(t_data *data, char pile_name, int val);
void	insert_end(t_data *data, char pile_name, int val);
int		ft_atoi(t_data *data, const char *s, int neg);
int		ft_isdigit(int c);
int		is_sorted(t_data *data);
int		main(int argc, char **argv);
void	moves_down_to_top(t_data *data, char pile_name, int min_or_max);
void	moves_up_to_top(t_data *data, char pile_name, int min_or_max);
void	parse(t_data *data);
void	push_top_a_to_b(t_data *data);
void	push_top_b_to_a(t_data *data);
void	reinitialize_moves(t_data *data);
void	rotate_and_push_to_a(t_data *data);
void	reverse_rotate_a(t_data *data);
void	reverse_rotate_b(t_data *data);
void	reverse_rotate_a_b(t_data *data);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rotate_a_b(t_data *data);
int		selected_quarter_push(t_data *data, int n, int quarter);
void	sort_less_5(t_data *data);
void	sort_less_40(t_data *data);
void	sort_more_40(t_data *data);
void	sorted_push_to_a(t_data *data, t_elem *tmp, t_elem *end);
void	swap_top_a(t_data *data);
void	swap_top_b(t_data *data);
void	swap_a_swap_b(t_data *data);

#endif