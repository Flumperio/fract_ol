/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymgr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:57:19 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/11 15:43:14 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ui_cross_exit(t_fra *fra)
{
	mlx_destroy_window(fra->mlx.mlx_ptr, fra->mlx.mlx_win);
	free_all(fra);
	exit(0);
	return (1);
}

int	key_press(int keycode, t_fra *fra)
{
	printf("keykode: %i\n", keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(fra->mlx.mlx_ptr, fra->mlx.mlx_win);
		free_all(fra);
		system("leaks cub3D");
		exit(0);
		return (1);
	}
	return (0);
}
