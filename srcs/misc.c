/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:22:52 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/04 14:05:23 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <utils.h>

void	ft_exit_and_free(void *p)
{
	if (p)
		free(p);
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

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
	rr(dbstack);
}

void	do_op(t_dbstack *dbstack, char *op)
{
	ft_printf("%s\n", op);
	if (!strcmp(op, "sa"))
		sa(dbstack);
	else if (!strcmp(op, "ra"))
		ra(dbstack);
	else if (!strcmp(op, "rra"))
		rra(dbstack);
	else if (!strcmp(op, "pa"))
		pa(dbstack);
	else if (!strcmp(op, "sb"))
		sb(dbstack);
	else if (!strcmp(op, "rb"))
		rb(dbstack);
	else if (!strcmp(op, "rrb"))
		rrb(dbstack);
	else if (!strcmp(op, "pb"))
		pb(dbstack);
	else if (!strcmp(op, "ss"))
		ss(dbstack);
	else if (!strcmp(op, "rr"))
		rr(dbstack);
	else if (!strcmp(op, "rrr"))
		rrr(dbstack);
}
