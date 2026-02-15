/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_to_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:39:35 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/15 15:13:33 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

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
 * @return The amount of rotations needed (positive or negative), for 
 * instance the value is positive for forward rotations and negative 
 * for reverse rotations, always choosing the path that will lead to 
 * the smallest count of |rotations|. 
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
 * @return The amount of rotations needed (positive or negative), for 
 * instance the value is positive for forward rotations and negative 
 * for reverse rotations, always choosing the path that will lead to 
 * the smallest count of |rotations|. 
*/
int	r_to_top_b(t_dbstack *dbstack, int idx)
{
	idx = pos_in_b(dbstack, idx);
	if (idx > dbstack->b_size / 2)
		return (idx - dbstack->b_size);
	return (idx);
}
