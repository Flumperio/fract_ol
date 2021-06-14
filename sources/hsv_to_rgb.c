/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:47:24 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/14 13:26:40 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	condi_if1(t_fra *fra, int v)
{
	fra->r = v;
	fra->g = fra->hsv.p;
	fra->b = fra->hsv.q;
	if (fra->hsv.region == 0)
	{
		fra->r = v;
		fra->g = fra->hsv.t;
		fra->b = fra->hsv.p;
	}
	if (fra->hsv.region == 1)
	{
		fra->r = fra->hsv.q;
		fra->g = v;
		fra->b = fra->hsv.p;
	}
}

void	condi_if2(t_fra *fra, int v)
{
	if (fra->hsv.region == 2)
	{	
		fra->r = fra->hsv.p;
		fra->g = v;
		fra->b = fra->hsv.t;
	}
	if (fra->hsv.region == 3)
	{
		fra->r = fra->hsv.p;
		fra->g = fra->hsv.q;
		fra->b = v;
	}
	if (fra->hsv.region == 4)
	{
		fra->r = fra->hsv.t;
		fra->g = fra->hsv.p;
		fra->b = v;
	}
}

void	HsvToRgb(t_fra *fra, unsigned char h, unsigned char s, unsigned char v)
{
	if (s == 0)
	{
		fra->r = v;
		fra->g = v;
		fra->b = v;
		return ;
	}
	fra->hsv.region = h / 43;
	fra->hsv.rema = (h - (fra->hsv.region * 43)) * 6;
	fra->hsv.p = (v * (255 - s)) >> 8;
	fra->hsv.q = (v * (255 - ((s * fra->hsv.rema) >> 8))) >> 8;
	fra->hsv.t = (v * (255 - ((s * (255 - fra->hsv.rema)) >> 8))) >> 8;
	condi_if1(fra, v);
	condi_if2(fra, v);
}
