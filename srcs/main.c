/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:58:12 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/03 13:52:22 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	main(int argc, char **argv)
{
	int			i;
	t_dbstack	*dbstack;

	i = 0;
	if (argc < 2)
		ft_exit_and_free(NULL);
	dbstack = ft_new_dbstack(argv);
	ft_printf("new double stack created with size %d\n", dbstack->size);
	while (i < dbstack->size)
	{
		ft_printf("[%d]", dbstack->stacks[i]);
		i++;
	}
	ft_printf("\n");
	free(dbstack);
}
