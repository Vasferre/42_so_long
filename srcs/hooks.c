/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:19:04 by vasferre          #+#    #+#             */
/*   Updated: 2023/05/29 16:19:04 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//funcao responsavel por atualizar o movimento do jogador
//quando os colletaveis forem 0 e o jogador chegar a saida o jogo fecha
static void	player_move(int keycode, t_game *game)
{
	if (keycode == W || keycode == UP_ARROW)
	{
		game->player_y -= 1;
		move_w(game);
	}
	else if (keycode == S || keycode == DOWN_ARROW)
	{
		game->player_y += 1;
		move_s(game);
	}
	else if (keycode == D || keycode == RIGHT_ARROW)
	{
		game->player_x += 1;
		move_d(game);
	}
	else if (keycode == A || keycode == LEFT_ARROW)
	{
		game->player_x -= 1;
		move_a(game);
	}
	if (player_on_exit(game) && game->collectibles == 0)
	{
		destroy(game);
	}
}

//funcao responsavel de fehcar o jogo caso o esc seja pressioando
//conta os steps
static int	exit_esc(int keycode, t_game *game)
{
	if (keycode == ESC)
		destroy (game);
	else if (!game->endgame)
	{
		player_move (keycode, game);
		printf ("Steps: %d\n", game->steps);
	}
	return (0);
}

//
void	hooks(t_game *game)
{
	mlx_hook (game->mlx.mlx_win, 2, 1L << 0, exit_esc, game);
	mlx_hook (game->mlx.mlx_win, 17, 1L << 17, destroy, game);
	mlx_hook (game->mlx.mlx_win, 9, 1L << 21, game_map, game);
}
