/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:48:54 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/04 14:00:13 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	sa(t_dbstack *dbstack)
{
	int	tmp;

	if ((dbstack->size - dbstack->a) < 2)
		return ;
	tmp = dbstack->stacks[dbstack->a];
	dbstack->stacks[dbstack->a] = dbstack->stacks[dbstack->a + 1];
	dbstack->stacks[dbstack->a + 1] = tmp;
}

void	ra(t_dbstack *dbstack)
{
	int	tmp;
	int	i;

	i = dbstack->size - 1;
	tmp = dbstack->stacks[i];
	while (i > dbstack->a)
	{
		dbstack->stacks[i] = dbstack->stacks[i - 1];
		i--;
	}
	dbstack->stacks[i] = tmp;
}

void	rra(t_dbstack *dbstack)
{
	int	tmp;
	int	i;

	i = dbstack->a + 1;
	tmp = dbstack->stacks[i - 1];
	while (i < dbstack->size)
	{
		dbstack->stacks[i - 1] = dbstack->stacks[i];
		i++;
	}
	dbstack->stacks[i - 1] = tmp;
}

void	pa(t_dbstack *dbstack)
{
	if (dbstack->a == 0)
		return ;
	
	rrb(dbstack);
	dbstack->a--;
}
