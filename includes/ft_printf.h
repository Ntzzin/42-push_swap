/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:47:15 by nado-nas          #+#    #+#             */
/*   Updated: 2026/01/28 12:45:50 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define DEC "0123456789"
# define HEX "0123456789abcdef"
# define UHEX "0123456789ABCDEF"

typedef unsigned long long	t_ull;
typedef unsigned int		t_ui;

int							ft_printf(const char *fmt, ...);

/*───────────────────────────────────────────
				Aux functions
─────────────────────────────────────────────*/
int							ft_putbasen(__int128 nbr, char *base, int blen);
int							ft_putcharn(char c);
int							ft_putstrn(const char *str);

#endif
