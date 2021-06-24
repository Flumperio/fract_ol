/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:15:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/24 09:20:35 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_mlx(t_fra *fra);
void	raycast(t_fra *fra);
void	print_frac(t_fra *fra);
int		raycast_loop(t_fra *fra);

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
	else if (fra->argv[0] == '2')
		fracta_Mandel(fra);
	else
		fracta_Newton(fra);
	mlx_put_image_to_window(fra->mlx.mlx_ptr,
		fra->mlx.mlx_win, fra->mlx.img, 0, 0);
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
	if (argc <= 1 || argc > 2)
		ft_msgerror("Número de argumentos erróneo.\n\
Las opciones disponibles son:\n\
1 --> Julia\n2 --> Mandelbroth\n3 --> Newton", 1);
	printf("argv_0: %s\nargv_1: %s\n", argv[0], argv[1]);
	if ((argv[1][0] == '1') || (argv[1][0] == '2' || argv[1][0] == '3'))
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
	free_all(fra);
	system("leaks fractol");
	return (0);
}
