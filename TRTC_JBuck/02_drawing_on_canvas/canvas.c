#include "canvas.h"

void	new_color(t_color *c, double r, double g, double b)
{
	c->red = r;
	c->green = g;
	c->blue = b;
}

void	add_color(t_color *new_color, t_color *c_a, t_color *c_b)
{
	new_color->red = c_a->red + c_b->red;
	new_color->green = c_a->green + c_b->green;
	new_color->blue = c_a->blue + c_b->blue;
}

void	substract_color(t_color *new_color, t_color *c_a, t_color *c_b)
{
	new_color->red = c_a->red - c_b->red;
	new_color->green = c_a->green - c_b->green;
	new_color->blue = c_a->blue - c_b->blue;
}

void	multiply_color(t_color *new_color, t_color *c_a, t_color *c_b)
{
	new_color->red = c_a->red * c_b->red;
	new_color->green = c_a->green * c_b->green;
	new_color->blue = c_a->blue * c_b->blue;
}

unsigned char	raw_color(double raw_color)
{
	if (raw_color > 255)	
		return (255);
	return (raw_color);
}

unsigned int double_to_rgb(unsigned int *pixel, t_color *color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = raw_color(color->red * 255);
	g = raw_color(color->green * 255);
	b = raw_color(color->blue * 255);
	return (make_rgb(r, g, b));
}

void	new_cavas(unsigned int canvas[HEIGHT][WIDTH])
{
	t_color	black;
	int		w = 0;
	int		h = 0;

	new_color(&black, 0, 0, 0);
	while (h < HEIGHT)
	{
		w = 0;
		while (w < WIDTH)
		{
			double_to_rgb(&canvas[h][w], &black);
			//new_color(&canvas[h][w], 0, 0, 0);
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

	h = 0;
	while (h < HEIGHT)
	{
		w = 0;
		while (w < WIDTH)
		{
			w++;
		}
		h++;
	}
	
	return (0);
}
