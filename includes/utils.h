/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:47:15 by nado-nas          #+#    #+#             */
/*   Updated: 2026/02/15 15:23:38 by nado-nas         ###   ########.fr       */
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
	int		a_rtt;
	int		b_rtt;
	int		s_rtt;
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
int			n_do_op(t_dbstack *dbstack, char *op, int n);

/*───────────────────────────────────────────
				Sort functions
─────────────────────────────────────────────*/
int			get_b_max(t_dbstack *dbstack);
int			get_a_min(t_dbstack *dbstack);
int			pos_in_a(t_dbstack *dbstack, int idx);
int			pos_in_b(t_dbstack *dbstack, int idx);
int			get_b_predecessor(t_dbstack *dbstack, int idx);
int			get_a_successor(t_dbstack *dbstack, int idx);
int			r_to_top_a(t_dbstack *dbstack, int idx);
int			r_to_top_b(t_dbstack *dbstack, int idx);
int			do_moves(t_moves moves, t_dbstack *dbstack);
t_moves		lowest_cost_a_to_b(t_dbstack *dbstack);
t_moves		lowest_cost_b_to_a(t_dbstack *dbstack);
int			sort(t_dbstack *dbstack);

/*───────────────────────────────────────────
				Aux functions
─────────────────────────────────────────────*/
int			ft_atoi(char **nptr);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_abs(int n);
int			min(int a, int b);
void		exit_and_free(void *p);

/*───────────────────────────────────────────
				Test functions
─────────────────────────────────────────────*/
void		print_moves(t_moves moves);
void		printall(t_dbstack *s);
int			is_sorted(t_dbstack *dbstack);

#endif
