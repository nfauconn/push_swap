/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 12:27:19 by nfauconn          #+#    #+#             */
/*   Updated: 2021/07/28 15:23:43 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_data *data)
{
	write(2, "Error\n", 6);
	if (data)
		free(data);
	exit(EXIT_FAILURE);
}
