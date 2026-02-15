/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:30:12 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/15 19:05:15 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

static void	remove_nl(char *line)
{
	int	i;

	i = -1;
	while (line[++i] != '\n')
	;
	line[i] = '\0';
}

int	main(int argc, char **argv)
{
	t_dbstack	*dbstack;
	char		*line;

	if (argc < 2)
		return (0);
	dbstack = new_dbstack(argv);
	line = get_next_line(0);
	while (line)
	{
		remove_nl(line);
		if (!do_op(dbstack, line))
		{
			free(line);
			exit_and_free(dbstack);
		}
		free(line);
		line = get_next_line(0);
	}
	if (dbstack->b_size == 0 && is_sorted(dbstack))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(dbstack);
	return (0);
}
