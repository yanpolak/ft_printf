/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <ymarival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:45:27 by ymarival          #+#    #+#             */
/*   Updated: 2025/01/22 18:45:27 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

static char	*handle_int_min(void)
{
	return (ft_strdup("2147483648"));
}

static void	prepare_number(t_format *f, va_list ap, char **nbr, int *neg)
{
	int				num;
	unsigned int	n;

	*neg = 0;
	if (f->specifier == 'u')
	{
		f->plus = 0;
		f->space = 0;
		n = va_arg(ap, unsigned int);
		*nbr = ft_uitoa(n);
		return ;
	}
	num = va_arg(ap, int);
	*neg = (num < 0);
	if (*neg || num == INT_MIN)
		f->plus = 0;
	if (num == INT_MIN)
		*nbr = handle_int_min();
	else
	{
		if (*neg)
			num *= -1;
		*nbr = ft_itoa(num);
	}
}

int	ft_print_d_i_u(t_format f, va_list ap)
{
	char	*nbr;
	int		c;
	int		len;
	int		neg;

	c = 0;
	prepare_number(&f, ap, &nbr, &neg);
	if (!nbr)
		return (0);
	len = ft_strlen(nbr);
	if (*nbr == '0' && !f.precision && f.dot)
		len = 0;
	if (f.precision < len || !f.dot)
		f.precision = len;
	c = ft_print_nbr(f, nbr, len, neg);
	free(nbr);
	return (c);
}
