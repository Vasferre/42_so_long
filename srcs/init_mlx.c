/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:19:07 by vasferre          #+#    #+#             */
/*   Updated: 2023/05/29 16:19:07 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//designa as imagens as respetivas nomes
static void	img_save(t_game *game)
{
	game->tiles = mlx_xpm_file_to_image (game->mlx.mlx_ptr, \
	"images/tile.xpm", &game->img_width, &game->img_height);
	game->wall = mlx_xpm_file_to_image (game->mlx.mlx_ptr, \
	"images/wall.xpm", &game->img_width, &game->img_height);
	game->barou = mlx_xpm_file_to_image (game->mlx.mlx_ptr, \
	"images/barou.xpm", &game->img_width, &game->img_height);
	game->ball = mlx_xpm_file_to_image (game->mlx.mlx_ptr, \
	"images/ball.xpm", &game->img_width, &game->img_height);
	game->baliza = mlx_xpm_file_to_image (game->mlx.mlx_ptr, \
	"images/baliza.xpm", &game->img_width, &game->img_height);
}

//determina o tamanho da janela
static void	window_size(t_game *game)
{
	int	i;

	game->columns = (ft_strlen(game->map[0]));
	i = 0;
	while (game->map[i] != NULL)
		i++;
	game->rows = i;
}

void	init_initializer(t_game *game)
{
	window_size (game);
	game->steps = 0;
	game->endgame = 0;
}

void	verif(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->columns)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			j++;
		}
		i++;
	}
}

//inicializa o mlx 
void	startmap(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx_ptr, \
	game->columns * 64, game->rows * 64, "SO_LONG");
	img_save (game);
	game_map (game);
}
