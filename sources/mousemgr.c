/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousemgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:33:37 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/28 18:59:15 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_hook(int button, int x, int y, t_fra *fra)
{
	int		centX;
	int		centY;
	char	*temp;

	centX = x - (fra->resX / 2);
	centY = y - (fra->resY / 2 - 1);

	if (button == 5)
	{
		temp = NULL;
		fra->jul.zoom *= pow(1.001, 30);
		temp = ft_itoa((int)fra->jul.zoom);
		fra->hlp.zoom = temp;
		fra->jul.moveX += (0.0003 * centX / fra->jul.zoom);
		fra->jul.moveY -= (0.0003 * centY / fra->jul.zoom);
		free(temp);
	}
	else if (button == 4)
	{
		temp = NULL;
		fra->jul.zoom /= pow(1.001, 40);
		temp = ft_itoa((int)fra->jul.zoom);
		fra->hlp.zoom = temp;
		fra->jul.moveX += (0.0003 * centX / fra->jul.zoom);
		fra->jul.moveY -= (0.0003 * centY / fra->jul.zoom);
		free(temp);
	}
	return (0);
}

int		mouse_move(int x, int y, t_fra *fra)
{
	char	*temp1;
	char	*temp2;

	temp1 = ft_calloc(sizeof(char), 10);
	temp2 = ft_calloc(sizeof(char), 10);
	if((x <= fra->resX && x > 0) && (y <= fra->resY && y > 0))
	{
		temp1 = ft_itoa(x);
		temp2 = ft_itoa(y);
		fra->hlp.x = temp1;
		fra->hlp.y = temp2;
		free(temp1);
		free(temp2);
	}
	return(0);
}
