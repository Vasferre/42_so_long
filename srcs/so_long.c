/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:19:26 by vasferre          #+#    #+#             */
/*   Updated: 2023/05/29 16:19:26 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//verifica a terminacao do ficheiro
static int	args_check(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b'
		&& argv [i - 3] == '.')
		return (1);
	return (0);
}

//chama as respetivas funcoes para verificar se o mapa esta em correto
// se nao estiver da return as respetivas mesnsagens de erro
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_mperror("Invalid Format");
	game.map = read_map(argv[1]);
	if (map_checked(&game) && args_check(argv[1]))
	{
		init_initializer(&game);
		verif(&game);
		if (!pathed(&game))
		{
			freed(game.map);
			ft_mperror("Invalid map");
		}
		startmap(&game);
		hooks(&game);
		mlx_loop(game.mlx.mlx_ptr);
		freed(game.map);
		return (0);
	}
	if (game.map)
		freed(game.map);
	ft_mperror("Invalid Map");
}
