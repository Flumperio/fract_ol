/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:19:27 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/11 15:20:31 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fractol.h"

int fracta_Julia(t_fra *fra)
{
	int i;
	int x;
	int y;

	y = 0;
	fra->jul.zoom = 1;
	fra->jul.moveX = 0;
	fra->jul.moveY = 0;
	fra->jul.maxIterations = 300;
	fra->jul.cRe = -0.7;
	fra->jul.cIm = 0.27015;
	while(y < fra->resY)
	{
		x= 0;
		while(x < fra->resX)
		{
			fra->jul.newRe = 1.5 * (x - fra->resX / 2) / (0.5 * fra->jul.zoom * fra->resX) + fra->jul.moveX;
			fra->jul.newIm = (y - fra->resY/ 2) / (0.5 * fra->jul.zoom * fra->resY) + fra->jul.moveY;
			i = 0;
			while(i < fra->jul.maxIterations)
			{
				fra->jul.oldRe = fra->jul.newRe;
				fra->jul.oldIm = fra->jul.newIm;
				fra->jul.newRe = fra->jul.oldRe * fra->jul.oldRe - fra->jul.oldIm * fra->jul.oldIm + fra->jul.cRe;
				fra->jul.newIm = 2 * fra->jul.oldRe * fra->jul.oldIm + fra->jul.cIm;
				if((fra->jul.newRe * fra->jul.newRe + fra->jul.newIm * fra->jul.newIm) > 4)
					break;
				i++;
			}
			HsvToRgb(fra, i % 256, 255, 255 * (i < fra->jul.maxIterations));
			fra->color = to_rgb(fra->r, fra->g, fra->b);
			my_mlx_pixel_put(fra, x, y, fra->color);
		x++;
		}
	y++;
	}
	return (0);
}
