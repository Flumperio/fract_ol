/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:12:13 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/21 18:53:14 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

void	selec_init(t_fra *fra)
{
	fra->temp = 0;
	if (fra->argv[0] == '1')
		init_val_jul(fra);
	else
		init_val_man(fra);
}
