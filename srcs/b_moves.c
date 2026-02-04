/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:48:54 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/04 13:37:13 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	sb(t_dbstack *dbstack)
{
	int	tmp;

	if (dbstack->a < 2)
		return ;
	tmp = dbstack->stacks[0];
	dbstack->stacks[0] = dbstack->stacks[1];
	dbstack->stacks[1] = tmp;
}

void	rb(t_dbstack *dbstack)
{
	int	tmp;
	int	i;

	i = dbstack->a - 1;
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
	while (i < dbstack->a)
	{
		dbstack->stacks[i - 1] = dbstack->stacks[i];
		i++;
	}
	dbstack->stacks[i - 1] = tmp;
}

void	pb(t_dbstack *dbstack)
{
	if (dbstack->a >= dbstack->size)
		return ;
	dbstack->a++;
	rb(dbstack);
}
