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

int	ft_put_n_char(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (write(1, &c, 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_print_prefix(t_flags *flags)
{
	if (flags->type == 'd' || flags->type == 'i')
	{
		if (flags->is_neg)
			return (write(1, "-", 1));
		if (flags->is_plus)
			return (write(1, "+", 1));
		if (flags->is_space)
			return (write(1, " ", 1));
	}
	if (flags->type == 'p')
	{
		if (flags->is_space)
			return (write(1, " 0x", 3));
		if (flags->is_plus)
			return (write(1, "+0x", 3));
		return (write(1, "0x", 2));
	}
	if (flags->type == 'x' && flags->is_hashtag)
		return (write(1, "0x", 2));
	if (flags->type == 'X' && flags->is_hashtag)
		return (write(1, "0X", 2));
	return (0);
}

int	ft_put_recursion(unsigned long n, unsigned long base, char *digits)
{
	int	res;
	int	temp;

	res = 0;
	if (n >= base)
	{
		temp = ft_put_recursion(n / base, base, digits);
		if (temp == -1)
			return (-1);
		res += temp;
	}
	if (write(1, &digits[n % base], 1) == -1)
		return (-1);
	return (res + 1);
}

int	ft_putnbr_base_unsigned(unsigned long n, t_flags *flags)
{
	char	*digits;
	int		base;

	if (flags->type == 'x' || flags->type == 'p')
	{
		digits = "0123456789abcdef";
		base = 16;
	}
	else if (flags->type == 'X')
	{
		digits = "0123456789ABCDEF";
		base = 16;
	}
	else
	{
		digits = "0123456789";
		base = 10;
	}
	return (ft_put_recursion(n, (unsigned long)base, digits));
}
