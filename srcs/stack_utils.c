/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:51:12 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/04 13:56:49 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

static int	ft_get_size(char **nums)
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
			ft_printf("atoi: %d\n", ft_atoi(&tmp));
			n++;
		}
		i++;
	}
	return (n);
}

static int	ft_contains(int *arr, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
		if (arr[i++] == num)
			return (1);
	return (0);
}

static int	ft_save(t_dbstack *dbstack, int i, int num)
{
	if (ft_contains(dbstack->stacks, i, num))
		ft_exit_and_free(dbstack);
	dbstack->stacks[i] = num;
}

static void	ft_fill(t_dbstack *dbstack, char **nums)
{
	char	*tmp;
	int		num;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (nums[i])
	{
		tmp = nums[i];
		while (*tmp)
		{
			ft_save(dbstack, j, ft_atoi(&tmp));
			j++;
		}
		i++;
	}
}

t_dbstack	*ft_new_dbstack(char **nums)
{
	t_dbstack	*dbstack;
	int			size;

	size = ft_get_size(nums);
	dbstack = malloc(sizeof(int) * (2 + size));
	if (!dbstack)
		ft_exit_and_free(dbstack);
	dbstack->size = size;
	dbstack->a = 0;
	ft_fill(dbstack, nums);
	return (dbstack);
}
