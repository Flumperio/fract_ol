/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_mandel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:19:27 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/15 16:18:30 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_val_m(t_fra *fra)
{
	fra->man.zoom = 1;
	fra->man.moveX = 0;
	fra->man.moveY = 0;
	fra->man.maxIterations = 300;
	fra->man.cRe = -0.7;
	fra->man.cIm = 0.28024;
}

int	calc_i_m(t_fra *fra)
{
	int	i;

	i = 0;
	while (i < fra->man.maxIterations)
	{
		fra->man.oldRe = fra->man.newRe;
		fra->man.oldIm = fra->man.newIm;
		fra->man.newRe = fra->man.oldRe * fra->man.oldRe
			- fra->man.oldIm * fra->man.oldIm + fra->man.pr;
		fra->man.newIm = 2 * fra->man.oldRe
			* fra->man.oldIm + fra->man.pi;
		if ((fra->man.newRe * fra->man.newRe
				+ fra->man.newIm * fra->man.newIm) > 4)
			break ;
		i++;
	}
	return (i);
}

int	fracta_Mandel(t_fra *fra)
{
	fra->man.y = 0;
	while (fra->man.y < fra->resY)
	{
		fra->man.x = 0;
		while (fra->man.x < fra->resX)
		{
			fra->man.pr = 1.5 * (fra->man.x - fra->resX / 2) / (0.5 * fra->man.zoom * fra->resX) + fra->man.moveX;
			fra->man.pi = (fra->man.y - fra->resY / 2) / (0.5 * fra->man.zoom * fra->resY) + fra->man.moveY;
			fra->man.newRe = fra->man.newIm = fra->man.oldRe = fra->man.oldIm = 0;
			fra->man.i = calc_i_m(fra);
			HsvToRgb(fra, fra->man.i % 256, 255, 255
				* (fra->man.i < fra->man.maxIterations));
			fra->color = to_rgb(fra->r, fra->g, fra->b);
			my_mlx_pixel_put(fra, fra->man.x, fra->man.y, fra->color);
			fra->man.x++;
		}
		fra->man.y++;
	}
	return (0);
}
