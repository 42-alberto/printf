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

int	ft_assemble_int(int d_len, unsigned long n, int z_len, t_flags *f)
{
	int	total;
	int	prefix_len;
	int	blanks_len;
	int	expected;

	prefix_len = (f->is_neg || f->is_plus || f->is_space);
	blanks_len = f->width - (d_len + z_len + prefix_len);
	if (blanks_len < 0)
		blanks_len = 0;
	expected = prefix_len + z_len + blanks_len + d_len;
	total = 0;
	if (!f->is_minus && !f->is_zero)
		total += ft_put_n_char(' ', blanks_len);
	total += ft_print_prefix(f);
	if (f->is_zero)
		total += ft_put_n_char('0', blanks_len);
	total += ft_put_n_char('0', z_len);
	if (!(n == 0 && f->precision == 0))
		total += ft_putnbr_base_unsigned(n, f);
	if (f->is_minus)
		total += ft_put_n_char(' ', blanks_len);
	if (total != expected)
		return (-1);
	return (total);
}

int	ft_print_int(long n, t_flags *f)
{
	unsigned long	num_abs;
	int				digit_len;
	int				zeros_len;

	if (n < 0)
	{
		f->is_neg = 1;
		f->is_plus = 0;
		f->is_space = 0;
		num_abs = (unsigned long)(-n);
	}
	else
		num_abs = (unsigned long)n;
	if (f->type == 'u')
	{
		f->is_neg = 0;
		f->is_plus = 0;
		f->is_space = 0;
	}
	digit_len = ft_count_digits(num_abs, f);
	zeros_len = ft_count_zeros(digit_len, num_abs, f);
	return (ft_assemble_int(digit_len, num_abs, zeros_len, f));
}
