/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <ymarival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:44:34 by ymarival          #+#    #+#             */
/*   Updated: 2025/01/29 00:29:32 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

static int	ft_handle_width(t_format f, int len, int precision_pad)
{
	int	count;
	int	total_len;
	int	pad_size;

	count = 0;
	total_len = len + 2;
	pad_size = f.width - total_len - precision_pad;
	if (pad_size > 0)
		count += ft_putnchar_fd(' ', 1, pad_size);
	return (count);
}

static int	ft_print_null_ptr(t_format f)
{
	int	count;
	int	len;

	count = 0;
	len = 5;
	if (!f.minus && f.width > len)
		count += ft_putnchar_fd(' ', 1, f.width - len);
	count += write(1, "(nil)", len);
	if (f.minus && f.width > len)
		count += ft_putnchar_fd(' ', 1, f.width - len);
	return (count);
}

static int	ft_get_precision_pad(t_format f, int len)
{
	if (f.precision > len)
		return (f.precision - len);
	return (0);
}

int	ft_hex(t_format f, va_list ap)
{
	int				count;
	unsigned int	n;
	int				len;

	count = 0;
	n = va_arg(ap, unsigned int);
	len = ft_nbrlen(n, 16);
	if (!n && !f.precision && f.dot)
		len = 0;
	if (f.precision < 0 || f.precision < len || !f.dot)
		f.precision = len;
	if (f.sharp && n)
		f.width -= 2;
	count += ft_putstrn_fd(ft_hex_pref(f), 1, 2 * (f.sharp && f.zero && n));
	if (!f.minus && f.width > f.precision && (!f.dot || f.neg_prec) && f.zero)
		count += ft_putnchar_fd('0', 1, (f.width - f.precision));
	else if (!f.minus && f.width > f.precision)
		count += ft_putnchar_fd(' ', 1, (f.width - f.precision));
	count += ft_putstrn_fd(ft_hex_pref(f), 1, 2 * (f.sharp && !f.zero && n));
	count += ft_putnchar_fd('0', 1, (f.precision - len));
	if (len)
		count += ft_hex_rec(f, n, n);
	if (f.minus && f.width > f.precision)
		count += ft_putnchar_fd(' ', 1, f.width - f.precision);
	return (count);
}

int	ft_ptr(t_format f, va_list ap)
{
	int		count;
	size_t	n;
	int		len;
	int		precision_pad;

	count = 0;
	n = (size_t)va_arg(ap, void *);
	if (!n)
		return (ft_print_null_ptr(f));
	len = ft_get_hex_ptr_len(n);
	precision_pad = ft_get_precision_pad(f, len);
	if (!f.minus)
		count += ft_handle_width(f, len, precision_pad);
	count += write(1, "0x", 2);
	count += ft_putnchar_fd('0', 1, precision_pad);
	count += ft_hex_rec(f, n, n);
	if (f.minus)
		count += ft_handle_width(f, len, precision_pad);
	return (count);
}
