/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:03 by vasferre          #+#    #+#             */
/*   Updated: 2022/11/28 17:01:38 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(va_list args, const char format)
{
	if (format == '%')
		return (ft_prtchr('%'));
	else if (format == 'c')
		return (ft_prtchr(va_arg(args, int)));
	else if (format == 's')
		return (ft_prtstr(va_arg(args, char *)));
	else if (format == 'x')
		return (ft_prthex(va_arg(args, unsigned int), format));
	else if (format == 'X')
		return (ft_prthex(va_arg(args, unsigned int), format));
	else if (format == 'i' || format == 'd')
		return (ft_prtnum(va_arg(args, int)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long long)));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int				i;
	int				len;
	va_list			args;

	i = 0;
	va_start (args, str);
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_format(args, str[i]);
		}
		else
			len += ft_prtchr(str[i]);
		i++;
	}
	va_end (args);
	return (len);
}

/* #include <stdio.h>
int main (void)
{
	int n1;
	int n2;
	n1 = printf("OG: %d\n", 520);
	printf("OG: %d\n", n1);
	n2 = ft_printf("MINE: %d\n", 520);
	ft_printf("%d\n", 520);
	return (0);
} */
