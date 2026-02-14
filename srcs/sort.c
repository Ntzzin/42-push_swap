/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:39:35 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/14 12:57:08 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

static int	do_moves(t_moves moves, t_dbstack *dbstack)
{
	int	ops;

	ops = 0;
	if (moves.a_rtt > 0)
		ops += n_do_op(dbstack, RA, moves.a_rtt);
	else
		ops += n_do_op(dbstack, RRA, -moves.a_rtt);
	if (moves.b_rtt > 0)
		ops += n_do_op(dbstack, RB, moves.b_rtt);
	else
		ops += n_do_op(dbstack, RRB, -moves.b_rtt);
	if (moves.s_rtt > 0)
		ops += n_do_op(dbstack, RR, moves.s_rtt);
	else
		ops += n_do_op(dbstack, RRR, -moves.s_rtt);
	return (ops);
}

static int	push_to_b(t_moves moves, t_dbstack *dbstack)
{
	return (do_moves(moves, dbstack) + do_op(dbstack, PB));
}

static int	push_to_a(t_moves moves, t_dbstack *dbstack)
{
	return (do_moves(moves, dbstack) + do_op(dbstack, PA));
}

static int	sort_last_3(t_dbstack *dbstack)
{
	int	*a;
	int	ops;

	a = &(dbstack->stacks[dbstack->b_size]);
	ops = 0;
	ft_printf("\e[0;36mSorting the 3 last elements in a...\e[0m\n");
	if (a[0] > a[1] && a[0] > a[2])
		ops += do_op(dbstack, RA);
	else if (a[1] > a[0] && a[1] > a[2])
		ops += do_op(dbstack, RRA);
	if (a[0] > a[1])
		ops += do_op(dbstack, SA);
	return (ops);
}

static int	rotate_a_till_sorted(t_dbstack *dbstack)
{
	int	ops;
	int	rtt;

	ops = 0;
	rtt = r_to_top_a(dbstack, get_a_min(dbstack));
	if (rtt < 0)
		ops += n_do_op(dbstack, RRA, -rtt);
	else
		ops += n_do_op(dbstack, RA, rtt);
	return (ops);
}

int	sort(t_dbstack *dbstack)
{
	int	ops;
	int	min;
	int	tmp;

	ops = 0;
	min = 0;
	if (dbstack->a_size >= 5)
		ops += n_do_op(dbstack, PB, 2);
	while (dbstack->a_size > 3)
		ops += push_to_b(lowest_cost_a_to_b(dbstack), dbstack);
	ops += sort_last_3(dbstack);
	while (dbstack->b_size)
		ops += push_to_a(lowest_cost_b_to_a(dbstack), dbstack);
	ops += rotate_a_till_sorted(dbstack);
	return (ops);
}
