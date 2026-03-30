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
/*
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int ft, std;
	char *s_null = NULL;

	ft_printf("1. Chars y Strings\n");
	ft = ft_printf("FT : [%0++ - -#010c] [%0++ - -#010.3s] [%0++ - -#010s] 
[%0++ - -#010.5s]\n", 'A', "42cursus", s_null, s_null);
	std = printf("STD: [%0++ - -#010c] [%0++ - -#010.3s] [%0++ - -#010s] 
[%0++ - -#010.5s]\n", 'A', "42cursus", s_null, s_null);
	printf("R: FT %d | STD %d\n\n", ft, std);

	ft_printf("2. Enteros\n");
	ft = ft_printf("FT : [%#0+10.5d] [%#0 010d] [%#0-10.5i]\n", 42, 42, -42);
	std = printf("STD: [%#0+10.5d] [%#0 010d] [%#0-10.5i]\n", 42, 42, -42);
	printf("R: FT %d | STD %d\n\n", ft, std);

	ft_printf("3. Hexadecimales\n");
	ft = ft_printf("FT : [%0++ - -#0x] [%-#10X] [%-.0x]\n", 255, 255, 0);
	std = printf("STD: [%0++ - -#0x] [%-#10X] [%-.0x]\n", 255, 255, 0);
	printf("R: FT %d | STD %d\n\n", ft, std);

	ft_printf("4. Punteros\n");
	int n = 42;
	ft = ft_printf("FT : [%0  #020p] [%+p] [%p] [%#+- 10.4p]\n",
			(void *)&n, (void *)&n, (void *)0, (void *)0);
	std = printf("STD: [%0  #020p] [%+p] [%p] [%#+- 10.4p]\n",
			(void *)&n, (void *)&n, (void *)0, (void *)0);
	printf("R: FT %d | STD %d\n\n", ft, std);

	ft_printf("5. El símbolo %%\n");
	// Mi función gestiona el with en el doble %% 
	// tengo que probar como funciona en los ordenadores de 42
	ft = ft_printf("FT : [%%] [%-5%]\n");
	std = printf("STD: [%%] [%-5%]\n");
	printf("R: FT %d | STD %d)\n\n", ft, std);

	ft_printf("6. Límites\n");
	ft = ft_printf("FT : [%u] [%u] [%d]\n", 0, UINT_MAX, INT_MIN);
	std = printf("STD: [%u] [%u] [%d]\n", 0, UINT_MAX, INT_MIN);
	printf("R: FT %d | STD %d\n", ft, std);

	return (0);
}
*/