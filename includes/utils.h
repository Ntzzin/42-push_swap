/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:47:15 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/03 14:15:29 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <ft_printf.h>
# include <stdlib.h>
# include <limits.h>

# define COUNT 0
# define SAVE 1

typedef struct s_dbstack
{
	int				a;
	int				size;
	int				stacks[];
}					t_dbstack;

/*───────────────────────────────────────────
				Stack functions
─────────────────────────────────────────────*/
t_dbstack			*ft_new_dbstack(char **nums);

/*───────────────────────────────────────────
				Aux functions
─────────────────────────────────────────────*/
int					ft_atoi(char **nptr);
void				ft_exit_and_free(void *p);

#endif
