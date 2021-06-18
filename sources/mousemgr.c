/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousemgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:33:37 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/18 17:18:30 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_hook(int button, int x, int y, t_fra *fra)
{
	//fra->jul.moveX=0;
	//fra->jul.moveY=0;
	int		centX;
	int		centY; 

	centX = fra->resX / 2;
	centY = fra->resY / 2 - 1;
	fra->temp = button;
	if (button == 5)
	{
		fra->jul.zoom *= pow(1.001, 40);
	//	fra->jul.moveX = centX - x;
	//	fra->jul.moveY = centY - y;
		printf("moveX: %f - moveY: %f - zoom: %f\n",fra->jul.moveX, fra->jul.moveY, fra->jul.zoom);
		printf("Buttton:  x: %i - y: %i\n", x, fra->resY - 1 - y);
	}
	else if (button == 4)
	{
		fra->jul.zoom /= pow(1.001, 40);
	//	fra->jul.moveX = centX - x;
	//	fra->jul.moveY = centY - y;
		printf("moveX: %f - moveY: %f - zoom: %f\n",fra->jul.moveX, fra->jul.moveY, fra->jul.zoom);
		printf("Buttton:  x: %i - y: %i\n", x, fra->resY - 1 - y);
	}
	else
		printf("Buttton:  x: %i - y: %i\n", x, y);
	return (0);
}
