/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:02:30 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/26 20:17:57 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(t_data *data, const char *s, int neg)
{
	int					sign;
	long long			nbr;

	sign = 1;
	nbr = 0;
	if (neg)
		sign *= -1;
	while (ft_isdigit(*s))
	{
		nbr = (nbr * 10) + (*s - '0');
		s++;
	}
	if (nbr > 2147483647)
	{
		if (nbr == 2147483648 && sign == -1)
			return (-2147483648);
		error(data);
	}
	return ((int)(nbr * sign));
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*source;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = (unsigned char *) dst;
	source = (const unsigned char *)src;
	while (n--)
		*dest++ = *source++;
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start + len > s_len)
		len = s_len - start;
	if (start > s_len)
	{
		new = (char *)malloc(sizeof (char) * 1);
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	new = (char *)malloc(sizeof (char) * (len + 1));
	if (!new)
		return (NULL);
	new = (char *)ft_memcpy(new, s + start, len + 1);
	new[len] = '\0';
	return (new);
}
