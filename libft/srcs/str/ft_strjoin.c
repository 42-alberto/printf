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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	dsts1s2_len;
	char	*dst_s1s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (((size_t) - 1) - s1_len - 1 < s2_len)
		return (NULL);
	dsts1s2_len = s1_len + s2_len;
	dst_s1s2 = malloc(sizeof(char) * (dsts1s2_len + 1));
	if (dst_s1s2 == NULL)
		return (NULL);
	ft_strlcpy (dst_s1s2, s1, dsts1s2_len + 1);
	ft_strlcat (dst_s1s2, s2, dsts1s2_len + 1);
	return (dst_s1s2);
}
/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst_s1s2;

	if (!s1 || !s2 || (((size_t) - 1) - ft_strlen(s1) - 1 < ft_strlen(s2)))
		return (NULL);
	dst_s1s2 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst_s1s2 == NULL)
		return (NULL);
	ft_strlcpy (dst_s1s2, s1, ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strlcat (dst_s1s2, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (dst_s1s2);
}
*/