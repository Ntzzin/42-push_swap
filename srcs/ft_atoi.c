/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:02:32 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/15 17:04:29 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

/**
 * @brief Parses an string respecting the push_swap's 
 * specifications. Basically this function mimics atoi(3) 
 * with extra functionalities, for instance it quits if the
 * passed string is not a valid number input for atoi(3).
 * @param nptr The address of the string.
 * @return The number that the string represents
 * @warning This function 
*/
int	parse(char **nptr)
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
		exit_and_free(NULL);
	return (sign * res);
}
