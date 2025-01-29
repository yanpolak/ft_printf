/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <ymarival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:11:41 by aperez-b          #+#    #+#             */
/*   Updated: 2025/01/29 00:47:02 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_format
{
	int		minus;
	int		plus_flag;
	int		width;
	int		precision;
	int		neg_prec;
	char	specifier;
	int		zero;
	int		dot;
	int		space;
	int		sharp;
}			t_format;

# define INT_MIN -2147483648
# define UINT_MAX 4294967295
# define SPECIFIERS	"cspdiuxX%"
# define HEXALOW	"0123456789abcdef"
# define HEXAUP		"0123456789ABCDEF"

int			ft_printf(const char *str, ...);
t_format	ft_fmt(void);
int			ft_write(t_format f, va_list ap);
int			ft_char(t_format f, va_list ap);
int			ft_str(t_format f, va_list ap);
int			ft_nbr(t_format f, va_list ap);
int			ft_hex(t_format f, va_list ap);
int			ft_ptr(t_format f, va_list ap);
int			ft_read(char *str, va_list	ap);

#endif
