/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:25:39 by nfauconn          #+#    #+#             */
/*   Updated: 2021/07/14 16:17:11 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_data	*root;
	
	root = NULL;
	if (argc < 2)
		return (1);
	init_data(root, argv);
	fill_data(root, argv);
	
	return (0);
}

