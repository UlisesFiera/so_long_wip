/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:40:39 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/07 16:40:19 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	path_find(char **matrix, int y, int x)
{
	matrix[y][x] = 'P';
	ft_printf("Player: %i-%i\n", y, x);
	if (matrix[y - 1][x] == 'E' || matrix[y][x - 1] == 'E' ||
		matrix[y][x + 1] == 'E' || matrix[y + 1][x] == 'E')
		return (0);
	if (matrix[y - 1][x] == '0' || matrix[y - 1][x] == 'C')
		path_find(matrix, y - 1, x);
	if (matrix[y][x - 1] == '0' || matrix[y][x - 1] == 'C')
		path_find(matrix, y, x - 1);
	if (matrix[y][x + 1] == '0' || matrix[y][x + 1] == 'C')
		path_find(matrix, y, x + 1);
	if (matrix[y + 1][x] == '0' || matrix[y + 1][x] == 'C')
		path_find(matrix, y + 1, x);
	return (1);
}

int	player_pos(char **matrix, int *y, int *x)
{
	int	i;
	int j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'P')
			{
				*y = i;
				*x = j;
				return (0);
			}	
			j++;
		}
		i++;
	}
	ft_printf("Missing player 'P' item\n");
	return (1);
}

int	backtracking(char **matrix)
{
	int y;
	int x;

	y = 0;
	x = 0;
	if (player_pos(matrix, &y, &x))
		return (1);
	if (path_find(matrix, y, x))
		return (1);
	return (0);
}