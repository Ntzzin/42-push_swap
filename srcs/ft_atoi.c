/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:02:32 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/03 14:17:12 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	ft_atoi(char **nptr)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while (**nptr == ' ' || (**nptr >= '\t' && **nptr <= '\r'))
		(*nptr)++;
	if (**nptr == '-' || **nptr == '+')
		if (*(*nptr)++ == '-')
			sign = -1;
	while (**nptr >= '0' && **nptr <= '9')
	{
		res = (res * 10) + (**nptr - '0');
		(*nptr)++;
	}
	if ((**nptr && **nptr != ' ') || res > INT_MAX || res < INT_MIN)
		ft_exit_and_free(NULL);
	return (sign * res);
}
