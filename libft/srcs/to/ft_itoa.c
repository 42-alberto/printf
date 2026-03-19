/* ************************************************************************** */
/*                                                                            */
/*    /\_/\                                               :::      ::::::::   */
/*   ( o.o )   "Punteros y café,                        :+:      :+:    :+:   */
/*    > ^ <         todo va a salir bien."            +:+ +:+         +:+     */
/*   By: Me                                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0001/01/01 00:00:01 by Me                #+#    #+#             */
/*   Updated: 0001/01/01 00:00:02 by Me               ###   ########.fr       */
/*                                                                        pito*/
/* ************************************************************************** */

#include "libft.h"

static int	integer_len(int n)
{
	long	num;
	int		len;

	num = n;
	len = 1;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while ((num / 10) > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		s_len;
	long	n_long;
	char	*number;

	s_len = integer_len(n);
	n_long = (long)n;
	number = (char *)malloc(sizeof(char) * (s_len + 1));
	if (number == NULL)
		return (NULL);
	number[s_len] = '\0';
	if (n_long < 0)
	{
		number[0] = '-';
		n_long = -n_long;
	}
	while (n_long / 10 > 0)
	{
		number[s_len - 1] = (n_long % 10) + '0';
		n_long /= 10;
		s_len--;
	}
	number[s_len - 1] = (n_long % 10) + '0';
	return (number);
}
