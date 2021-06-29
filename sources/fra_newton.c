/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_newton.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:29:03 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/29 13:51:38 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	calc_i_n(t_fra *fra)
{
	int	i;

	i = 0;
	while (i < fra->jul.maxIterations)
	{
		fra->jul.oldRe = fra->jul.newRe;
		fra->jul.oldIm = fra->jul.newIm;
		fra->jul.newRe = 2 * fra->jul.oldRe / 3 - (
				fra->jul.oldRe * fra->jul.oldRe - fra->jul.oldIm
				* fra->jul.oldIm) / (fra->jul.oldRe * fra->jul.oldRe
				+ fra->jul.oldIm * fra->jul.oldIm) / (fra->jul.oldRe
				* fra->jul.oldRe + fra->jul.oldIm * fra->jul.oldIm) / 3;
		fra->jul.newIm = 2 * fra->jul.oldIm / 3 + 2 * fra->jul.oldRe
			* fra->jul.oldIm / (fra->jul.oldRe * fra->jul.oldRe
				+ fra->jul.oldIm * fra->jul.oldIm) / (fra->jul.oldRe
				* fra->jul.oldRe + fra->jul.oldIm * fra->jul.oldIm) / 3;
		if ((fra->jul.newRe * fra->jul.newRe
				+ fra->jul.newIm * fra->jul.newIm) > 4)
			break ;
		i++;
	}
	return (i);
}

int	fracta_Newton(t_fra *fra)
{
	int	x;
	int	y;

	y = 0;
	while (y < fra->resY)
	{
		x = 0;
		while (x < fra->resX)
		{
			fra->jul.newRe = 1.5 * (x - fra->resX / 2)
				/ (0.5 * fra->jul.zoom * fra->resX) + fra->jul.moveX;
			fra->jul.newIm = (y - fra->resY / 2)
				/ (0.5 * fra->jul.zoom * fra->resY) + fra->jul.moveY;
			fra->jul.i = calc_i_n(fra);
			HsvToRgb(fra, fra->jul.i % 256, 255, 255
				* (fra->jul.i < fra->jul.maxIterations));
			fra->color = fra->temp + (to_rgb(fra->r, fra->g, fra->b));
			my_mlx_pixel_put(fra, x, y, fra->color);
			x++;
		}
		y++;
	}
	return (0);
}
