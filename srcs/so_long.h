/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:05:18 by vasferre          #+#    #+#             */
/*   Updated: 2023/06/01 19:05:18 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"
# include <stdbool.h>
# include "keys.h"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;

}	t_mlx;

typedef struct s_game
{
	char	**map;
	void	*tiles;
	void	*wall;
	void	*barou;
	void	*ball;
	void	*baliza;
	int		columns;
	int		rows;
	int		img_width;
	int		img_height;
	int		collectibles;
	int		player;
	int		exit;
	int		player_x;
	int		player_y;
	int		steps;
	int		endgame;
	t_mlx	mlx;
}	t_game;

//destroyMLX
int		destroy(t_game *game);
void	freed(char **map);
//player
void	hooks(t_game *game);
void	move_w(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);
void	move_a(t_game *game);
//tileschecker
int		game_map(t_game *game);
void	mlx(t_game *game, void *image, int x, int y);
int		player_on_exit(t_game *game);
//hooks
void	hooks(t_game *game);
void	steps_counter(t_game *game);
//mperror
void	ft_mperror(char *error);
//init_mlx
void	init_initializer(t_game *game);
//map_checker
int		map_checked(t_game *game);
//readmap
char	**read_map(char *path);
int		pathed(t_game *game);
void	verif(t_game *game);
void	startmap(t_game *game);
bool	is_validate(t_game *game, int l, int c);
//mperror
void	ft_mperror(char *error);

#endif