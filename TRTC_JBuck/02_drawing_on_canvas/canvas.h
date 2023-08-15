#ifndef CANVAS_H
# define CANVAS_H

# include <stdio.h>
# include <stdbool.h>
# include <math.h>

# define WIDTH	20
# define HEIGHT	10

typedef struct s_color
{
	double		red;
	double		green;
	double		blue;
}	t_color;

typedef struct s_canvas
{
	unsigned int	**canvs;
	int				height;
	int				width;
}	t_canvas;

#endif