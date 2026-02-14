/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:39:35 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/14 14:30:29 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

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
 * @brief Converts an absolute index @p idx into the its relative position
 * in stack a.
 * @param dbstack The address of the double stack.
 * @param idx The absolute index within the underlying stacks array.
 * @return The relative position in stack a.
*/
int	pos_in_a(t_dbstack *dbstack, int idx)
{
	return (idx - dbstack->b_size);
}

/**
 * @brief Converts an absolute index @p idx into the its relative position
 * in stack b.
 * @param dbstack The address of the double stack.
 * @param idx The absolute index within the underlying stacks array.
 * @return The relative position in stack b.
*/
int	pos_in_b(t_dbstack *dbstack, int idx)
{
	return (dbstack->b_size - 1 - idx);
}

/**
 * @brief Calculates the amount of rotations needed in order to bring
 * a number at @p idx to the top of stack a.
 * @param dbstack The address of the double stack.
 * @param idx The absolute index within the underlying stacks array.
 * @return The amount of rotations needed (positive or negative), for instance the 
 * value is positive for forward rotations and negative for reverse rotations, always
 * choosing the path that will lead to the smallest count of |rotations|. 
*/
int	r_to_top_a(t_dbstack *dbstack, int idx)
{
	idx = pos_in_a(dbstack, idx);
	if (idx > dbstack->a_size / 2)
		return (idx - dbstack->a_size);
	return (idx);
}

/**
 * @brief Calculates the amount of rotations needed in order to bring
 * a number at @p idx to the top of stack b.
 * @param dbstack The address of the double stack.
 * @param idx The absolute index within the underlying stacks array.
 * @return The amount of rotations needed (positive or negative), for instance the 
 * value is positive for forward rotations and negative for reverse rotations, always
 * choosing the path that will lead to the smallest count of |rotations|. 
*/
int	r_to_top_b(t_dbstack *dbstack, int idx)
{
	idx = pos_in_b(dbstack, idx);
	if (idx > dbstack->b_size / 2)
		return (idx - dbstack->b_size);
	return (idx);
}
