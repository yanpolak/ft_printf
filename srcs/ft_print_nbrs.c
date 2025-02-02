/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <ymarival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:34:26 by ymarival          #+#    #+#             */
/*   Updated: 2025/01/29 00:47:02 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	plus_flag(t_format f)
{
	if (f.plus_flag)
		return ('+');
	return ('-');
}

static int	ft_print_nbr(t_format f, char *nbr, int len, int neg)
{
	int	c;

	c = 0;
	f.width -= (f.space && !neg && !f.plus_flag && f.width);
	if (neg || f.plus_flag)
		c += ft_putnchar_fd(plus_flag(f), 1, f.zero && (!f.dot || f.neg_prec));
	else if (f.space)
		c += ft_putnchar_fd(' ', 1, f.zero && !f.dot);
	if (!f.minus && f.width > f.precision && (!f.dot || f.neg_prec) && f.zero)
		c += ft_putnchar_fd('0', 1, f.width - f.precision - neg - f.plus_flag);
	else if (!f.minus && f.width > f.precision)
		c += ft_putnchar_fd(' ', 1, f.width - f.precision - neg - f.plus_flag);
	if (neg || f.plus_flag)
		c += ft_putnchar_fd(plus_flag(f), 1, !f.zero || (f.dot && !f.neg_prec));
	else if (f.space)
		c += ft_putnchar_fd(' ', 1, !f.zero || f.dot);
	c += ft_putnchar_fd('0', 1, f.precision - len);
	c += write(1, nbr, len);
	if (f.minus && f.width > f.precision)
		c += ft_putnchar_fd(' ', 1, f.width - f.precision - neg - f.plus_flag);
	return (c);
}

int	ft_nbr(t_format f, va_list ap)
{
	char	*nbr;
	int		n;
	int		c;
	int		len;
	int		neg;

	c = 0;
	n = va_arg(ap, int);
	neg = (n < 0 && n != INT_MIN && f.specifier != 'u');
	if (neg)
		f.plus_flag = 0;
	if (n < 0 && f.specifier != 'u')
		n *= -1;
	if (n < 0 && f.specifier == 'u')
		nbr = ft_uitoa((unsigned)n);
	else
		nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	if (*nbr == '0' && !f.precision && f.dot)
		len = 0;
	if (f.precision < len || !f.dot)
		f.precision = len;
	c += ft_print_nbr(f, nbr, len, neg);
	free(nbr);
	return (c);
}
