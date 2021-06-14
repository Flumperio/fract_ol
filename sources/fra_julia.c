/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:19:27 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/14 16:36:04 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_val(t_fra *fra)
{
	fra->jul.zoom = 1;
	fra->jul.moveX = 0;
	fra->jul.moveY = 0;
	fra->jul.maxIterations = 300;
	fra->jul.cRe = -0.7;
	fra->jul.cIm = 0.28024;
}

int	calc_i(t_fra *fra)
{
	int	i;

	i = 0;
	while (i < fra->jul.maxIterations)
	{
		fra->jul.oldRe = fra->jul.newRe;
		fra->jul.oldIm = fra->jul.newIm;
		fra->jul.newRe = fra->jul.oldRe * fra->jul.oldRe
			- fra->jul.oldIm * fra->jul.oldIm + fra->jul.cRe;
		fra->jul.newIm = 2 * fra->jul.oldRe
			* fra->jul.oldIm + fra->jul.cIm;
		if ((fra->jul.newRe * fra->jul.newRe
				+ fra->jul.newIm * fra->jul.newIm) > 4)
			break ;
		i++;
	}
	return (i);
}

int	fracta_Julia(t_fra *fra)
{
	fra->jul.y = 0;
	//init_val(fra);
	while (fra->jul.y < fra->resY)
	{
		fra->jul.x = 0;
		while (fra->jul.x < fra->resX)
		{
			fra->jul.newRe = 1.5 * (fra->jul.x - fra->resX / 2)
				/ (0.5 * fra->jul.zoom * fra->resX) + fra->jul.moveX;
			fra->jul.newIm = (fra->jul.y - fra->resY / 2)
				/ (0.5 * fra->jul.zoom * fra->resY) + fra->jul.moveY;
			fra->jul.i = calc_i(fra);
			HsvToRgb(fra, fra->jul.i % 256, 255, 255
				* (fra->jul.i < fra->jul.maxIterations));
			fra->color = to_rgb(fra->r, fra->g, fra->b);
			my_mlx_pixel_put(fra, fra->jul.x, fra->jul.y, fra->color);
			fra->jul.x++;
		}
		fra->jul.y++;
	}
	return (0);
}
