/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:35:10 by vasco             #+#    #+#             */
/*   Updated: 2022/11/07 19:52:13 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*conv_str;

	i = 0;
	conv_str = (unsigned char *)str;
	while (i < n)
	{
		conv_str[i] = c;
		i++;
	}
	return (str);
}
