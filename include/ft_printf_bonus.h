/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <ymarival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:41:02 by ymarival          #+#    #+#             */
/*   Updated: 2025/01/29 00:47:02 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H

# define FT_PRINTF_BONUS_H

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

int			ft_get_hex_ptr_len(size_t n);

char		*ft_hex_pref(t_format f);

int			ft_hex_rec(t_format f, size_t n, size_t iteration);

int			ft_print_nbr(t_format f, char *nbr, int len, int neg);

#endif
