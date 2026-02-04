/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:58:12 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/04 13:27:18 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <utils.h>

static void	printall(t_dbstack *s)
{
	ft_printf("\nStacks\n");
	ft_printf("a -> %d\n", s->a);
	for (int i = 0; i < s->size; i++)
	{
		ft_printf("[%d]", s->stacks[i]);
	}
	ft_printf("\nA->");
	for (int i = s->a; i < s->size; i++)
	{
		ft_printf("[%d]", s->stacks[i]);
	}
	ft_printf("\nB->");
	for (int i = 0; i < s->a; i++)
	{
		ft_printf("[%d]", s->stacks[i]);
	}
	ft_printf("\nDONE\n");
}

static int	do_op(t_dbstack *dbstack, char *op)
{
	ft_printf("-----%s-----\n", op);
	if (!strcmp(op, "sa"))
		sa(dbstack);
	else if (!strcmp(op, "ra"))
		ra(dbstack);
	else if (!strcmp(op, "aa"))
		rra(dbstack);
	else if (!strcmp(op, "pa"))
		pa(dbstack);
	else if (!strcmp(op, "sb"))
		sb(dbstack);
	else if (!strcmp(op, "rb"))
		rb(dbstack);
	else if (!strcmp(op, "bb"))
		rrb(dbstack);
	else if (!strcmp(op, "pb"))
		pb(dbstack);
	else
		return (ft_printf("Invalid operation\n"), 0);
	printall(dbstack);
	return (1);
}

int	main(int argc, char **argv)
{
	int			i;
	t_dbstack	*dbstack;
	char		buffer[4];
	char		op[3];

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
	printall(dbstack);
	
	int r = read(STDIN_FILENO, buffer, 3);
	int ops = 1;
	buffer[3] = 0;
	op[2] = 0;
	while (r > 0)
	{
		strncpy(op, buffer, 2);
		if(!do_op(dbstack, op))
			break;
		r = read(STDIN_FILENO, buffer, 3);
	}
	ft_printf("Exited the program\n");
	free(dbstack);
}
