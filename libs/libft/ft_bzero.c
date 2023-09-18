/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:54:29 by vasco             #+#    #+#             */
/*   Updated: 2022/11/04 17:50:00 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	size_t			i;
	unsigned char	*conv_s;

	i = 0;
	conv_s = (unsigned char *)ptr;
	while (i < n)
	{
		*(conv_s + i) = '\0';
		i++;
	}
}
