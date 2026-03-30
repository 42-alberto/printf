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

static int	ft_put_str_formatted(const char *s, int s_len, t_flags *flags)
{
	int	blanks_len;

	if (flags->is_minus)
		if (write(1, s, s_len) == -1)
			return (-1);
	blanks_len = ft_put_n_char(' ', flags->width - s_len);
	if (blanks_len == -1)
		return (-1);
	if (!flags->is_minus)
		if (write(1, s, s_len) == -1)
			return (-1);
	return (blanks_len + s_len);
}

int	ft_print_str(const char *s, t_flags *flags)
{
	int	s_len;

	if (!s)
	{
		if (flags->precision == -1 || flags->precision >= 6)
			s = "(null)";
		else
			s = "";
	}
	s_len = (int)ft_strlen(s);
	if (flags->precision >= 0 && flags->precision < s_len)
		s_len = flags->precision;
	return (ft_put_str_formatted(s, s_len, flags));
}
