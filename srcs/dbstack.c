/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbstack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:51:12 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/12 16:23:11 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

static int	get_size(char **nums)
{
	char	*tmp;
	int		i;
	int		n;

	i = 1;
	n = 0;
	while (nums[i])
	{
		tmp = nums[i];
		while (*tmp)
		{
			ft_atoi(&tmp);
			n++;
		}
		i++;
	}
	return (n);
}

static int	contains(int *arr, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
		if (arr[i++] == num)
			return (1);
	return (0);
}

static void	save(t_dbstack *dbstack, int i, int num)
{
	if (contains(dbstack->stacks, i, num))
		exit_and_free(dbstack);
	dbstack->stacks[i] = num;
}

static void	fill(t_dbstack *dbstack, char **nums)
{
	char	*tmp;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (nums[i])
	{
		tmp = nums[i];
		while (*tmp)
		{
			save(dbstack, j, ft_atoi(&tmp));
			j++;
		}
		i++;
	}
}

t_dbstack	*new_dbstack(char **nums)
{
	t_dbstack	*dbstack;
	int			size;

	size = get_size(nums);
	dbstack = malloc(sizeof(int) * (2 + size));
	if (!dbstack)
		exit_and_free(NULL);
	dbstack->a_size = size;
	dbstack->b_size = 0;
	fill(dbstack, nums);
	return (dbstack);
}
