/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:58:12 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/15 16:09:35 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <utils.h>

int	main(int argc, char **argv)
{
	int			i;
	t_dbstack	*dbstack;

	i = 0;
	if (argc < 2)
		exit_and_free(NULL);
	dbstack = new_dbstack(argv);
	sort(dbstack);
	free(dbstack);
	return (0);
}
