#include "canvas.h"

/*
** Here we compose a new color from t_color as double value
** using bitwise operators to clear and write proper separate color
*/
unsigned int	double_color_to_int(double raw_color)
{
	if (raw_color > 255.0)	
		return (255);
	return ((unsigned int)raw_color);
}

void	set_red(unsigned int *rgb, unsigned int red)
{
	*rgb &= *rgb & 0x00ffff;
	*rgb |= red << 16;
}

void	set_green(unsigned int *rgb, unsigned int green)
{
	*rgb &= *rgb & 0xff00ff;
	*rgb |= green << 8;
}

void	set_blue(unsigned int *rgb, unsigned int blue)
{
	*rgb &= *rgb & 0xffff00;
	*rgb |= blue;
}

unsigned int	make_rgb(unsigned int red, unsigned int green, unsigned int blue)
{
	unsigned int	new_rgb;

	new_rgb = 0;
	new_rgb &= new_rgb & 0xffffffff;
	set_red(&new_rgb, red);
	set_green(&new_rgb, green);
	set_blue(&new_rgb, blue);
	return (new_rgb);	
}

unsigned int double_to_rgb(t_color *color)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	new_rgb_color;

	r = double_color_to_int(color->red * 255.0);
	g = double_color_to_int(color->green * 255.0);
	b = double_color_to_int(color->blue * 255.0);
	new_rgb_color = make_rgb(r, g, b);
	return (new_rgb_color);
}
/* ***** */

/* Test function which fills in the canvas with black */
void	new_cavas(unsigned int canvas[HEIGHT][WIDTH])
{
	t_color	black;
	int		w = 0;
	int		h = 0;

	new_color(&black, 0.0, 0.0, 0.0);
	while (h < HEIGHT)
	{
		w = 0;
		while (w < WIDTH)
		{
			canvas[h][w] = double_to_rgb(&black);
			w++;
		}
		h++;
	}
}

int	main()
{
	t_canvas		c;
	unsigned int	canvas[HEIGHT][WIDTH];
	int				h;
	int				w;

	new_cavas(canvas);
	h = 0;
	while (h < HEIGHT)
	{
		w = 0;
		while (w < WIDTH)
		{
			printf("%d ", canvas[h][w]);
			w++;
		}
		printf("\n");
		h++;
	}
	
	return (0);
}
