/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:58:12 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/07 18:16:11 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <utils.h>

int	main(int argc, char **argv)
{
	int			i;
	int			ops;
	t_dbstack	*dbstack;

	i = 0;
	if (argc < 2)
		exit_and_free(NULL);
	dbstack = new_dbstack(argv);
	ft_printf("\e[0;32mNew double stack created with size %d\e[0m\n", dbstack->a_size);
	/*
	while (i < dbstack->a_size + dbstack->b_size)
	{
		ft_printf("[%d]", dbstack->stacks[i]);
		i++;
	}
	*/
	ft_printf("\e[0;34mSorting...\e[0m\n");
	ops = sort(dbstack);
	if (is_sorted(dbstack))
	{
		ft_printf("\e[0;32mSorted all using\e[0m", ops);
		if ((dbstack->a_size == 100 && ops < 700) || (dbstack->a_size == 500 && ops < 5500) || (dbstack->a_size != 500 && dbstack->a_size != 100))
			ft_printf("\e[0;36m %d \e[0m", ops);
		else
			ft_printf("\e[0;35m %d \e[0m", ops);
		ft_printf("\e[0;32moperations\e[0m\n");
	}else
		ft_printf("\e[0;35mFinal result is not sorted.\e[0m\n");
	//printall(dbstack);
	free(dbstack);
	
}


/*
int main(int argc, char **argv){
	int			i;
	t_dbstack	*dbstack;
	char		buffer[4];
	char		op[3];
	int			r;
	int			ops;

	i = 0;
	if (argc < 2)
		exit_and_free(NULL);
	dbstack = new_dbstack(argv);
	ft_printf("new double stack created with size %d\n", dbstack->a_size
		+ dbstack->b_size);
	while (i < dbstack->a_size + dbstack->b_size)
	{
		ft_printf("[%d]", dbstack->stacks[i]);
		i++;
	}
	ft_printf("\n");
	printall(dbstack);
	r = read(STDIN_FILENO, buffer, 3);
	ops = 1;
	buffer[3] = 0;
	op[2] = 0;
	while (r > 0)
	{
		strncpy(op, buffer, 2);
		if(!do_op(dbstack, op))
			break ;
		printall(dbstack);
		r = read(STDIN_FILENO, buffer, 3);
	}
	ft_printf("Exited the program\n");
	free(dbstack);
}
*/