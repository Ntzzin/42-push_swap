/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:52:16 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/09 12:27:34 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	ss(t_dbstack *dbstack)
{
	sa(dbstack);
	sb(dbstack);
}

void	rr(t_dbstack *dbstack)
{
	ra(dbstack);
	rb(dbstack);
}

void	rrr(t_dbstack *dbstack)
{
	rra(dbstack);
	rrb(dbstack);
}

int	do_op(t_dbstack *dbstack, char *op)
{
	ft_printf("%s\n", op);
	if (!ft_strcmp(op, "sa"))
		return(sa(dbstack), printall(dbstack), 1);
	else if (!ft_strcmp(op, "ra"))
		return(ra(dbstack), printall(dbstack), 1);
	else if (!ft_strcmp(op, "rra"))
		return(rra(dbstack), printall(dbstack), 1);
	else if (!ft_strcmp(op, "pa"))
		return(pa(dbstack), 1);
	else if (!ft_strcmp(op, "sb"))
		return(sb(dbstack), printall(dbstack), 1);
	else if (!ft_strcmp(op, "rb"))
		return(rb(dbstack), printall(dbstack), 1);
	else if (!ft_strcmp(op, "rrb"))
		return(rrb(dbstack), printall(dbstack), 1);
	else if (!ft_strcmp(op, "pb"))
		return(pb(dbstack), printall(dbstack), 1);
	else if (!ft_strcmp(op, "ss"))
		return(ss(dbstack), printall(dbstack), 1);
	else if (!ft_strcmp(op, "rr"))
		return(rr(dbstack), printall(dbstack), 1);
	else if (!ft_strcmp(op, "rrr"))
		return(rrr(dbstack), printall(dbstack), 1);
	return (0);
}

int	n_do_op(t_dbstack *dbstack, char *op, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		do_op(dbstack, op);
		i++;
	}
	return (n);
}
