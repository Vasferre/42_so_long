/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:19:22 by vasferre          #+#    #+#             */
/*   Updated: 2023/05/29 16:19:22 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//le o mapa 
static char	*read_from_file(int fd)
{
	char	*holder_map;
	char	*holder;
	char	*line;

	holder_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line || *line == '\n')
		{
			while (line != NULL)
			{
				free (line);
				line = get_next_line(fd);
			}
			break ;
		}
		holder = holder_map;
		holder_map = ft_strjoin(holder, line);
		free (line);
		free (holder);
	}
	return (holder_map);
}

char	**read_map(char *path)
{
	int		fd;
	char	**map;
	char	*holder_map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	holder_map = read_from_file(fd);
	map = ft_split(holder_map, '\n');
	free(holder_map);
	close(fd);
	return (map);
}
