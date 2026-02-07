/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:47:15 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/07 17:36:29 by nado-nas         ###   ########.fr       */
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
	int		b_size;
	int		a_size;
	int		stacks[];
}			t_dbstack;

typedef struct s_moves
{
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		rr;
	int		rrr;
}			t_moves;

/*───────────────────────────────────────────
				Stack functions
─────────────────────────────────────────────*/
t_dbstack	*new_dbstack(char **nums);

void		sa(t_dbstack *dbstack);
void		ra(t_dbstack *dbstack);
void		rra(t_dbstack *dbstack);
void		pa(t_dbstack *dbstack);

void		sb(t_dbstack *dbstack);
void		rb(t_dbstack *dbstack);
void		rrb(t_dbstack *dbstack);
void		pb(t_dbstack *dbstack);

int			do_op(t_dbstack *dbstack, char *op);

/*───────────────────────────────────────────
				Sort functions
─────────────────────────────────────────────*/
int			calc_a_rotations(t_dbstack *dbstack, int i);
int			calc_b_rotations(t_dbstack *dbstack, int i);
int			b_max(t_dbstack *dbstack);
int			sort(t_dbstack *dbstack);

/*───────────────────────────────────────────
				Aux functions
─────────────────────────────────────────────*/
int			ft_atoi(char **nptr);
int			ft_strcmp(const char *s1, const char *s2);
int			min(int a, int b);
void		exit_and_free(void *p);

/*───────────────────────────────────────────
				Test functions
─────────────────────────────────────────────*/
void		print_moves(t_moves moves);
void		printall(t_dbstack *s);
int			is_sorted(t_dbstack *dbstack);

#endif
