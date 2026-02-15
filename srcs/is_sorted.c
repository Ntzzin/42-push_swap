/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:40:57 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/15 16:16:34 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	is_sorted(t_dbstack *dbstack)
{
	int	i;

	i = 1;
	while (i < dbstack->a_size + dbstack->b_size)
	{
		if (dbstack->stacks[i - 1] > dbstack->stacks[i])
			return (0);
		i++;
	}
	return (1);
}
