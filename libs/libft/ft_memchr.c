/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:10:41 by vasco             #+#    #+#             */
/*   Updated: 2022/11/07 19:57:09 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*conv_s;

	i = 0;
	conv_s = (unsigned char *)s;
	while (i < n)
	{
		if (conv_s[i] == (unsigned char)c)
			return (conv_s + i);
		i++;
	}
	return (NULL);
}
