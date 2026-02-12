/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowest_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:46:20 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/12 16:13:17 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

t_moves	moves(t_dbstack *dbstack, int i, int (*calc_a_target) (t_dbstack*, int), int (*calc_b_target) (t_dbstack*, int))
{
	t_moves	moves;
	int		a;
	int		b;

	moves = (t_moves){0};
	if (calc_a_target)
		a = calc_a_target(dbstack, i);
	else
		a = i;
	if (calc_b_target)
		b = calc_b_target(dbstack, i);
	else
		b = i;
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

static int	cost(t_moves moves)
{
	return (ft_abs(moves.a_rtt) + ft_abs(moves.b_rtt) + ft_abs(moves.s_rtt));
}

t_moves	lowest_cost_a_to_b(t_dbstack *dbstack)
{
	t_moves	min;
	t_moves	curr;
	int		i;

	i = dbstack->b_size + 1;
	min = moves(dbstack, i - 1, pos_in_a, get_b_predecessor);
	while (i < dbstack->b_size + dbstack->a_size)
	{
		curr = moves(dbstack, i, pos_in_a, get_b_predecessor);
		if (cost(curr) < cost(min))
			min = curr;
		i++;
	}
	return (min);
}

t_moves	lowest_cost_b_to_a(t_dbstack *dbstack)
{
	t_moves	min;
	t_moves	curr;
	int		i;

	i =  dbstack->b_size - 2;
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
