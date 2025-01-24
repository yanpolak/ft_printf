/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <ymarival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:44:58 by ymarival          #+#    #+#             */
/*   Updated: 2025/01/22 18:44:58 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

char	*ft_sharp(t_format f)
{
	if (f.specifier == 'X')
		return ("0X");
	return ("0x");
}

int	ft_recursive_hex(t_format f, size_t n, size_t iteration)
{
	int		count;
	int		remainder;
	char	character;

	count = 0;
	if (n > 0 || (!iteration && (f.specifier != 'p' || !f.dot)))
	{
		remainder = n % 16;
		if (f.specifier != 'X')
			character = HEXALOW[remainder];
		else
			character = HEXAUP[remainder];
		n /= 16;
		iteration = 1;
		count += ft_recursive_hex(f, n, iteration);
		count += ft_putchar_fd(character, 1);
	}
	return (count);
}

int	ft_get_hex_ptr_len(size_t n)
{
	int	len;

	len = 1;
	while (n > 15)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int	ft_handle_width(t_format f, int len, int precision_pad)
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

int	ft_get_precision_pad(t_format f, int len)
{
	if (f.precision > len)
		return (f.precision - len);
	return (0);
}
