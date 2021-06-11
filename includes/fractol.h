/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:20:45 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/11 15:43:06 by juasanto         ###   ########.fr       */
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
/*
** Define Keys
*/
# define KEY_FW 13
# define KEY_BW 1
# define KEY_RR 2
# define KEY_RL 0
# define KEY_SR 14
# define KEY_SL 12
# define KEY_ESC 53
/*
 * Fractal Jullia
*/ 
typedef struct s_jul
{
	double			cRe;
	double			cIm;
	double			newRe;
	double			newIm;
	double			oldRe;
	double			oldIm;
	double			zoom;
	double			moveX;
	double			moveY;
	int				maxIterations;
}					t_jul;



typedef struct s_fra
{
	int				temp;
	int				resX;
	int				resY;
	int				color;
	float			r;
	float			g;
	float			b;
	float			h;
	float			s;
	float			v;
	t_mlx			mlx;
	t_jul			jul;
}					t_fra;

int		ui_cross_exit(t_fra *fra);
int		to_rgb(int r, int g, int b);
void	free_all(t_fra *fra);
void	my_mlx_pixel_put(t_fra *fra, int x, int y, int color);
void	HsvToRgb(t_fra *fra, unsigned char h, unsigned char s, unsigned char v);
int fracta_Julia(t_fra *fra);

#endif
