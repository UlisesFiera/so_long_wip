/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:20:56 by ulfernan          #+#    #+#             */
/*   Updated: 2024/12/15 21:59:40 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int		collision(t_data_load *load, int x, int y)
{
	int			map_x;
    int			map_y;
	static int	visited_y = 0;
	static int	visited_x = 0;
	static int	collected = 0;
	static int	open_exit = 0;
    
	map_x = x / load->pixel_x;
	map_y = y / load->pixel_y;
	map_copy(load);
	if (load->map_matrix[map_y][map_x] == '1')
	{
		free_matrix(load);
		return (1);
	}
	if (load->map_matrix[map_y][map_x] == 'C' && map_y != visited_y && map_x != visited_x)
	{
		collected++;
		visited_y = map_y;
		visited_x = map_x;
		ft_printf("count: %i\n", collected);
		if (collected == load->collectible_count)
			open_exit = 1;
	}
	if (load->map_matrix[map_y][map_x] == 'E')
	{
		if (open_exit == 1)
		{
			free_matrix(load);
			free_load(load);
			exit(0);
		}
		free_matrix(load);
		return (1);
	}
	free_matrix(load);
	return (0);
}