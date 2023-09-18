/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:10:47 by vasco             #+#    #+#             */
/*   Updated: 2022/11/08 14:58:17 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*conv_s;
	unsigned char	*conv_t;

	conv_s = (unsigned char *)str1;
	conv_t = (unsigned char *)str2;
	i = 0;
	if (n == 0)
		return (0);
	while (conv_s[i] == conv_t[i] && i < (n - 1))
		i++;
	return (conv_s[i] - conv_t[i]);
}
