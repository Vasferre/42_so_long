/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:18:51 by vasferre          #+#    #+#             */
/*   Updated: 2023/07/06 18:39:19 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_path(char **sol, t_game *game, int l, int c)
{
	int	count;

	count = 0;
	if (game->map[l][c] == 'E')
	{
		game->exit = true;
		return (count);
	}
	if (game->map[l][c] == 'C' && sol[l][c] != 1)
		count++;
	if (sol[l][c] == 1)
		return (count);
	if (is_validate(game, l, c) == false)
		return (count);
	sol[l][c] = 1;
	count += find_path(sol, game, l + 1, c);
	count += find_path(sol, game, l, c + 1);
	count += find_path(sol, game, l - 1, c);
	count += find_path(sol, game, l, c - 1);
	return (count);
}

bool	is_validate(t_game *game, int l, int c)
{
	if (l >= 0 && l < game->rows && c >= 0 && c < game->columns
		&& game->map[l][c] != '1')
		return (true);
	return (false);
}

char	*new_copy(int columns)
{
	char	*str;
	int		i;

	str = (char *)malloc((columns + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[columns] = '\0';
	i = -1;
	while (++i < columns)
		str[i] = '0';
	return (str);
}

char	**copy(int rows, int columns)
{
	char	**sol;
	int		l;

	sol = (char **)malloc((rows + 1) * sizeof(char *));
	if (!sol)
		return (NULL);
	sol[rows] = 0;
	l = -1;
	while (++l < rows)
	{
		sol[l] = new_copy(columns);
		if (!sol[l])
			return (NULL);
	}
	return (sol);
}

int	pathed(t_game *game)
{
	char	**sol;
	int		i;
	int		var;

	i = 0;
	game->exit = 0;
	sol = copy(game->rows, game->columns);
	var = find_path(sol, game, game->player_y, game->player_x);
	while (sol[i] != NULL)
		free (sol[i++]);
	free (sol);
	return (var == game->collectibles && game->exit == true);
}
