/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:19:08 by nado-nas          #+#    #+#             */
/*   Updated: 2026/01/28 12:06:43 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	ft_isspec(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	ft_putspec(const char c, va_list *ap)
{
	t_ull	tmp;

	if (c == 'c')
		return (ft_putcharn(va_arg(*ap, int)));
	else if (c == 's')
		return (ft_putstrn(va_arg(*ap, char *)));
	else if (c == 'p')
	{
		tmp = va_arg(*ap, t_ull);
		if (tmp)
			return (ft_putstrn("0x") + ft_putbasen(tmp, HEX, 16));
		else
			return (ft_putstrn("(nil)"));
	}
	else if (c == 'd' || c == 'i')
		return (ft_putbasen(va_arg(*ap, int), DEC, 10));
	else if (c == 'u' || c == 'i')
		return (ft_putbasen(va_arg(*ap, t_ui), DEC, 10));
	else if (c == 'x')
		return (ft_putbasen(va_arg(*ap, t_ui), HEX, 16));
	else if (c == 'X')
		return (ft_putbasen(va_arg(*ap, t_ui), UHEX, 16));
	else if (c == '%')
		return (ft_putcharn('%'));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		n;

	if (!fmt)
		return (-1);
	i = 0;
	n = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (ft_isspec(fmt[i + 1]))
			{
				n += ft_putspec(fmt[++i], &ap);
				i++;
				continue ;
			}
		}
		n += ft_putcharn(fmt[i]);
		i++;
	}
	va_end(ap);
	return (n);
}
