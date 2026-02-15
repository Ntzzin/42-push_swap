/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:39:35 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/15 16:58:09 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

/**
 * @brief Executes a set of moves based on the defined t_moves structure, 
 * finalized by a push to stack b.
 * @param moves The structure containing the moves.
 * @param dbstack The address of the double stack.
 * @return The number of moves executed.
*/
static int	push_to_b(t_moves moves, t_dbstack *dbstack)
{
	return (do_moves(moves, dbstack) + do_op(dbstack, PB));
}

/**
 * @brief Executes a set of moves based on the defined t_moves structure, 
 * finalized by a push to stack a.
 * @param moves The structure containing the moves.
 * @param dbstack The address of the double stack.
 * @return The number of moves executed.
*/
static int	push_to_a(t_moves moves, t_dbstack *dbstack)
{
	return (do_moves(moves, dbstack) + do_op(dbstack, PA));
}

/**
 * @brief Sorts 3 numbers in stack a.
 * @warning This function expects stack a to have exactly
 * 3 elements.
 * @param dbstack The address of the double stack.
 * @return The number of moves executed.
*/
static int	sort_3(t_dbstack *dbstack)
{
	int	*a;
	int	ops;

	a = &(dbstack->stacks[dbstack->b_size]);
	ops = 0;
	if (a[0] > a[1] && a[0] > a[2])
		ops += do_op(dbstack, RA);
	else if (a[1] > a[0] && a[1] > a[2])
		ops += do_op(dbstack, RRA);
	if (a[0] > a[1])
		ops += do_op(dbstack, SA);
	return (ops);
}

/**
 * @brief Rotates stack a till it is sorted.
 * @param dbstack The address of the double stack.
 * @return The number of moves executed.
*/
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

/**
 * @brief Apllies the sorting algorithm.
 * @param dbstack The address of the double stack.
 * @return The number of moves executed.
*/
int	sort(t_dbstack *dbstack)
{
	int	ops;

	ops = 0;
	if (dbstack->a_size >= 5)
		ops += n_do_op(dbstack, PB, 2);
	while (dbstack->a_size > 3)
		ops += push_to_b(lowest_cost_a_to_b(dbstack), dbstack);
	ops += sort_3(dbstack);
	while (dbstack->b_size)
		ops += push_to_a(lowest_cost_b_to_a(dbstack), dbstack);
	ops += rotate_a_till_sorted(dbstack);
	return (ops);
}
