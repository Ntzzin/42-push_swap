/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:47:15 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/04 14:04:48 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <ft_printf.h>
# include <limits.h>
# include <stdlib.h>

# define SA "sa"
# define RA "ra"
# define RRA "rra"
# define PA "pa"

# define SB "sb"
# define RB "rb"
# define RRB "rrb"
# define PB "pb"

# define SS "ss"
# define RR "rr"
# define RRR "rrr"

typedef struct s_dbstack
{
	int		a;
	int		size;
	int		stacks[];
}			t_dbstack;

/*───────────────────────────────────────────
				Stack functions
─────────────────────────────────────────────*/
t_dbstack	*ft_new_dbstack(char **nums);

void		sa(t_dbstack *dbstack);
void		ra(t_dbstack *dbstack);
void		rra(t_dbstack *dbstack);
void		pa(t_dbstack *dbstack);

void		sb(t_dbstack *dbstack);
void		rb(t_dbstack *dbstack);
void		rrb(t_dbstack *dbstack);
void		pb(t_dbstack *dbstack);

/*───────────────────────────────────────────
				Aux functions
─────────────────────────────────────────────*/
int			ft_atoi(char **nptr);
void		ft_exit_and_free(void *p);

#endif
