/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:48:54 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/07 14:34:22 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	sb(t_dbstack *dbstack)
{
	int	tmp;

	if (dbstack->b_size < 2)
		return ;
	tmp = dbstack->stacks[0];
	dbstack->stacks[0] = dbstack->stacks[1];
	dbstack->stacks[1] = tmp;
}

void	rb(t_dbstack *dbstack)
{
	int	tmp;
	int	i;

	i = dbstack->b_size - 1;
	tmp = dbstack->stacks[i];
	while (i > 0)
	{
		dbstack->stacks[i] = dbstack->stacks[i - 1];
		i--;
	}
	dbstack->stacks[i] = tmp;
}

void	rrb(t_dbstack *dbstack)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = dbstack->stacks[0];
	while (i < dbstack->b_size)
	{
		dbstack->stacks[i - 1] = dbstack->stacks[i];
		i++;
	}
	dbstack->stacks[i - 1] = tmp;
}

void	pb(t_dbstack *dbstack)
{
	if (dbstack->b_size >= dbstack->a_size + dbstack->b_size)
		return ;
	dbstack->b_size++;
	dbstack->a_size--;
}
