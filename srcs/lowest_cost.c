/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowest_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:46:20 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/15 15:23:58 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

/**
 * @brief Computes all the moves needed in order to bring to the top of 
 * both individual stacks a given target. For each stack a target is 
 * determined based on the provided target calculation function 
 * (if NULL @p idx will be used instead).
 * @param dbstack The address of the double stack.
 * @param idx The absolute index within the underlying stacks array.
 * @param calc_a_target The function used to calculate the position 
 * of the target on stack a.
 * @param calc_b_target The function used to calculate the position 
 * of the target on stack b.
 * @return The data about the moves to be done.
 */
t_moves	moves(t_dbstack *dbstack, int idx,
	int (*calc_a_target)(t_dbstack *, int),
	int (*calc_b_target)(t_dbstack *, int))
{
	t_moves	moves;
	int		a;
	int		b;

	moves = (t_moves){0};
	if (calc_a_target)
		a = calc_a_target(dbstack, idx);
	else
		a = idx;
	if (calc_b_target)
		b = calc_b_target(dbstack, idx);
	else
		b = idx;
	moves.a_rtt = r_to_top_a(dbstack, a);
	moves.b_rtt = r_to_top_b(dbstack, b);
	if (moves.a_rtt > 0 && moves.b_rtt > 0)
		moves.s_rtt = min(moves.a_rtt, moves.b_rtt);
	else if (moves.a_rtt < 0 && moves.b_rtt < 0)
		moves.s_rtt = -min(-moves.a_rtt, -moves.b_rtt);
	moves.a_rtt -= moves.s_rtt;
	moves.b_rtt -= moves.s_rtt;
	return (moves);
}

/**
 * @brief Executes a set of moves based on the defined t_moves structure.
 * @param moves The structure containing the moves.
 * @param dbstack The address of the double stack.
 * @return The number of moves executed.
*/
int	do_moves(t_moves moves, t_dbstack *dbstack)
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

/**
 * @brief Calculates the total number of operations
 * needed to complete a set of moves.
 * @param moves The structure containing the moves.
 * @return The total cost in order to execute all the moves.
 */
static int	cost(t_moves moves)
{
	return (ft_abs(moves.a_rtt) + ft_abs(moves.b_rtt) + ft_abs(moves.s_rtt));
}

/**
 * @brief Searches for the element in stack a with the lowest 
 * cost in moves to be correctly positioned in stack b.
 * @param dbstack The address of the double stack.
 * @return The data about the moves of said lowest-cost element.
 */
t_moves	lowest_cost_a_to_b(t_dbstack *dbstack)
{
	t_moves	min;
	t_moves	curr;
	int		i;

	i = dbstack->b_size + 1;
	min = moves(dbstack, i - 1, NULL, get_b_predecessor);
	while (i < dbstack->b_size + dbstack->a_size)
	{
		curr = moves(dbstack, i, NULL, get_b_predecessor);
		if (cost(curr) < cost(min))
			min = curr;
		i++;
	}
	return (min);
}

/**
 * @brief Searches for the element in stack b with the lowest 
 * cost in moves to be correctly positioned in stack a.
 * @param dbstack The address of the double stack.
 * @return The data about the moves of said lowest-cost element.
 */
t_moves	lowest_cost_b_to_a(t_dbstack *dbstack)
{
	t_moves	min;
	t_moves	curr;
	int		i;

	i = dbstack->b_size - 2;
	min = moves(dbstack, i + 1, get_a_successor, NULL);
	while (i >= 0)
	{
		curr = moves(dbstack, i, get_a_successor, NULL);
		if (cost(curr) < cost(min))
			min = curr;
		i--;
	}
	return (min);
}
