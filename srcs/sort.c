/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:39:35 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/12 14:43:02 by nado-nas         ###   ########.fr       */
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
	if (get_max(a, dbstack->a_size) == 0)
		ops += do_op(dbstack, RA);
	else if (get_max(a, dbstack->a_size) == 1)
		ops += do_op(dbstack, RRA);
	if (a[0] > a[1])
		ops += do_op(dbstack, SA);
	return (ops);
}
/*
static int	push_back(t_dbstack *dbstack)
{
	int	ops;
	int	suc;

	ops = 0;
	while (dbstack->b_size > 0)
	{
		suc = sucnum(&(dbstack->stacks[dbstack->b_size]),
				dbstack->stacks[dbstack->b_size - 1], dbstack->a_size);
		if (suc > dbstack->a_size / 2)
			ops += n_do_op(dbstack, RRA, dbstack->a_size - suc);
		else
			ops += n_do_op(dbstack, RA, suc);
		ops += do_op(dbstack, PA);
	}
	return (ops);
}
	*/

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
		ops += push_to_b(lowest_cost(dbstack), dbstack);
	ops += sort_last_3(dbstack);
	
	while (dbstack->b_size)
		ops += push_to_a(lowest_cost2(dbstack), dbstack);
		
		
	/*
	while (dbstack->b_size > 0)
	{
		tmp = sucnum(&(dbstack->stacks[dbstack->b_size]),dbstack->stacks[dbstack->b_size - 1], dbstack->a_size);
		//ft_printf("prec for %d is at %d\n", dbstack->stacks[dbstack->b_size - 1], tmp);
		if (tmp == -1){
			
			tmp = get_min(&(dbstack->stacks[dbstack->b_size]), dbstack->a_size);
			//ft_printf("	reassigning prec to %d\n", tmp);
		}
			
		
		if (tmp > dbstack->a_size / 2)
			ops += n_do_op(dbstack, RRA, dbstack->a_size - tmp);
		else
			ops += n_do_op(dbstack, RA, tmp);
		ops += do_op(dbstack, PA);
			
	}
		*/
	//ops += push_back(dbstack);
	int x;
	x = r_to_top_a(dbstack, get_min(dbstack->stacks, dbstack->a_size));
	//min = get_min(dbstack->stacks, dbstack->a_size);
	if (x < 0)
		ops += n_do_op(dbstack, RRA, -x);
	else
		ops += n_do_op(dbstack, RA, x);
	return (ops);
}
