/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:19:19 by vasferre          #+#    #+#             */
/*   Updated: 2023/05/29 16:19:19 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//destroi a imagem e da load a nova e guarda na struct
static void	update_image(char key, t_game *game)
{
	mlx_destroy_image(game->mlx.mlx_ptr, game->barou);
	if (key == 'w')
		game->barou = mlx_xpm_file_to_image
			(game->mlx.mlx_ptr, "images/barou.xpm", \
			&game->img_width, &game->img_height);
	else if (key == 's')
		game->barou = mlx_xpm_file_to_image
			(game->mlx.mlx_ptr, "images/barou.xpm", \
			&game->img_width, &game->img_height);
	else if (key == 'd')
		game->barou = mlx_xpm_file_to_image
			(game->mlx.mlx_ptr, "images/barou.xpm", \
			&game->img_width, &game->img_height);
	else if (key == 'a')
		game->barou = mlx_xpm_file_to_image
			(game->mlx.mlx_ptr, "images/barou.xpm", \
			&game->img_width, &game->img_height);
}

//resposavel pelo movimento do player
//verificar colisoes, colletavies e a saida
void	move_w(t_game *game)
{
	update_image('w', game);
	if (game->map[game->player_y][game->player_x] == 'E'
			&& game->collectibles == 0)
	{
		mlx_clear_window(game->mlx.mlx_ptr, game->mlx.mlx_win);
		game->map[game->player_y + 1][game->player_x] = '0';
		game->steps++;
		game->endgame = 1;
		game_map(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
			|| game->map[game->player_y][game->player_x] == 'E')
		game->player_y += 1;
	else
	{
		mlx_clear_window(game->mlx.mlx_ptr, game->mlx.mlx_win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->collectibles -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y + 1][game->player_x] = '0';
		game->steps++;
		game_map(game);
	}
}

void	move_s(t_game *game)
{
	update_image('s', game);
	if (game->map[game->player_y][game->player_x] == 'E'
			&& game->collectibles == 0)
	{
		mlx_clear_window(game->mlx.mlx_ptr, game->mlx.mlx_win);
		game->map[game->player_y - 1][game->player_x] = '0';
		game->steps++;
		game->endgame = 1;
		game_map(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
			|| game->map[game->player_y][game->player_x] == 'E')
		game->player_y -= 1;
	else
	{
		mlx_clear_window(game->mlx.mlx_ptr, game->mlx.mlx_win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->collectibles -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y - 1][game->player_x] = '0';
		game->steps++;
		game_map(game);
	}
}

void	move_d(t_game *game)
{
	update_image('d', game);
	if (game->map[game->player_y][game->player_x] == 'E'
			&& game->collectibles == 0)
	{
		mlx_clear_window(game->mlx.mlx_ptr, game->mlx.mlx_win);
		game->map[game->player_y][game->player_x - 1] = '0';
		game->steps++;
		game->endgame = 1;
		game_map(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
			|| game->map[game->player_y][game->player_x] == 'E')
		game->player_x -= 1;
	else
	{
		mlx_clear_window(game->mlx.mlx_ptr, game->mlx.mlx_win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->collectibles -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x - 1] = '0';
		game->steps++;
		game_map(game);
	}
}

void	move_a(t_game *game)
{
	update_image('a', game);
	if (game->map[game->player_y][game->player_x] == 'E'
			&& game->collectibles == 0)
	{
		mlx_clear_window(game->mlx.mlx_ptr, game->mlx.mlx_win);
		game->map[game->player_y][game->player_x + 1] = '0';
		game->steps++;
		game->endgame = 1;
		game_map(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
			|| game->map[game->player_y][game->player_x] == 'E')
		game->player_x += 1;
	else
	{
		mlx_clear_window(game->mlx.mlx_ptr, game->mlx.mlx_win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->collectibles -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x + 1] = '0';
		game->steps++;
		game_map(game);
	}
}
