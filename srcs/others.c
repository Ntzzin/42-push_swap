/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:40:57 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/08 17:42:34 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	print_moves(t_moves moves)
{
	ft_printf("-----Moves-----\n");
	ft_printf("ra: %d\n", moves.ra);
	ft_printf("rra: %d\n", moves.rra);
	ft_printf("rb: %d\n", moves.rb);
	ft_printf("rrb: %d\n", moves.rrb);
	ft_printf("rr: %d\n", moves.rr);
	ft_printf("rrr: %d\n", moves.rrr);
}

int is_sorted(t_dbstack *dbstack)
{
	for (int i = 1; i < dbstack->a_size + dbstack->b_size; i++)
		if (dbstack->stacks[i - 1] > dbstack->stacks[i])
			return (0);
	return (1);
}

void	printall(t_dbstack *s)
{
	/*
	ft_printf("\nStacks\n");
	ft_printf("a_size at -> %d\n", s->a_size);
	ft_printf("b_size at -> %d\n", s->b_size);
	for (int i = 0; i < s->a_size + s->b_size; i++)
	{
		ft_printf("[%d]", s->stacks[i]);
	}
	ft_printf("\n\n");
	for (int i = 0, j = s->a_size + s->b_size - 1; i < s->a_size + s->b_size; i++, j--)
	{
		if (i >= s->b_size)
			ft_printf("[%d] ", s->stacks[i]);
		else
		 	ft_printf("    ");
		
		if (j < s->b_size)
			ft_printf("[%d]\n", s->stacks[j]);
		else
		 	ft_printf("   \n");
	}
	ft_printf(" A   B \n");
	ft_printf("\nDONE\n");
	*/
}
