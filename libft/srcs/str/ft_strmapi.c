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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s_mod;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	s_mod = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (s_mod == NULL)
		return (NULL);
	while (s[i])
	{
		s_mod[i] = f(i, s[i]);
		i++;
	}
	s_mod[i] = '\0';
	return (s_mod);
}
