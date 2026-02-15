/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:39:35 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/15 15:10:23 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

/**
 * @param dbstack The address of the double stack.
 * @return The absolute position of the smallest number in the
 * stack a.
 */
int	get_a_min(t_dbstack *dbstack)
{
	int	i;
	int	min;

	i = dbstack->b_size;
	min = i;
	while (++i < dbstack->b_size + dbstack->a_size)
		if (dbstack->stacks[i] < dbstack->stacks[min])
			min = i;
	return (min);
}

/**
 * @param dbstack The address of the double stack.
 * @return The absolute position of the biggest number in
 * stack b.
 */
int	get_b_max(t_dbstack *dbstack)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (++i < dbstack->b_size)
		if (dbstack->stacks[i] > dbstack->stacks[max])
			max = i;
	return (max);
}

/**
 * @brief Search for the successor of a number at @p idx in stack b.
 * @param dbstack The address of the double stack.
 * @param idx The absolute index within the underlying stacks array.
 * @return The absolute position of the successor, if no 
 * successor is found, the smallest number will be returned instead.
 */
int	get_a_successor(t_dbstack *dbstack, int idx)
{
	int	i;
	int	suc;
	int	*s;

	i = dbstack->b_size - 1;
	suc = -1;
	s = dbstack->stacks;
	while (++i < dbstack->b_size + dbstack->a_size)
		if (s[i] > dbstack->stacks[idx] && (suc == -1 || s[i] < s[suc]))
			suc = i;
	if (suc == -1)
		suc = get_a_min(dbstack);
	return (suc);
}

/**
 * @brief Search for the predecessor of a number at @p idx in stack b.
 * @param dbstack The address of the double stack.
 * @param idx The absolute index within the underlying stacks array.
 * @return The absolute position of the predecessor, if no 
 * predecessor is found, the biggest number will be returned instead.
 */
int	get_b_predecessor(t_dbstack *dbstack, int idx)
{
	int	i;
	int	pre;
	int	*s;

	i = -1;
	pre = -1;
	s = dbstack->stacks;
	while (++i < dbstack->b_size)
		if (s[i] < dbstack->stacks[idx] && (pre == -1 || s[i] > s[pre]))
			pre = i;
	if (pre == -1)
		pre = get_b_max(dbstack);
	return (pre);
}
