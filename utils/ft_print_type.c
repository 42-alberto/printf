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

int	ft_print_type(va_list args, t_flags *flags)
{
	if (flags->type == 'c')
		return (ft_print_char(va_arg(args, int), flags));
	else if (flags->type == 's')
		return (ft_print_str(va_arg(args, char *), flags));
	else if (flags->type == 'd' || flags->type == 'i')
		return (ft_print_int((long)va_arg(args, int), flags));
	else if (flags->type == 'u')
		return (ft_print_int((long)va_arg(args, unsigned int), flags));
	else if (flags->type == 'x' || flags->type == 'X')
		return (ft_print_hex((unsigned long)va_arg(args, unsigned int), flags));
	else if (flags->type == 'p')
	{
		flags->precision = -1;
		return (ft_print_hex((unsigned long)va_arg(args, void *), flags));
	}
	else if (flags->type == '%')
		return (ft_print_char('%', flags));
	return (write(1, &flags->type, 1));
}
