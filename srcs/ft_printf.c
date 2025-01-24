/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <ymarival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:16:18 by ymarival          #+#    #+#             */
/*   Updated: 2025/01/22 21:16:24 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int			chars_print;
	va_list		ap;
	char		*format_start;

	chars_print = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			format_start = (char *)str;
			if (*(++str))
				chars_print += ft_parse((char *)str, ap);
			while (*str && !ft_strchr(SPECIFIERS, *str))
				str++;
			if (!(*str))
				str = format_start;
		}
		else
			chars_print += ft_putchar_fd(*str, 1);
		if (*str)
			str++;
	}
	va_end(ap);
	return (chars_print);
}

int	ft_print_format(t_format f, va_list	ap)
{
	int	chars_print;

	chars_print = 0;
	if (f.specifier == 'c' || f.specifier == '%')
		chars_print = ft_print_c_pct(f, ap);
	if (f.specifier == 's')
		chars_print = ft_print_s(f, ap);
	if (f.specifier == 'd' || f.specifier == 'i' || f.specifier == 'u')
		chars_print = ft_print_d_i_u(f, ap);
	if (f.specifier == 'X' || f.specifier == 'x')
		chars_print = ft_print_x(f, ap);
	if (f.specifier == 'p')
		chars_print = ft_print_p(f, ap);
	return (chars_print);
}
