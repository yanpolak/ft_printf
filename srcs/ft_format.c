/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <ymarival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:42:12 by ymarival          #+#    #+#             */
/*   Updated: 2025/01/22 18:42:14 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_format	ft_newformat(void)
{
	t_format	newformat;

	newformat.minus = 0;
	newformat.plus = 0;
	newformat.width = 0;
	newformat.precision = 0;
	newformat.specifier = 0;
	newformat.zero = 0;
	newformat.dot = 0;
	newformat.space = 0;
	newformat.sharp = 0;
	newformat.neg_prec = 0;
	return (newformat);
}
