/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:22:52 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/03 13:23:35 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <errno.h>
#include <string.h>

void	ft_exit_and_free(void *p)
{
	if (p)
		free(p);
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}
