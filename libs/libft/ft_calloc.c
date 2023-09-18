/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:54:38 by vasco             #+#    #+#             */
/*   Updated: 2022/11/04 17:52:28 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char			*ptr;
	unsigned int	tot;
	size_t			i;

	tot = size * nitems;
	ptr = malloc(tot);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (tot > 0)
	{
		ptr[i] = 0;
		i++;
		tot--;
	}
	return ((void *)ptr);
}
