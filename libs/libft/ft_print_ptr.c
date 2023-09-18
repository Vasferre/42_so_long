/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:01:29 by vasferre          #+#    #+#             */
/*   Updated: 2022/11/28 16:54:31 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lenptr(uintptr_t num)
{
	size_t		i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

void	ft_putptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_putptr (ptr / 16);
		ft_putptr (ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd ((ptr + 48), 1);
		else
			ft_putchar_fd ((ptr - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int		len;

	if (ptr == 0)
		return (write(1, "(nil)", 5));
	len = write (1, "0x", 2);
	ft_putptr (ptr);
	len += ft_lenptr (ptr);
	return (len);
}
