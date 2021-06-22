/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousemgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:33:37 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/22 10:47:33 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_hook(int button, int x, int y, t_fra *fra)
{
	int		centX;
	int		centY;

	centX = x - (fra->resX / 2);
	centY = y - (fra->resY / 2 - 1);
	if (button == 5)
	{
		fra->jul.zoom *= pow(1.001, 30);
		fra->jul.moveX += (0.0003 * centX / fra->jul.zoom);
		fra->jul.moveY -= (0.0003 * centY / fra->jul.zoom);
	}
	else if (button == 4)
	{
		fra->jul.zoom /= pow(1.001, 40);
		fra->jul.moveX += (0.0003 * centX / fra->jul.zoom);
		fra->jul.moveY -= (0.0003 * centY / fra->jul.zoom);
	}
	return (0);
}

int		mouse_move(int x, int y, t_fra *fra)
{
	char	*texto="Hola";
		fra->temp = fra->temp;
	if(x <= fra->resX && x > 0 && y <= fra->resY && y > 0)
		//printf("x: %i, y: %i\n", x, y);
		mlx_string_put(fra->mlx.mlx_ptr, fra->mlx.mlx_win, 10, 10, 0x000000, texto);
	return(0);
}
