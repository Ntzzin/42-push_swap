/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowest_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:46:20 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/09 15:59:12 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

static t_moves	moves(t_dbstack *dbstack, int i)
{
	t_moves	moves;
	int		a_rtt;
	int		b_rtt;

	moves = (t_moves){0};
	//ft_printf("\e[0;33mCost for %d\e[0m\n", dbstack->stacks[i]);
	a_rtt = calc_a_rotations(dbstack, i);
	//ft_printf("	a rot %d\n", a_rtt);
	b_rtt = calc_b_rotations(dbstack, i);
	//ft_printf("	b rot %d\n", b_rtt);
	if (a_rtt < 0)
		moves.rra = -a_rtt;
	else
		moves.ra = a_rtt;
	if (b_rtt < 0)
		moves.rrb = -b_rtt;
	else
		moves.rb = b_rtt;
	if (moves.ra && moves.rb)
		moves.rr = min(moves.ra, moves.rb);
	else if (moves.rra && moves.rrb)
		moves.rrr = min(moves.rra, moves.rrb);
	//ft_printf("	rr rot %d\n", moves.rr);
	//ft_printf("	rrr rot %d\n", moves.rrr);
	moves.ra -= moves.rr;
	moves.rra -= moves.rrr;
	moves.rb -= moves.rr;
	moves.rrb -= moves.rrr;
	return (moves);
}

static t_moves	moves2(t_dbstack *dbstack, int i)
{
	t_moves	moves;
	int		a_rtt;
	int		b_rtt;

	moves = (t_moves){0};
	//ft_printf("\e[0;33mCost for %d\e[0m\n", dbstack->stacks[i]);
	a_rtt = calc_a_rotations2(dbstack, i);
	//ft_printf("	a rot %d\n", a_rtt);
	b_rtt = calc_b_rotations2(dbstack, i);
	//ft_printf("	b rot %d\n", b_rtt);
	if (a_rtt < 0)
		moves.rra = -a_rtt;
	else
		moves.ra = a_rtt;
	if (b_rtt < 0)
		moves.rrb = -b_rtt;
	else
		moves.rb = b_rtt;
	if (moves.ra && moves.rb)
		moves.rr = min(moves.ra, moves.rb);
	else if (moves.rra && moves.rrb)
		moves.rrr = min(moves.rra, moves.rrb);
	//ft_printf("	rr rot %d\n", moves.rr);
	//ft_printf("	rrr rot %d\n", moves.rrr);
	moves.ra -= moves.rr;
	moves.rra -= moves.rrr;
	moves.rb -= moves.rr;
	moves.rrb -= moves.rrr;
	return (moves);
}

static int	cost(t_moves moves)
{
	return (moves.ra + moves.rra + moves.rb + moves.rrb + moves.rr + moves.rrr);
}

t_moves	a_to_b_l_cost(t_dbstack *dbstack)
{
	int		i;
	t_moves	min;
	int curr;
	int cmin;
	int y;

	i = dbstack->b_size + 1;
	//ft_printf("LOWEST_COST MIN FIRST\n");
	min = moves(dbstack, i - 1);
	while (i < dbstack->b_size + dbstack->a_size)
	{
		//ft_printf("LOWEST_COST CURR\n");
		curr = cost(moves(dbstack, i));
		cmin = cost(min);
		if (curr < cmin)
		{
			//ft_printf("LOWEST_COST MIN\n");
			min = moves(dbstack, i);
		}
		i++;
	}
	//ft_printf("LOWEST_COST MIN IS %d\n", min);
	return (min);
}

t_moves	b_to_a_l_cost(t_dbstack *dbstack)
{
	int		i;
	t_moves	min;
	int curr;
	int cmin;
	int y;

	i = dbstack->b_size - 2;
	//ft_printf("LOWEST_COST MIN FIRST\n");
	min = moves2(dbstack, i + 1);
	while (i > 0)
	{
		//ft_printf("LOWEST_COST CURR\n");
		curr = cost(moves2(dbstack, i));
		cmin = cost(min);
		if (curr < cmin)
		{
			//ft_printf("LOWEST_COST MIN\n");
			min = moves2(dbstack, i);
		}
		i--;
	}
	return (min);
}
