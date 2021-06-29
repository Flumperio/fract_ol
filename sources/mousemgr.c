/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousemgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:33:37 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/29 13:21:56 by juasanto         ###   ########.fr       */
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
		if (fra->hlp.zoom)
			free(fra->hlp.zoom);
		fra->jul.zoom *= pow(1.001, 30);
		fra->hlp.zoom = ft_itoa((int)fra->jul.zoom);
		fra->jul.moveX += (0.0003 * centX / fra->jul.zoom);
		fra->jul.moveY -= (0.0003 * centY / fra->jul.zoom);
	}
	else if (button == 4)
	{
		if (fra->hlp.zoom)
			free(fra->hlp.zoom);
		fra->jul.zoom *= pow(1.001, 30);
		fra->jul.zoom /= pow(1.001, 40);
		fra->hlp.zoom = ft_itoa((int)fra->jul.zoom);
		fra->jul.moveX += (0.0003 * centX / fra->jul.zoom);
		fra->jul.moveY -= (0.0003 * centY / fra->jul.zoom);
	}
	return (0);
}

int	mouse_move(int x, int y, t_fra *fra)
{
	if ((x <= fra->resX && x > 0) && (y <= fra->resY && y > 0))
	{
		if (fra->hlp.x)
			free(fra->hlp.x);
		if (fra->hlp.y)
			free(fra->hlp.y);
		fra->hlp.x = ft_itoa(x);
		fra->hlp.y = ft_itoa(y);
	}
	return (0);
}
