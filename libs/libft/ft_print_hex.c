/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:01:41 by vasferre          #+#    #+#             */
/*   Updated: 2022/11/28 16:52:58 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_len(unsigned int num)
{
	int		i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex (num / 16, format);
		ft_put_hex (num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd ((num + 48), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd ((num - 10 + 'a'), 1);
			else if (format == 'X')
				ft_putchar_fd ((num - 10 + 'A'), 1);
		}
	}
}

int	ft_prthex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex (num, format);
	return (ft_hex_len(num));
}
