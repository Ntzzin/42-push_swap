/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:39:35 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/09 16:01:36 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

static int	process(t_moves moves, t_dbstack *dbstack)
{
	int	ops;

	ops = 0;
	ops += n_do_op(dbstack, RA, moves.ra);
	ops += n_do_op(dbstack, RRA, moves.rra);
	ops += n_do_op(dbstack, RB, moves.rb);
	ops += n_do_op(dbstack, RRB, moves.rrb);
	ops += n_do_op(dbstack, RR, moves.rr);
	ops += n_do_op(dbstack, RRR, moves.rrr);
	ops += do_op(dbstack, PB);
	return (ops);
}

static int	process2(t_moves moves, t_dbstack *dbstack)
{
	int	ops;

	ops = 0;
	ops += n_do_op(dbstack, RA, moves.ra);
	ops += n_do_op(dbstack, RRA, moves.rra);
	ops += n_do_op(dbstack, RB, moves.rb);
	ops += n_do_op(dbstack, RRB, moves.rrb);
	ops += n_do_op(dbstack, RR, moves.rr);
	ops += n_do_op(dbstack, RRR, moves.rrr);
	ops += do_op(dbstack, PA);
	return (ops);
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

	ops = 0;
	while (dbstack->b_size > 0)
	{
		tmp = precnum2(&(dbstack->stacks[dbstack->b_size]),dbstack->stacks[dbstack->b_size - 1], dbstack->a_size);
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
}

int	sort(t_dbstack *dbstack)
{
	int ops;
	int	min;
	int	tmp;

	ops = 0;
	min = 0;
	while (dbstack->a_size > 3)
		ops += process(lowest_cost(dbstack), dbstack);
	ops += sort_last_3(dbstack);
	ft_printf("\e[0;36mPushing everything back to a...\e[0m\n");
	
	while (dbstack->b_size > 0)
		ops += process2(lowest_cost2(dbstack), dbstack);
	
	/*
	while (dbstack->b_size > 0)
	{
		tmp = precnum2(&(dbstack->stacks[dbstack->b_size]),dbstack->stacks[dbstack->b_size - 1], dbstack->a_size);
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
	//sft_printf("\e[0;36mRotating a...\e[0m\n");
	//ft_printf("%d ops\n", ops);
	min = get_min(dbstack->stacks, dbstack->a_size);
	//ft_printf("%d ops\n", ops);
	if (min > dbstack->a_size / 2)
		ops	+= n_do_op(dbstack, RRA, dbstack->a_size - min);
	else
		ops	+= n_do_op(dbstack, RA, min);
	return (ops);
}

/*
	if (dbstack->a_size > 1)
	{
		do_op(dbstack, PB);
		do_op(dbstack, PB);
		ops += 2;
	}
	*/