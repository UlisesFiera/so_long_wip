/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:53:15 by ulfernan          #+#    #+#             */
/*   Updated: 2024/11/28 17:53:15 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	ft_pixel_put(t_data_texture *texture, int x, int y, int color)
{
	char	*dst;

	dst = texture->addr + (y *texture->line_length + x * (texture->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}