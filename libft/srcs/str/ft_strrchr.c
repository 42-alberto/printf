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

char	*ft_strrchr(const char *s, int c)
{
	char	*s_found;
	char	*last_found;
	char	c_char;

	s_found = (char *) s;
	last_found = NULL;
	c_char = (char) c;
	while (*s_found || (c_char == '\0' && !*s_found))
	{
		if (*s_found == c_char)
			last_found = s_found;
		if (!*s_found)
			break ;
		s_found++;
	}
	return (last_found);
}
