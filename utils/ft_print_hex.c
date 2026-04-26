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

int	ft_assemble_hex(int d_len, unsigned long n, int z_len, t_flags *f)
{
	int	total;
	int	prefix_len;
	int	blanks_len;
	int	expected;

	prefix_len = (f->type == 'p' || (f->is_hashtag && n != 0)) * 2;
	prefix_len += ((f->type == 'p') * (f->is_plus + f->is_space));
	blanks_len = f->width - (d_len + z_len + prefix_len);
	if (blanks_len < 0)
		blanks_len = 0;
	expected = prefix_len + z_len + blanks_len + d_len;
	total = 0;
	if (!f->is_minus && !f->is_zero)
		total += ft_put_n_char(' ', blanks_len);
	total += ft_print_prefix(f);
	if (f->is_zero)
		total += ft_put_n_char(' ', blanks_len);
	total += ft_put_n_char('0', z_len);
	if (d_len > 0)
		total += ft_putnbr_base_unsigned(n, f);
	if (f->is_minus)
		total += ft_put_n_char(' ', blanks_len);
	if (total != expected)
		return (-1);
	return (total);
}

int	ft_print_hex(unsigned long n, t_flags *f)
{
	int	d_len;
	int	z_len;

	if (f->type == 'p' && n == 0)
		return (ft_print_str("(nil)", f));
	if (n == 0)
		f->is_hashtag = 0;
	d_len = ft_count_digits(n, f);
	z_len = ft_count_zeros(d_len, n, f);
	return (ft_assemble_hex(d_len, n, z_len, f));
}
