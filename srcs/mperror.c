/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mperror.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:17:47 by vasferre          #+#    #+#             */
/*   Updated: 2023/05/18 15:30:56 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//escreve e da exit
void	ft_mperror(char *error)
{
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	exit (1);
}
