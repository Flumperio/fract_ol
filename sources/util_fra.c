/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_fra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:06:23 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/30 10:06:39 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	to_rgb(int r, int g, int b)
{
	return ((b * 1) + (g * 256) + (r * 256 * 256));
}

void	ft_free_struct(t_fra *fra)
{
	if (!fra)
		return ;
	free(fra);
	fra = NULL;
}

void	my_mlx_pixel_put(t_fra *fra, int x, int y, int color)
{
	char	*dst;

	dst = fra->mlx.addr + (y * fra->mlx.line_length
			+ x * (fra->mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
