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

int	ft_print_blanks(int len, int s_len)
{
	int	i;

	i = 0;
	if (s_len >= len)
		return (0);
	while (i < len - s_len)
	{
		if (write (1, " ", 1) == -1)
			return (-1);
		i++;
	}
	return (len - s_len);
}

int	ft_print_char(int c, t_flags *flags)
{
	unsigned char	c_char;
	int				res;

	c_char = (unsigned char) c;
	if (flags->minus && write(1, &c_char, 1) == -1)
		return (-1);
	res = ft_print_blanks(flags->len, 1);
	if (res == -1)
		return (-1);
	if (!flags->minus && write(1, &c_char, 1) == -1)
		return (-1);
	return (res + 1);
}
