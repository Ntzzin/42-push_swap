/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:22:52 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/07 17:36:18 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <utils.h>

void	exit_and_free(void *p)
{
	if (p)
		free(p);
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
