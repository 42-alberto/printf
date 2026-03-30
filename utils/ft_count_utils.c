/* ************************************************************************** */
/*                                                                            */
/*    /\_/\                                               :::      ::::::::   */
/*   ( o.o )   "Me quedo sin tinta,                     :+:      :+:    :+:   */
/*    > ^ <         ¿Cómo imprimiré ahora?"           +:+ +:+         +:+     */
/*   By: Me                                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0002/01/01 00:00:01 by Me                #+#    #+#             */
/*   Updated: 0002/01/01 00:00:02 by Me               ###   ########.fr       */
/*                                                                      patito*/
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_zeros(int digit_len, unsigned long num, t_flags *flags)
{
	int	sign_len;
	int	zero_len;

	if (flags->precision != -1)
	{
		if (flags->precision > digit_len)
			return (flags->precision - digit_len);
		return (0);
	}
	if (flags->is_zero)
	{
		sign_len = 0;
		if (flags->type == 'p' || (flags->is_hashtag && num != 0))
			sign_len = 2;
		if (flags->type == 'p' && (flags->is_space || flags->is_plus))
			sign_len = 3;
		if (flags->type == 'd' || flags->type == 'i')
			if (flags->is_neg || flags->is_plus || flags->is_space)
				sign_len = 1;
		zero_len = flags->width - (digit_len + sign_len);
		if (zero_len > 0)
			return (zero_len);
	}
	return (0);
}

int	ft_count_digits(unsigned long num, t_flags *flags)
{
	int	count;
	int	base;

	if (flags->type == 'x' || flags->type == 'X' || flags->type == 'p')
		base = 16;
	else
		base = 10;
	if (num == 0 && flags->precision == 0)
		return (0);
	if (num == 0)
		return (1);
	count = 0;
	while (num > 0)
	{
		num /= base;
		count++;
	}
	return (count);
}

int	ft_count_spaces(int total_len, int width)
{
	int	spaces;

	spaces = width - total_len;
	if (spaces < 0)
		return (0);
	return (spaces);
}
