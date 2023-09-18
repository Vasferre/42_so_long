/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tileschecker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:19:29 by vasferre          #+#    #+#             */
/*   Updated: 2023/05/29 16:19:29 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win, \
	image, x * 32, y * 32);
}

//muda o logar do player e da upadte na struct
static void	player_pos(t_game *game, void *image, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
	mlx(game, image, x, y);
}

//se o player tiver na posicao de saida o programa da exit
int	player_on_exit(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == 'E')
		return (1);
	return (0);
}

//caso nao exista mais coletaveis a saida esta disponivel
static void	open_exit(t_game *game, int x, int y)
{
	if (game->collectibles == 0)
	{
		mlx_destroy_image(game->mlx.mlx_ptr, game->baliza);
		game->baliza = mlx_xpm_file_to_image(game->mlx.mlx_ptr, \
		"images/baliza.xpm", &game->img_width, &game->img_height);
	}
	mlx(game, game->baliza, x, y);
}

//da assign as letras
int	game_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (x < ft_strlen(game->map[y]))
		{
			if (game->map[y][x] == '1')
				mlx(game, game->wall, x, y);
			else if (game->map[y][x] == '0')
				mlx(game, game->tiles, x, y);
			else if (game->map[y][x] == 'P')
				player_pos(game, game->barou, x, y);
			else if (game->map[y][x] == 'C')
				mlx(game, game->ball, x, y);
			else if (game->map[y][x] == 'E')
				open_exit(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
