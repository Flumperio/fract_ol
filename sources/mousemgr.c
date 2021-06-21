/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousemgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:33:37 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/21 15:05:11 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_hook(int button, int x, int y, t_fra *fra)
{
	//fra->jul.moveX=0;
	//fra->jul.moveY=0;
	int		centX;
	int		centY;
	//int		newresX;
	//int		newresY;

	centX = x - (fra->resX / 2);
	centY = y - (fra->resY / 2 - 1);
	fra->temp = button;
	if (button == 5)
	{
		fra->jul.zoom *= pow(1.001, 40);
		fra->jul.moveX += (0.0003 * centX / fra->jul.zoom);
		fra->jul.moveY -= (0.0003 * centY / fra->jul.zoom);
		//fra->jul.oldmouseX = (centX - x); 
		//fra->jul.oldmouseY = (centY - y);
		
		printf("moveX: %f - moveY: %f - zoom: %f\n",fra->jul.moveX, fra->jul.moveY, fra->jul.zoom);
		printf("Buttton:  x: %i - y: %i\n", x, fra->resY - 1 - y);
	}
	else if (button == 4)
	{
		fra->jul.zoom /= pow(1.001, 40);
		printf("moveX: %f - moveY: %f - zoom: %f\n",fra->jul.moveX, fra->jul.moveY, fra->jul.zoom);
		printf("Buttton:  x: %i - y: %i\n", x, fra->resY - 1 - y);
	}
	else
		printf("Buttton:  x: %i - y: %i\n", x, y);
	return (0);
}
