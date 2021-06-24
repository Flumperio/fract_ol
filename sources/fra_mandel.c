/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_mandel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:19:27 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/24 10:03:01 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	calc_i_m(t_fra *fra)
{
	int	i;

	i = 0;
	fra->jul.newRe = 0;
	fra->jul.newIm = 0;
	fra->jul.oldRe = 0;
	fra->jul.oldIm = 0;
	while (i < fra->jul.maxIterations)
	{
		fra->jul.oldRe = fra->jul.newRe;
		fra->jul.oldIm = fra->jul.newIm;
		fra->jul.newRe = fra->jul.oldRe * fra->jul.oldRe
			- fra->jul.oldIm * fra->jul.oldIm + fra->jul.pr;
		fra->jul.newIm = 2 * fra->jul.oldRe
			* fra->jul.oldIm + fra->jul.pi;
		if ((fra->jul.newRe * fra->jul.newRe
				+ fra->jul.newIm * fra->jul.newIm) > 4)
			break ;
		i++;
	}
	return (i);
}

int	fracta_Mandel(t_fra *fra)
{
	fra->jul.y = 0;
	while (fra->jul.y < fra->resY)
	{
		fra->jul.x = 0;
		while (fra->jul.x < fra->resX)
		{
			fra->jul.pr = 1.5 * (fra->jul.x - fra->resX / 2) / (0.5
					* fra->jul.zoom * fra->resX) + fra->jul.moveX;
			fra->jul.pi = (fra->jul.y - fra->resY / 2) / (0.5
					* fra->jul.zoom * fra->resY) + fra->jul.moveY;
			fra->jul.i = calc_i_m(fra);
			HsvToRgb(fra, fra->jul.i % 256, 255, 255
				* (fra->jul.i < fra->jul.maxIterations));
			fra->color = fra->temp + (to_rgb(fra->r, fra->g, fra->b));
			my_mlx_pixel_put(fra, fra->jul.x, fra->jul.y, fra->color);
			fra->jul.x++;
		}
		fra->jul.y++;
	}
	return (0);
}
