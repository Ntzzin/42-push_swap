/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbasen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:20:32 by nado-nas          #+#    #+#             */
/*   Updated: 2026/01/28 12:06:46 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/**
 * @brief Prints a number in an arbitrary ’base’
 * @param nbr The number to be printed.
 * @param base The base in which the number will be represented
 * @param blen The lenght of ’base'
 * @return The number of characters printed
 * @note __int128 is used so the function can handle both
 * unsigned long long values and negative numbers safely.
 */
int	ft_putbasen(__int128 nbr, char *base, int blen)
{
	int	s;

	s = 0;
	if (nbr < 0)
	{
		s += ft_putcharn('-');
		nbr *= -1;
	}
	if (nbr >= blen)
		s += ft_putbasen(nbr / blen, base, blen);
	s += ft_putcharn(base[nbr % blen]);
	return (s);
}
