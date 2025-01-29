/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <ymarival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:39:40 by ymarival          #+#    #+#             */
/*   Updated: 2025/01/29 00:47:02 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

static char	get_sign(t_format f, int neg)
{
	if (neg)
		return ('-');
	if (f.plus_flag)
		return ('+');
	return (0);
}

static int	ft_handle_prefix(t_format f, char sign, int neg, int c)
{
	if (f.specifier != 'u')
		f.width -= (f.space && !neg && !f.plus_flag);
	if (sign && f.specifier != 'u')
		c += ft_putnchar_fd(sign, 1, f.zero && (!f.dot || f.neg_prec));
	else if (f.space && f.specifier != 'u')
		c += ft_putnchar_fd(' ', 1, f.zero && !f.dot);
	return (c);
}

int	ft_print_nbr(t_format f, char *nbr, int len, int neg)
{
	int		c;
	char	sign;

	c = 0;
	sign = get_sign(f, neg);
	c = ft_handle_prefix(f, sign, neg, c);
	if (!f.minus && f.width > f.precision && (!f.dot || f.neg_prec) && f.zero)
		c += ft_putnchar_fd('0', 1, f.width - f.precision
				- (sign != 0 && f.specifier != 'u'));
	else if (!f.minus && f.width > f.precision)
		c += ft_putnchar_fd(' ', 1, f.width - f.precision
				- (sign != 0 && f.specifier != 'u'));
	if (sign && f.specifier != 'u')
		c += ft_putnchar_fd(sign, 1, !f.zero || (f.dot && !f.neg_prec));
	else if (f.space && f.specifier != 'u')
		c += ft_putnchar_fd(' ', 1, !f.zero || f.dot);
	c += ft_putnchar_fd('0', 1, f.precision - len);
	c += write(1, nbr, len);
	if (f.minus && f.width > f.precision)
		c += ft_putnchar_fd(' ', 1, f.width - f.precision
				- (sign != 0 && f.specifier != 'u'));
	return (c);
}
