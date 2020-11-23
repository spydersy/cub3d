/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:49:10 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/22 18:13:08 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda_algorithm.h"
#include <math.h>

// int			main()
// {

	// return (0);
// }

int main()  
{
	void		*mlx_ptr;
	void		*mlx_win;

	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			i;

	float		x;
	float		y;
	float		dx;
	float		dy;
	float		steps;

	x0 = 120;
	y0 = 33;
	x1 = 2;
	y1 = 60;

    dx = (float)(x1 - x0);  
    dy = (float)(y1 - y0);

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 800, 800, "DDA ALGORITHM");

    if(dx >= dy)
	{
		steps = dx;
	}  
    else  
	{
		steps = dy;
    }
    dx = dx / steps;  
    dy = dy / steps;  
	if (dx  == 1 && x0 >= x1 && y0 >= y1)
	{
		x = x1;
		y = y1;
	}
	else
	{
		x = x0;
		y = y0;
	}
	if (dy == 1 && y0 >= y1 && y0 >= y1)
	{
		y = y1;
		x = x1;
	}
	else
	{
		y = y0;
		x = x0;
	}
    // x = x0;
    // y = y0;
	\\\\\\\\\\\\\

	
    i = 1;  
    while(i<= steps)  
    {  
		mlx_pixel_put(mlx_ptr, mlx_win, x, y, 0xff0000);
        x += dx;  
        y += dy;  
        i=i+1;  
    }  
	mlx_loop(mlx_ptr);
}