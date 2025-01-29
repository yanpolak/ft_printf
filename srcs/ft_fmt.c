/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <ymarival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:45:16 by ymarival          #+#    #+#             */
/*   Updated: 2025/01/29 01:02:08 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_format	ft_fmt(void)
{
	t_format	initformat;

	initformat.minus = 0;
	initformat.plus_flag = 0;
	initformat.width = 0;
	initformat.precision = 0;
	initformat.specifier = 0;
	initformat.zero = 0;
	initformat.dot = 0;
	initformat.space = 0;
	initformat.sharp = 0;
	initformat.neg_prec = 0;
	return (initformat);
}
