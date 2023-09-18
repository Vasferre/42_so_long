/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:06:36 by vasferre          #+#    #+#             */
/*   Updated: 2022/11/28 16:36:57 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_prtchr(char c)
{
	return (write (1, &c, 1));
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[1], 1);
		i++;
	}
}

int	ft_prtstr(char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
		return (ft_prtstr("(null)"));
	while (str[++i])
		write (1, &str[i], 1);
	return (i);
}

int	ft_prtnum(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_prtstr(num);
	free (num);
	return (len);
}
