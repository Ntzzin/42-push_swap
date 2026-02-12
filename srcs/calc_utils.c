/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:39:35 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/12 14:50:58 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	get_max(int *a, int n)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (++i < n)
		if (a[i] > a[max])
			max = i;
	return (max);
}

int	get_min(int *a, int n)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (++i < n)
		if (a[i] < a[min])
			min = i;
	return (min);
}

int	get_b_predecessor(t_dbstack *dbstack, int idx)
{
	int	i;
	int	pre;
	int	*b;

	i = -1;
	pre = -1;
	b = dbstack->stacks;
	while (++i < dbstack->b_size)
		if (b[i] < dbstack->stacks[idx] && (pre == -1 || b[i] > b[pre]))
			pre = i;
	if (pre == -1)
		pre = get_max(b, dbstack->b_size);
	return (pre);
}

int	get_a_successor(t_dbstack *dbstack, int idx)
{
	int	i;
	int	suc;
	int	*a;

	i = -1;
	suc = -1;
	a = &(dbstack->stacks[dbstack->b_size]);
	while (++i < dbstack->a_size)
		if (a[i] > dbstack->stacks[idx] && (suc == -1 || a[i] < a[suc]))
			suc = i;
	if (suc == -1)
		suc = get_min(a, dbstack->a_size);
	return (suc);
}

int	pos_in_b(t_dbstack *dbstack, int i){
	return (dbstack->b_size - 1 - i);
}

int	pos_in_a(t_dbstack *dbstack, int i){
	return (i - dbstack->b_size);
}

int	r_to_top_a(t_dbstack *dbstack, int i)
{
	if (i > dbstack->a_size / 2)
		return (i - dbstack->a_size);
	return (i);
}

int	r_to_top_b(t_dbstack *dbstack, int i)
{
	i = dbstack->b_size - 1 - i;
	if (i > dbstack->b_size / 2)
		return (i - dbstack->b_size);
	return (i);
}
