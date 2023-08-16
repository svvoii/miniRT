#ifndef CANVAS_H
# define CANVAS_H

# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>

# include "../01_typles_points_vectors/tpv.h"

# define WIDTH	250
# define HEIGHT	150
# define BUFFER_SIZE 2048

enum e_color
{
	RED,
	GREEN,
	BLUE
};

typedef struct s_color
{
	double		red;
	double		green;
	double		blue;
}	t_color;

typedef struct s_canvas
{
	unsigned int	canvas[HEIGHT][WIDTH];
	int				height;
	int				width;
}	t_canvas;

typedef struct s_prj
{
	int	x[BUFFER_SIZE];
	int	y[BUFFER_SIZE];
	int	count;
}	t_prj;

/* HELPER FUNCTIONS */
void	new_color(t_color *c, double r, double g, double b);
void	add_color(t_color *new_color, t_color *c_a, t_color *c_b);
void	substract_color(t_color *new_color, t_color *c_a, t_color *c_b);
void	multiply_color(t_color *new_color, t_color *c_a, t_color *c_b);

/* Libft */
char	*ft_itoa(int n);

void	get_projectile(t_prj *prj);

#endif