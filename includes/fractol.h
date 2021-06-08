/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:20:45 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/06 13:49:57 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** Libraries
*/
# include <time.h>
# include <math.h>
# include "../Libft/includes/libft.h"
# include "../minilibx/mlx.h"
/*
** MLX
*/
typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_mlx;	

typedef struct s_fra
{
	int				temp;
	int				resX;
	int				resY;
	t_mlx			mlx;
}					t_fra;

#endif
