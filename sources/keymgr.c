/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymgr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:57:19 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/21 19:08:07 by juasanto         ###   ########.fr       */
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
		system("leaks fractol");
		exit(0);
		return (1);
	}
	if (keycode == KEY_RS)
		selec_init(fra);
	if (keycode == KEY_FW)
		fra->bol.key_fw = 1;
	if (keycode == KEY_BW)
		fra->bol.key_bw = 1;
	if (keycode == KEY_CL)
		fra->bol.key_cl = 1;
	if (keycode == KEY_SL)
		fra->bol.key_sl = 1;
	if (keycode == KEY_SR)
		fra->bol.key_sr = 1;
	return (0);
}

int	key_relea(int keycode, t_fra *fra)
{
	if (keycode == KEY_FW)
		fra->bol.key_fw = 0;
	if (keycode == KEY_BW)
		fra->bol.key_bw = 0;
	if (keycode == KEY_CL)
		fra->bol.key_cl = 0;
	if (keycode == KEY_SL)
		fra->bol.key_sl = 0;
	if (keycode == KEY_SR)
		fra->bol.key_sr = 0;
	return (0);
}

void	pl_move(t_fra *fra)
{
	double	move_const;

	move_const = 0.0003 * 30;
	if (fra->bol.key_fw == 1)
		fra->jul.moveY += (move_const / fra->jul.zoom);
	if (fra->bol.key_bw == 1)
		fra->jul.moveY -= (move_const / fra->jul.zoom);
	if (fra->bol.key_sl == 1)
		fra->jul.moveX += (move_const / fra->jul.zoom);
	if (fra->bol.key_sr == 1)
		fra->jul.moveX -= (move_const / fra->jul.zoom);
	if (fra->bol.key_cl == 1)
		fra->temp += 5;

}
