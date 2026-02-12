/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowest_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:46:20 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/12 14:38:47 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

t_moves	moves_ult(t_dbstack *dbstack, int i, int (*calc_a_target) (t_dbstack*, int), int (*calc_b_target) (t_dbstack*, int))
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

t_moves	lowest_cost(t_dbstack *dbstack)
{
	t_moves	min;
	int		i;
	int		curr;
	int		cmin;

	i = dbstack->b_size + 1;
	min = moves_ult(dbstack, i - 1, pos_in_a, get_b_predecessor);
	while (i < dbstack->b_size + dbstack->a_size)
	{
		curr = cost(moves_ult(dbstack, i, pos_in_a, get_b_predecessor));
		cmin = cost(min);
		if (curr < cmin)
			min = moves_ult(dbstack, i, pos_in_a, get_b_predecessor);
		i++;
	}
	return (min);
}

t_moves	lowest_cost2(t_dbstack *dbstack)
{
	t_moves	min;
	int		i;
	int		curr;
	int		cmin;

	i =  dbstack->b_size - 2;
	min = moves_ult(dbstack, i + 1, get_a_successor, NULL);
	while (i >= 0)
	{//1
		curr = cost(moves_ult(dbstack, i, get_a_successor, NULL));
		cmin = cost(min);
		if (curr < cmin)
			min = moves_ult(dbstack, i, get_a_successor, NULL);
		i--;
	}
	return (min);
}
