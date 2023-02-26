/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:34:39 by ymarival          #+#    #+#             */
/*   Updated: 2022/11/15 18:34:44 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//character

void	ft_putcharacter_length(char character, int *length)
{
	write(1, &character, 1);
	(*length)++;
}

//string

void	ft_string(char *args, int *length)
{
	size_t	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		(*length) += 6;
		return ;
	}
	while (args[i] != '\0')
	{
		ft_putcharacter_length(args[i], length);
		i++;
	}
}
