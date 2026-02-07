/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:48:54 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/07 14:42:51 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	sa(t_dbstack *dbstack)
{
	int	tmp;

	if (dbstack->a_size < 2)
		return ;
	tmp = dbstack->stacks[dbstack->b_size];
	dbstack->stacks[dbstack->b_size] = dbstack->stacks[dbstack->b_size + 1];
	dbstack->stacks[dbstack->b_size + 1] = tmp;
}

void	ra(t_dbstack *dbstack)
{
	int	tmp;
	int	i;

	i = dbstack->b_size + 1;
	tmp = dbstack->stacks[i - 1];
	while (i < dbstack->a_size + dbstack->b_size)
	{
		dbstack->stacks[i - 1] = dbstack->stacks[i];
		i++;
	}
	dbstack->stacks[i - 1] = tmp;
}

void	rra(t_dbstack *dbstack)
{
	int	tmp;
	int	i;

	i = dbstack->b_size + dbstack->a_size - 1;
	tmp = dbstack->stacks[i];
	while (i > dbstack->b_size)
	{
		dbstack->stacks[i] = dbstack->stacks[i - 1];
		i--;
	}
	dbstack->stacks[i] = tmp;
}

void	pa(t_dbstack *dbstack)
{
	if (dbstack->b_size == 0)
		return ;
	dbstack->b_size--;
	dbstack->a_size++;
}
