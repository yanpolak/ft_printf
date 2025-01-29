/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <ymarival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:52:46 by ymarival          #+#    #+#             */
/*   Updated: 2025/01/29 00:47:02 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static t_format	ft_read_width(char *str, va_list	ap, t_format f)
{
	int	specified;

	specified = 0;
	while (*str != '.' && !ft_strchr(SPECIFIERS, *str))
	{
		if (*str == '-')
			f.minus = 1;
		if (*str == '0' && !ft_isdigit(*(str - 1)))
			f.zero = 1;
		else if (((*str > '0' && *str <= '9') || *str == '*') && !specified)
		{
			if (*str == '*')
				f.width = va_arg(ap, int);
			else
				f.width = ft_atoi(str);
			specified = 1;
		}
		str++;
	}
	return (f);
}

static t_format	ft_read_bonus(char *str, t_format f)
{
	while (*str != '.' && !ft_strchr(SPECIFIERS, *str))
	{
		if (*str == '+')
			f.plus_flag = 1;
		if (*str == ' ')
			f.space = 1;
		if (*str == '#')
			f.sharp = 1;
		str++;
	}
	return (f);
}

static t_format	ft_parse_precision(char *str, va_list ap, t_format f)
{
	int	specified;

	specified = 0;
	while (!ft_strchr(SPECIFIERS, *str))
	{
		if ((ft_isdigit(*str) || *str == '*') && !specified)
		{
			if (*str == '*')
				f.precision = va_arg(ap, int);
			else
				f.precision = ft_atoi(str);
			specified = 1;
		}
		str++;
	}
	return (f);
}

int	ft_write(t_format f, va_list	ap)
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

int	ft_read(char *str, va_list	ap)
{
	t_format	new_format;

	new_format = ft_read_width(str, ap, ft_fmt());
	new_format = ft_read_bonus(str, new_format);
	while (!ft_strchr(SPECIFIERS, *str) && *str != '.')
		str++;
	if (*str == '.' && !new_format.specifier)
	{
		new_format.dot = 1;
		new_format = ft_parse_precision(str++, ap, new_format);
		while (!ft_strchr(SPECIFIERS, *str))
			str++;
	}
	if (new_format.width < 0)
	{
		new_format.minus = 1;
		new_format.width *= -1;
	}
	new_format.specifier = *str;
	new_format.neg_prec = new_format.precision < 0;
	return (ft_write(new_format, ap));
}
