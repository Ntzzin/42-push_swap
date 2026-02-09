/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:39:35 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/09 15:53:43 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	get_max(int	*a, int n)
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

int	get_min(int	*a, int n)
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

int	precnum(int *a, int num, int n)
{
	int	i;
	int	prec;

	i = -1;
	prec = -1;
	while (++i < n)
		if (a[i] < num && (prec == -1 || a[i] > a[prec]))
			prec = i;
	if (prec == -1)
		return (get_max(a, n));
	return (prec);
}

int	sucnum(int *a, int num, int n)
{
	int	i;
	int	res;

	i = -1;
	res = -1;
	while (++i < n)
		if (a[i] > num && (res == -1 || a[i] < a[res]))
			res = i++;
	if (res == -1)
		return (get_min(a, n));
	return (res);
}

int	calc_a_rotations(t_dbstack *dbstack, int i)
{
	i = i - dbstack->b_size;
	if (i > dbstack->a_size / 2)
		return (-(dbstack->a_size - i));
	return (i);
}

int	calc_b_rotations(t_dbstack *dbstack, int i)
{
	int	prec;

	prec = dbstack->b_size - 1 - precnum(&(dbstack->stacks[0]), dbstack->stacks[i], dbstack->b_size);
	if (prec > dbstack->b_size / 2)
		return (-(dbstack->b_size - prec));
	return (prec);
}

int	calc_a_rotations2(t_dbstack *dbstack, int i)
{
	int	suc;

	suc = sucnum(&(dbstack->stacks[dbstack->b_size]), dbstack->stacks[i], dbstack->a_size);

	if (suc > dbstack->a_size / 2)
		return (-(dbstack->a_size - suc));
	return (suc);
}

int	calc_b_rotations2(t_dbstack *dbstack, int i)
{
	i = dbstack->b_size - 1 - i;
	if (i > dbstack->b_size / 2)
		return (-(dbstack->b_size - i));
	return (i);
}

