/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:15:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/09 14:07:21 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	free_all(t_fra *fra);
void	my_mlx_pixel_put(t_fra *fra, int x, int y, int color);
void	init_mlx(t_fra *fra);
void	raycast(t_fra *fra);
void	print_frac(t_fra *fra);
int		raycast_loop(t_fra *fra);
int		to_rgb(int r, int g, int b);
int		ui_cross_exit(t_fra *fra);

/*
 * Fractal
*/
#define MAXCOUNT 30

// Function to draw mandelbrot set
void fractal(t_fra *fra, float left, float top, float xside, float yside)
{
    float xscale, yscale, zx, zy, cx, tempx, cy;
	int color = to_rgb(20, 50, 90);
    int x, y; 
    int maxx, maxy, count;

    // getting maximum value of x-axis of screen
    maxx = fra->resX;

    // getting maximum value of y-axis of screen
    maxy = fra->resY;

    // setting up the xscale and yscale
    xscale = xside / maxx;
    yscale = yside / maxy;

    // calling rectangle function
    // where required image will be seen
    //rectangle(0, 0, maxx, maxy);

    // scanning every point in that rectangular area.
    // Each point represents a Complex number (x + yi).
    // Iterate that complex number
    for (y = 1; y <= maxy - 1; y++) {
        for (x = 1; x <= maxx - 1; x++)
        {
            // c_real
            cx = x * xscale + left;

            // c_imaginary
            cy = y * yscale + top;

            // z_real
            zx = 0;

            // z_imaginary
            zy = 0;
            count = 0;

            // Calculate whether c(c_real + c_imaginary) belongs
            // to the Mandelbrot set or not and draw a pixel
            // at coordinates (x, y) accordingly
            // If you reach the Maximum number of iterations
            // and If the distance from the origin is
            // greater than 2 exit the loop
            while ((zx * zx + zy * zy < 4) && (count < MAXCOUNT))
            {
                // Calculate Mandelbrot function
                // z = z*z + c where z is a complex number

                // tempx = z_real*_real - z_imaginary*z_imaginary + c_real
                tempx = zx * zx - zy * zy + cx;

                // 2*z_real*z_imaginary + c_imaginary
                zy = 2 * zx * zy + cy;

                // Updating z_real = tempx
                zx = tempx;

                // Increment count
                count = count + 1;
            }

            // To display the created fractal
            my_mlx_pixel_put(fra, x, y, color + count * 100);
        }
    }
}



/*
 * funciones
*/

int	to_rgb(int r, int g, int b)
{
	return ((b * 1) + (g * 256) + (r * 256 * 256));
}

int	ui_cross_exit(t_fra *fra)
{
	mlx_destroy_window(fra->mlx.mlx_ptr, fra->mlx.mlx_win);
	free_all(fra);
	exit(0);
	return (1);
}

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

int	raycast_loop(t_fra *fra)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	//pl_move(cub);
	color = to_rgb(20, 50, 90);
	fra->mlx.img = mlx_new_image(fra->mlx.mlx_ptr, fra->resX, fra->resY);
	fra->mlx.addr = mlx_get_data_addr(fra->mlx.img, &fra->mlx.bits_per_pixel,
			&fra->mlx.line_length, &fra->mlx.endian);
    float left, top, xside, yside;
    left = -1.75;
    top = -0.25;
    xside = 0.25;
    yside = 0.45;
    fractal(fra, left, top, xside, yside);
//	while (x < fra->resX)
//	{
//		while (y < fra->resY)
//		{
//			my_mlx_pixel_put(fra, x, y, color + x);
//			y++;
//		}
//		y = 0;
//		x++;
//	}
	//sprites_print(cub);
	
	mlx_put_image_to_window(fra->mlx.mlx_ptr, fra->mlx.mlx_win, fra->mlx.img, 0, 0);
	mlx_destroy_image(fra->mlx.mlx_ptr, fra->mlx.img);
	return (0);
}

void	raycast(t_fra *fra)
{
	init_mlx(fra);
	//mlx_hook(fra->mlx.mlx_win, 2, 1L << 0, key_press, fra);
	//mlx_hook(fra->mlx.mlx_win, 3, 1L << 1, key_relea, fra);
	mlx_hook(fra->mlx.mlx_win, 17, 1L << 17, ui_cross_exit, fra);
	mlx_loop_hook(fra->mlx.mlx_ptr, raycast_loop, fra);
	mlx_loop(fra->mlx.mlx_ptr);
}

int		main ()
{
	t_fra	*fra;

	fra = ft_calloc(sizeof(t_fra), 1);
	fra->temp = 0;	
	fra->resX = 800;
	fra->resY = 800;
	
	printf("Hola Majo que quieres de pincho");
	raycast(fra);
	free_all(fra);
	system("leaks fractol");
	return(0);
}
