/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:15:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/07 18:11:30 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	free_all(t_fra *fra)
{
	int	cnt;

	cnt = 0;
	free(fra);
}

void	my_mlx_pixel_put(t_fra *fra, int x, int y, int color)
{
	char	*dst;

	dst = fra->mlx.addr + (y * fra->mlx.line_length
			+ x * (fra->mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_mlx(t_fra *fra)
{
	fra->mlx.mlx_ptr = mlx_init();
	fra->mlx.mlx_win = mlx_new_window(fra->mlx.mlx_ptr, fra->resX, fra->resY, "FraTol");
}

void	print_raydir_x_y(t_cube *cub, int x)
{
	int		y;

	y = 0;
	cub->ZBuffer[x] = cub->ray.perpWallDist;
	text_calc(cub);
	while (y < cub->resY)
	{
		if (y < cub->ray.drawStart)
			y = paint_ceiling(cub, x, y);
		else if (y > cub->ray.drawStart && y < cub->ray.drawEnd)
			y = paint_wall(cub, x, y);
		else if (y > cub->ray.drawEnd)
			y = paint_floor(cub, x, y);
		y++;
	}
}

int		main ()
{
	t_fra	*fra;

	fra = ft_calloc(sizeof(t_fra), 1);
	fra->temp = 0;	
	fra->resX = 800;
	fra->resY = 800;

	printf("Hola Majo que quieres de pincho");
	free_all(fra);
	system("leaks fractol");
	return(0);
}
