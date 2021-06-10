/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:15:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/06/10 19:09:14 by juasanto         ###   ########.fr       */
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
float max(double r, double g, double b)
{
	if (r >= g && r >= b)
		return(r);
	else if (g > b)
		return(g);
	else
		return(b);
}

float min(double r, double g, double b)
{
	if (r <= g && r <= b)
		return(r);
	else if (g < b)
		return(g);
	else
		return(b);
}

int rgb_to_hsv(t_fra *fra, float r, float g, float b) 
{
   // R, G, B values are divided by 255
   // to change the range from 0..255 to 0..1:
   r /= 255.0;
   g /= 255.0;
   b /= 255.0;
   float cmax = max(r, g, b); // maximum of r, g, b
   float cmin = min(r, g, b); // minimum of r, g, b
   float diff = cmax-cmin; // diff of cmax and cmin.
   if (cmax == cmin)
      fra->h = 0;
   else if (cmax == r)
      fra->h = fmod((60 * ((g - b) / diff) + 360), 360.0);
   else if (cmax == g)
      fra->h = fmod((60 * ((b - r) / diff) + 120), 360.0);
   else if (cmax == b)
      fra->h = fmod((60 * ((r - g) / diff) + 240), 360.0);
   // if cmax equal zero
      if (cmax == 0)
         fra->s = 0;
      else
         fra->s = (diff / cmax) * 100;
   // compute v
   fra->v = cmax * 100;
   return 0;
}

void hsv_to_rgb(t_fra *fra, float H, float S,float V)
{
    if(H>360 || H<0 || S>100 || S<0 || V>100 || V<0)
        return;
    float s = S/100;
    float v = V/100;
    float C = s*v;
    float X = C*(1-fabs(fmod(H/60.0, 2)-1));
    float m = v-C;
    float r,g,b;
    if(H >= 0 && H < 60){
        r = C,g = X,b = 0;
    }
    else if(H >= 60 && H < 120){
        r = X,g = C,b = 0;
    }
    else if(H >= 120 && H < 180){
        r = 0,g = C,b = X;
    }
    else if(H >= 180 && H < 240){
        r = 0,g = X,b = C;
    }
    else if(H >= 240 && H < 300){
        r = X,g = 0,b = C;
    }
    else{
        r = C,g = 0,b = X;
    }

    fra->r = (r+m)*255;
    fra->g = (g+m)*255;
    fra->b = (b+m)*255;
}

	int fracta_Julia(t_fra *fra)
{

 	double cRe;
 	double cIm;
 	double newRe;
	double newIm;
	double oldRe;
	double oldIm;
	double zoom;
	double moveX;
	double moveY;
	int color;
	int maxIterations;
	int i;

	zoom = 1;
	moveX = 0;
	moveY = 0;
	maxIterations = 300;
	cRe = -0.7;
	cIm = 0.27015;

  //loop through every pixel
  for(int y = 0; y < fra->resY; y++)
  for(int x = 0; x < fra->resX; x++)
  {
    //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
    newRe = 1.5 * (x - fra->resX / 2) / (0.5 * zoom * fra->resX) + moveX;
    newIm = (y - fra->resY/ 2) / (0.5 * zoom * fra->resY) + moveY;
    //i will represent the number of iterations
    //start the iteration process
    for(i = 0; i < maxIterations; i++)
    {
      //remember value of previous iteration
      oldRe = newRe;
      oldIm = newIm;
      //the actual iteration, the real and imaginary part are calculated
      newRe = oldRe * oldRe - oldIm * oldIm + cRe;
      newIm = 2 * oldRe * oldIm + cIm;
      //if the point is outside the circle with radius 2: stop
      if((newRe * newRe + newIm * newIm) > 4) break;
    }
    //use color model conversion to get rainbow palette, make brightness black if maxIterations reached
    //color = HSVtoRGB(RGBtoHSV(i % 256, 255, 255 * (i < maxIterations)));
    //draw the pixeli

	rgb_to_hsv(fra, i % 256, 255, 255 * (i < maxIterations));
	hsv_to_rgb(fra, fra->h, fra->s, fra->v);
	//HSVtoRGB(fra, fra->h, fra->s, fra->v);
	
	color = to_rgb(fra->r, fra->g, fra->b);
	my_mlx_pixel_put(fra, x, y, color);
	}
	return (0);
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
	//int	color;

	x = 0;
	y = 0;
/* 
 * pl_move(cub);
*/
	//color = to_rgb(20, 50, 90);
	fra->mlx.img = mlx_new_image(fra->mlx.mlx_ptr, fra->resX, fra->resY);
	fra->mlx.addr = mlx_get_data_addr(fra->mlx.img, &fra->mlx.bits_per_pixel,
			&fra->mlx.line_length, &fra->mlx.endian);
	fracta_Julia(fra);
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
	fra->resX = 1800;
	fra->resY = 800;
	printf("Hola Majo que quieres de pincho");
	raycast(fra);
	free_all(fra);
	system("leaks fractol");
	return(0);
}
