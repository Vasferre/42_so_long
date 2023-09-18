/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:19:11 by vasferre          #+#    #+#             */
/*   Updated: 2023/05/29 16:19:11 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//verifica se todas as linhas tem o mesmo tamanho
//usando o strlen verifica se a linha atual e igual a 1 linha
static int	is_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]) 
			&& map[i][ft_strlen(map[i])] - 1 == '\n')
			return (0);
		i++;
	}
	return (1);
}

//verifica o mapa para ver se e rodeado de 1
static int	check_wall(char **map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map[i] != NULL)
		i++;
	if (!map[0])
		return (0);
	while (j < ft_strlen(map[0]) - 1)
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	len = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

//checka se todas as condicoes estao presentes no mapa
static int	char_check(t_game *game)
{
	int	i;
	int	j;

	game->collectibles = 0;
	game->player = 0;
	game->exit = 0;
	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
				game->player++;
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] == 'C')
				game->collectibles++;
			j++;
		}
		i++;
	}
	if (game->player != 1 || game->exit != 1 || game->collectibles == 0)
		return (0);
	return (1);
}

//verifica se todos os chars presentes no mapa sao alguma destas letras
static int	is_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (j < ft_strlen(map[i]) - 1)
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//chama todas as funcoes
int	map_checked(t_game *game)
{
	if (is_map(game->map) && game->map[0] != NULL && check_wall(game->map) 
		&& char_check(game)
		&& is_valid(game->map))
		return (1);
	return (0);
}
