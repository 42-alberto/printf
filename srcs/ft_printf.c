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

const char	*ft_atoi_printf(const char *format, int *len)
{
	*len = 0;
	while (*format >= '0' && *format <= '9')
	{
		*len = *len * 10 + (*format - '0');
		format++;
	}
	return (format);
}

const char	*ft_flags_activator(const char *format, t_flags *flags)
{
	while (*format == '-' || *format == '0' || *format == '#'
		|| *format == ' ' || *format == '+')
	{
		if (*format == '-')
			flags->is_minus = 1;
		else if (*format == '0')
			flags->is_zero = 1;
		else if (*format == '#')
			flags->is_hashtag = 1;
		else if (*format == '+')
			flags->is_plus = 1;
		else if (*format == ' ')
			flags->is_space = 1;
		format++;
	}
	return (format);
}

void	ft_init_flags(t_flags *flags)
{
	flags->is_minus = 0;
	flags->is_zero = 0;
	flags->is_hashtag = 0;
	flags->is_space = 0;
	flags->is_plus = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->type = 0;
	flags->is_neg = 0;
}

const char	*ft_parser_flags(const char *format, t_flags *flags)
{
	ft_init_flags(flags);
	format = ft_flags_activator(format, flags);
	if ((*format >= '0') && (*format <= '9'))
		format = ft_atoi_printf(format, &flags->width);
	if (*format == '.')
	{
		flags->precision = 0;
		format = ft_atoi_printf(++format, &flags->precision);
	}
	flags->type = *format;
	if (flags->is_minus || flags->precision > -1)
		flags->is_zero = 0;
	if (flags->is_plus)
		flags->is_space = 0;
	if (*format)
		format++;
	return (format);
}

int	ft_printf(const char *format, ...)
{
	int		len_printed;
	int		len;
	t_flags	flags;
	va_list	vargs;

	if (!format)
		return (-1);
	len_printed = 0;
	va_start(vargs, format);
	while (*format)
	{
		if (*format == '%' && *(++format))
		{
			format = ft_parser_flags(format, &flags);
			len = ft_print_type(vargs, &flags);
		}
		else
			len = write(1, format++, 1);
		if (len == -1)
			return (va_end(vargs), -1);
		len_printed += len;
	}
	return (va_end(vargs), len_printed);
}
