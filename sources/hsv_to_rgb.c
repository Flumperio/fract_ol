/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:47:24 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/11 15:44:02 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void HsvToRgb(t_fra *fra, unsigned char h, unsigned char s, unsigned char v)
{
	unsigned char	region;
	unsigned char	rema;
	unsigned char	p;
	unsigned char	q;
	unsigned char	t;
	if (s == 0)
	{
		fra->r = v;
		fra->g = v;
		fra->b = v;
	return ;
	}
	region = h / 43;
	rema = (h - (region * 43)) * 6; 
	p = (v * (255 - s)) >> 8;
	q = (v * (255 - ((s * rema) >> 8))) >> 8;
	t = (v * (255 - ((s * (255 - rema)) >> 8))) >> 8;
	if (region == 0)
	{
		fra->r = v;
		fra->g = t;
		fra->b = p;
	}
	else if (region == 1)
	{
		fra->r = q;
		fra->g = v; 
		fra->b = p;
	}
	else if (region == 2)
	{	
		fra->r = p;
		fra->g = v;
		fra->b = t;
	}
	else if (region == 3)
	{
		fra->r = p;
		fra->g = q;
		fra->b = v;
	}
	else if (region == 4)
	{
		fra->r = t;
		fra->g = p;
		fra->b = v;
	}
	else
	{
		fra->r = v;
		fra->g = p;
		fra->b = q;
	}
}
