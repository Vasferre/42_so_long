/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:51:17 by vasco             #+#    #+#             */
/*   Updated: 2022/11/08 15:40:44 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	leng_src;
	size_t	leng_dest;

	if (size == 0)
		return (ft_strlen(src));
	leng_src = ft_strlen (src);
	leng_dest = ft_strlen (dest);
	j = leng_dest;
	i = 0;
	if (size < leng_dest)
		return (leng_src + size);
	while (src[i] != '\0' && j < (size - 1))
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (leng_dest + leng_src);
}
