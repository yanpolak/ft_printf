/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <ymarival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:44:19 by ymarival          #+#    #+#             */
/*   Updated: 2025/01/22 18:44:22 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	ft_print_c_pct(t_format f, va_list ap)
{
	char	c;
	int		count;

	count = 0;
	if (f.specifier == 'c')
		c = va_arg(ap, int);
	else
		c = '%';
	f.precision = 1;
	if (!f.minus && f.zero)
		count += ft_putnchar_fd('0', 1, f.width - f.precision);
	else if (!f.minus && f.width > f.precision)
		count += ft_putnchar_fd(' ', 1, f.width - f.precision);
	count += ft_putchar_fd(c, 1);
	if (f.minus && f.width - f.precision > 0)
		count += ft_putnchar_fd(' ', 1, f.width - f.precision);
	return (count);
}

static char	*ft_handle_null_string(t_format f, int *has_malloc)
{
	char	*string;

	if (f.dot && f.precision >= 0 && f.precision < 6)
		return ("");
	string = malloc(sizeof(char) * 7);
	*has_malloc = 1;
	ft_strlcpy(string, "(null)", 7);
	return (string);
}

static int	ft_print_padding(t_format f, int count, int precision)
{
	if (!f.minus && f.width > precision && f.zero && (!f.dot || f.neg_prec))
		count += ft_putnchar_fd('0', 1, f.width - precision);
	else if (!f.minus && f.width - precision > 0)
		count += ft_putnchar_fd(' ', 1, f.width - precision);
	return (count);
}

int	ft_print_s(t_format f, va_list ap)
{
	char	*string;
	int		count;
	int		has_malloc;

	count = 0;
	has_malloc = 0;
	string = va_arg(ap, char *);
	if (!string)
		string = ft_handle_null_string(f, &has_malloc);
	if (!f.dot || f.precision < 0 || f.precision >= (int)ft_strlen(string))
		f.precision = ft_strlen(string);
	count = ft_print_padding(f, count, f.precision);
	count += ft_putstrn_fd(string, 1, f.precision);
	if (f.minus && f.width - f.precision > 0)
		count += ft_putnchar_fd(' ', 1, f.width - f.precision);
	if (has_malloc)
		free(string);
	return (count);
}
