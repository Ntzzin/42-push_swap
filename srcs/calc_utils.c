/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:39:35 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/07 17:39:02 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	b_max(t_dbstack *dbstack)
{
	int	i;
	int	max;

	i = dbstack->b_size - 2;
	max = i + 1;
	while (i >= 0)
	{
		if (dbstack->stacks[i] > dbstack->stacks[max])
			max = i;
		i--;
	}
	return (max);
}

static int	b_min(t_dbstack *dbstack)
{
	int	i;
	int	min;

	i = dbstack->b_size - 2;
	min = i + 1;
	while (i >= 0)
	{
		if (dbstack->stacks[i] < dbstack->stacks[min])
			min = i;
		i--;
	}
	return (min);
}

static int	b_precnum(t_dbstack *dbstack, int num)
{
	int	i;
	int	res;

	i = dbstack->b_size - 1;
	res = -1;
	while (i >= 0)
	{
		if (dbstack->stacks[i] < num
			&& (res == -1 ||dbstack->stacks[i] > dbstack->stacks[res]))
			res = i;
		i--;
	}
	return (res);
}

int	calc_a_rotations(t_dbstack *dbstack, int i)
{
	i = i - dbstack->b_size;
	//ft_printf("		%d\n", i);
	if (i > dbstack->a_size / 2)
		return (-(dbstack->a_size - i));
	return (i);
}

int	calc_b_rotations(t_dbstack *dbstack, int i)
{
	int	max;
	int	min;
	int	prec;

	max = b_max(dbstack);
	//ft_printf("		max is at %d\n", max);
	min = b_min(dbstack);
	//ft_printf("		min is at %d\n", min);
	prec = dbstack->b_size - 1 - b_precnum(dbstack, dbstack->stacks[i]);
	//ft_printf("		prec is at %d\n", prec);
	//ft_printf("		current is %d\n", dbstack->stacks[i]);
	if (dbstack->stacks[i] > dbstack->stacks[max]
		|| dbstack->stacks[i] < dbstack->stacks[min])
	{
		//ft_printf("current max is %d\n", dbstack->stacks[max]);
		max = dbstack->b_size - 1 - max;
		//ft_printf("		pos in b %d\n", max);
		if (max > dbstack->b_size / 2)
			return (-(dbstack->b_size - max));
		//ft_printf("		retuning b rot %d\n", max);
		return (max);
	}
	if (prec > dbstack->b_size / 2)
		return (-(dbstack->b_size - prec));
	return (prec);
}
