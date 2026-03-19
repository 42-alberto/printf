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

#include "printf.h"

int	ft_print_str(const char *s, t_flags *flags)
{
	int	blanks_len;
	int	s_len;
	int	precision;

	precision = flags->precision;
	if (!s)
	{
		if (precision == -1 || precision >= 6)
			s = "(null)";
		else
			s = "";
	}
	s_len = ft_strlen(s);
	if (precision >= 0 && s_len >= precision)
		s_len = precision;
	if (flags->minus && write(1, s, s_len) == -1)
		return (-1);
	blanks_len = ft_print_blanks(flags->len, s_len);
	if (blanks_len == -1)
		return (-1);
	if (!flags->minus && write(1, s, s_len) == -1)
		return (-1);
	return (blanks_len + s_len);
}
