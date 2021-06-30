/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:15:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/30 10:01:29 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	string_to_Window(t_fra *fra)
{
	mlx_clear_window(fra->mlx.mlx_ptr, fra->mlx.mlx_win_h);
	if (fra->hlp.x && fra->hlp.y && fra->hlp.zoom)
	{
		mlx_string_put(fra->mlx.mlx_ptr, fra->mlx.mlx_win_h, 10, 20,
			255, "X:");
		mlx_string_put(fra->mlx.mlx_ptr, fra->mlx.mlx_win_h, 40, 20,
			255, fra->hlp.x);
		mlx_string_put(fra->mlx.mlx_ptr, fra->mlx.mlx_win_h, 10, 40,
			255, "Y:");
		mlx_string_put(fra->mlx.mlx_ptr, fra->mlx.mlx_win_h, 40, 40,
			255, fra->hlp.y);
		mlx_string_put(fra->mlx.mlx_ptr, fra->mlx.mlx_win_h, 10, 60,
			255, "Zoom ABS:");
		mlx_string_put(fra->mlx.mlx_ptr, fra->mlx.mlx_win_h, 110, 60,
			255, fra->hlp.zoom);
	}
}

int	raycast_loop(t_fra *fra)
{
	pl_move(fra);
	fra->mlx.img = mlx_new_image(fra->mlx.mlx_ptr, fra->resX, fra->resY);
	fra->mlx.addr = mlx_get_data_addr(fra->mlx.img, &fra->mlx.bits_per_pixel,
			&fra->mlx.line_length, &fra->mlx.endian);
	if (fra->argv[0] == '1')
		fracta_Julia(fra);
	else if (fra->argv[0] == '2')
		fracta_Mandel(fra);
	else
		fracta_Newton(fra);
	mlx_put_image_to_window(fra->mlx.mlx_ptr,
		fra->mlx.mlx_win, fra->mlx.img, 0, 0);
	string_to_Window(fra);
	mlx_destroy_image(fra->mlx.mlx_ptr, fra->mlx.img);
	return (0);
}

void	raycast(t_fra *fra)
{
	init_mlx(fra);
	selec_init(fra);
	mlx_mouse_hook(fra->mlx.mlx_win, mouse_hook, fra);
	mlx_hook(fra->mlx.mlx_win, 6, 1L << 6, mouse_move, fra);
	mlx_hook(fra->mlx.mlx_win, 2, 1L << 0, key_press, fra);
	mlx_hook(fra->mlx.mlx_win, 3, 1L << 1, key_relea, fra);
	mlx_hook(fra->mlx.mlx_win, 17, 1L << 17, ui_cross_exit, fra);
	mlx_loop_hook(fra->mlx.mlx_ptr, raycast_loop, fra);
	mlx_loop(fra->mlx.mlx_ptr);
}

void	chk_args (t_fra *fra, int argc, char **argv)
{
	if (argc <= 1)
		ft_msgerror("Número de argumentos erróneo.\n\
Las opciones disponibles son:\n\
1 --> Julia\n2 --> Mandelbroth\n3 --> Newton", 1);
	if ((argv[1][0] == '1' || argv[1][0] == '2' || argv[1][0] == '3')
			&& !argv[1][1])
		fra->argv = argv[1];
	else
		ft_msgerror("Número de argumentos erróneo.\n\
Las opciones disponibles son:\n\
1 --> Julia\n2 --> Mandelbroth\n3 --> Newton", 1);
}

int	main (int argc, char **argv)
{
	t_fra	*fra;

	fra = ft_calloc(sizeof(t_fra), sizeof(t_fra));
	chk_args(fra, argc, argv);
	raycast(fra);
	ft_free_struct(fra);
	return (0);
}
