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

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	i_src;

	dst_len = 0;
	src_len = ft_strlen (src);
	i = 0;
	i_src = 0;
	while (dst[i] && i < dsize)
	{
		i++;
		dst_len = i;
	}
	if (dsize > dst_len)
	{
		while (src[i_src] && i < dsize - 1)
			dst [i++] = src[i_src++];
		dst [i] = '\0';
		return (dst_len + src_len);
	}
	return (dsize + src_len);
}
