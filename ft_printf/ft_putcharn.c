/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:55:55 by nado-nas          #+#    #+#             */
/*   Updated: 2026/01/28 12:06:49 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/**
 * @return The amount of characters printed
 */
int	ft_putcharn(char c)
{
	write(1, &c, 1);
	return (1);
}
