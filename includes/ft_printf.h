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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct flags
{
	int		is_minus;
	int		is_zero;
	int		is_hashtag;
	int		is_space;
	int		is_plus;
	int		width;
	int		precision;
	char	type;
	int		is_neg;
}	t_flags;

int			ft_printf(const char *format, ...);
int			ft_print_type(va_list args, t_flags *flags);
const char	*ft_parser_flags(const char *format, t_flags *flags);
void		ft_init_flags(t_flags *flags);
const char	*ft_flags_activator(const char *format, t_flags *flags);
const char	*ft_atoi_printf(const char *format, int *len);
int			ft_print_char(int c, t_flags *flags);
int			ft_print_str(const char *s, t_flags *flags);
int			ft_print_int(long n, t_flags *flags);
int			ft_print_hex(unsigned long n, t_flags *flags);
int			ft_assemble_int(int d_len, unsigned long n, int z_len, t_flags *f);
int			ft_assemble_hex(int d_len, unsigned long n, int z_len, t_flags *f);
int			ft_count_digits(unsigned long num, t_flags *flags);
int			ft_count_zeros(int digit_len, unsigned long num, t_flags *flags);
int			ft_print_prefix(t_flags *flags);
int			ft_put_n_char(char c, int n);
int			ft_putnbr_base_unsigned(unsigned long n, t_flags *flags);

#endif
