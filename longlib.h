/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:47:32 by ulfernan          #+#    #+#             */
/*   Updated: 2024/11/28 11:47:32 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONGLIB_H
# define LONGLIB_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

typedef struct	s_data_load
{
	void		*mlx;
	void		*win;
	char		*map;
	void		*img;
	char		*addr;
	int			map_width;
	int			map_height;
}				t_data_load;

typedef struct	s_data_texture
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data_texture;

void	ft_pixel_put(t_data_texture *texture, int x, int y, int color);
void	esc_window(t_data_load *load);
int		load_textures(t_data_load *load);

#endif