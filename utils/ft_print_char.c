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

int	ft_print_char(int c, t_flags *flags)
{
	unsigned char	c_char;
	int				blanks_len;

	c_char = (unsigned char)c;
	if (flags->is_minus)
		if (write(1, &c_char, 1) == -1)
			return (-1);
	blanks_len = ft_put_n_char(' ', flags->width - 1);
	if (blanks_len == -1)
		return (-1);
	if (!flags->is_minus)
		if (write(1, &c_char, 1) == -1)
			return (-1);
	return (blanks_len + 1);
}
