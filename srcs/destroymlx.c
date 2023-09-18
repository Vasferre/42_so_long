/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroymlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:19:00 by vasferre          #+#    #+#             */
/*   Updated: 2023/05/29 16:19:00 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//funcao para dar free ao array para prevenir leaks
void	freed(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

//funcao encarregue de destruir as imagens
int	destroy(t_game *game)
{
	freed (game->map);
	mlx_destroy_image (game->mlx.mlx_ptr, game->tiles);
	mlx_destroy_image (game->mlx.mlx_ptr, game->wall);
	mlx_destroy_image (game->mlx.mlx_ptr, game->barou);
	mlx_destroy_image (game->mlx.mlx_ptr, game->ball);
	mlx_destroy_image (game->mlx.mlx_ptr, game->baliza);
	mlx_destroy_window (game->mlx.mlx_ptr, game->mlx.mlx_win);
	mlx_destroy_display (game->mlx.mlx_ptr);
	free (game->mlx.mlx_ptr);
	exit (0);
	return (0);
}
