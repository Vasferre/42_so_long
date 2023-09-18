/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:10:56 by vasco             #+#    #+#             */
/*   Updated: 2022/11/04 18:07:30 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*conv_src;
	unsigned char	*conv_dest;

	i = 0;
	if (!dest && !src)
		return (NULL);
	conv_src = (unsigned char *)src;
	conv_dest = (unsigned char *)dest;
	while (i < n)
	{
		*(conv_dest + i) = *(conv_src + i);
		i++;
	}
	return (dest);
}
