/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <ymarival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:45:38 by ymarival          #+#    #+#             */
/*   Updated: 2025/01/28 22:36:12 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	ft_printf(const char *str, ...)
{
	int			count;
	va_list		ap;
	char		*first;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			first = (char *)str;
			if (*(++str))
				count += ft_read((char *)str, ap);
			while (*str && !ft_strchr(SPECIFIERS, *str))
				str++;
			if (!(*str))
				str = first;
		}
		else
			count += ft_putchar_fd(*str, 1);
		if (*str)
			str++;
	}
	va_end(ap);
	return (count);
}

int	ft_write(t_format f, va_list ap)
{
	int	count;

	count = 0;
	if (f.specifier == 'c' || f.specifier == '%')
		count = ft_char(f, ap);
	if (f.specifier == 's')
		count = ft_str(f, ap);
	if (f.specifier == 'd' || f.specifier == 'i' || f.specifier == 'u')
		count = ft_nbr(f, ap);
	if (f.specifier == 'X' || f.specifier == 'x')
		count = ft_hex(f, ap);
	if (f.specifier == 'p')
		count = ft_ptr(f, ap);
	return (count);
}
