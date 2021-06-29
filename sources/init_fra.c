/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:12:13 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/29 13:55:19 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_mlx(t_fra *fra)
{
	fra->mlx.mlx_ptr = mlx_init();
	fra->resX = 800;
	fra->resY = 600;
	fra->hlp.x = NULL;
	fra->hlp.y = NULL;
	fra->hlp.zoom = NULL;
	fra->mlx.mlx_win = mlx_new_window(fra->mlx.mlx_ptr,
			fra->resX, fra->resY, "Frac_Tol");
	fra->mlx.mlx_win_h = mlx_new_window(fra->mlx.mlx_ptr,
			200, 90, "Help");
}

void	init_val_jul(t_fra *fra)
{
	fra->jul.zoom = 1;
	fra->jul.moveX = 0;
	fra->jul.moveY = 0;
	fra->jul.maxIterations = 300;
	fra->jul.cRe = -0.8;
	fra->jul.cIm = 0.156;
}

void	init_val_man(t_fra *fra)
{
	fra->jul.zoom = 1;
	fra->jul.moveX = -0.5;
	fra->jul.moveY = 0;
	fra->jul.maxIterations = 128;
}

void	init_val_new(t_fra *fra)
{
	fra->jul.zoom = 1;
	fra->jul.moveX = -0.5;
	fra->jul.moveY = 0;
	fra->jul.maxIterations = 64;
}

void	selec_init(t_fra *fra)
{
	fra->temp = 0;
	if (fra->argv[0] == '1')
		init_val_jul(fra);
	else if (fra->argv[0] == '2')
		init_val_man(fra);
	else
		init_val_new(fra);
}	
