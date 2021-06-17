/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:15:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/17 20:59:26 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_mlx(t_fra *fra);
void	raycast(t_fra *fra);
void	print_frac(t_fra *fra);
int		raycast_loop(t_fra *fra);
/*
 * Fractal
*/

void	init_mlx(t_fra *fra)
{
	fra->mlx.mlx_ptr = mlx_init();
	fra->resX = 800;
	fra->resY = 600;
	fra->mlx.mlx_win = mlx_new_window(fra->mlx.mlx_ptr,
			fra->resX, fra->resY, "Frac_Tol");
}

int	raycast_loop(t_fra *fra)
{
	pl_move(fra);
	fra->mlx.img = mlx_new_image(fra->mlx.mlx_ptr, fra->resX, fra->resY);
	fra->mlx.addr = mlx_get_data_addr(fra->mlx.img, &fra->mlx.bits_per_pixel,
			&fra->mlx.line_length, &fra->mlx.endian);
	if (fra->argv[0] == '1')
		fracta_Julia(fra);
	else
		fracta_Mandel(fra);
	mlx_put_image_to_window(fra->mlx.mlx_ptr,
		fra->mlx.mlx_win, fra->mlx.img, 0, 0);
	mlx_destroy_image(fra->mlx.mlx_ptr, fra->mlx.img);
	return (0);
}

void	raycast(t_fra *fra)
{
	init_mlx(fra);
	selec_init(fra);
	mlx_hook(fra->mlx.mlx_win, 2, 1L << 0, key_press, fra);
	mlx_hook(fra->mlx.mlx_win, 3, 1L << 1, key_relea, fra);
	mlx_hook(fra->mlx.mlx_win, 17, 1L << 17, ui_cross_exit, fra);
	mlx_loop_hook(fra->mlx.mlx_ptr, raycast_loop, fra);
	mlx_loop(fra->mlx.mlx_ptr);
}

void	chk_args (t_fra *fra, int argc, char **argv)
{
	if (argc <= 1 || argc > 2)
		ft_msgerror("Nuemero de argumentos erróneo.\nLas opciones disponibles son:\n1 --> Julia\n2 --> Mandelbroth", 1);
	if ((ft_strchr(argv[1], '1') != 0) || (ft_strchr(argv[1], '2') !=0))
		fra->argv = argv[1];
	else
		ft_msgerror("Selección errónea.\nLas opciones disponibles son:\n1 --> Julia\n2 --> Mandelbroth", 1);
}

int	main (int argc, char **argv)
{
	t_fra	*fra;

	fra = ft_calloc(sizeof(t_fra), sizeof(t_fra));
	chk_args(fra, argc, argv);
	raycast(fra);
	free_all(fra);
	system("leaks fractol");
	return (0);
}
