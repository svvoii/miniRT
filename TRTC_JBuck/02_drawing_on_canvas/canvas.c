#include "canvas.h"

/* HELPER FUNCTIONS */
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

/*
** Here we compose a new color from t_color as double value
** using bitwise operators to clear and write proper separate color
** Instead of (unsigned int) use (unsigned char) to cary the data on each individual color
** this helps to optimize some memory..
*/
unsigned char	double_color_to_int(double raw_color)
{
	if (raw_color > 255.0)	
		return (255);
	return (raw_color);
}

void	set_color(unsigned int *rgb, unsigned char color, enum e_color c, int displace)
{
	if (c == RED)
		*rgb &= *rgb & 0x00ffff;
	if (c == GREEN)
		*rgb &= *rgb & 0xff00ff;
	if (c == BLUE)
		*rgb &= *rgb & 0xffff00;
	*rgb |= (unsigned int)color << displace;
}

unsigned int	make_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	unsigned int	new_rgb;

	new_rgb = 0;
	//new_rgb &= new_rgb & 0xffffffff;
	set_color(&new_rgb, red, RED, 16);
	set_color(&new_rgb, green, GREEN, 8);
	set_color(&new_rgb, blue, BLUE, 0);
	return (new_rgb);	
}

unsigned int double_to_rgb(t_color *color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned int	new_rgb_color;

	r = double_color_to_int(color->red * 255.0);
	g = double_color_to_int(color->green * 255.0);
	b = double_color_to_int(color->blue * 255.0);
	new_rgb_color = make_rgb(r, g, b);
	return (new_rgb_color);
}
/* ***** */

void	new_cavas(unsigned int canvas[HEIGHT][WIDTH])
{
	t_color	black;
	t_color	white;
	t_color	red;
	t_color	green;
	t_color	blue;
	int		w = 0;
	int		h = 0;

	new_color(&black, 0, 0, 0);
	new_color(&white, 255, 255, 255);
	new_color(&red, 255, 0, 0);
	new_color(&green, 0, 255, 0);
	new_color(&blue, 0, 0, 255);
	while (h < HEIGHT)
	{
		w = 0;
		while (w < WIDTH)
		{
			canvas[h][w] = double_to_rgb(&black);
			/*
			canvas[h][w] = double_to_rgb(&white);
			canvas[h][w] = double_to_rgb(&red);
			canvas[h][w] = double_to_rgb(&green);
			canvas[h][w] = double_to_rgb(&blue);
			*/
			w++;
		}
		h++;
	}
}

char	*cavas_to_ppm(int width, int height)
{
	char	ppm_str[BUFFER_SIZE];
	char	*wd;
	char	*hg;
	int		i;

	while (i < BUFFER_SIZE)
		ppm_str[i] = '\0';
	wd = ft_itoa(width);
	hg = ft_itoa(height);
	strcat(ppm_str, "P3\n");
	strcat(ppm_str, wd);
	strcat(ppm_str, " ");
	strcat(ppm_str, hg);
	strcat(ppm_str, "\n");
	free(wd);
	free(hg);
	i = 0;

}

void	set_projectile_on_canvas(t_canvas *c, t_prj *projectile)
{
	t_color		red;
	int			x;
	int			y;
	int			i;

	new_color(&red, 255, 0, 0);
	i = 0;
	while (i < projectile->count)
	{
		x = projectile->x[i];
		y = projectile->y[i];
		c->canvas[y][x] = double_to_rgb(&red);
		printf("[%d]\tx:[%d], y:[%d]\n", i, x, y);
		i++;
	}
}

/* This will fill in the structure t_prj with points of the projectile to plot on the canvas */
void	get_projectile(t_prj *prj)
{
	t_projectile	projectile;
	t_tuple			tmp_vector; 
	/*
	tmp_vector is uset to compute gravity and wind and plug it in new_projectile
	as velosity tuple with calculated magnitude
	*/
	t_environment	env;
	int		i;

	new_point(&projectile.position, 0, 1, 0);
	new_vector(&tmp_vector, 1, 1, 0);
	normalize(&projectile.velocity, &tmp_vector, magnitude(&tmp_vector));

	new_vector(&env.grvity, 0, -0.1, 0);
	new_vector(&env.wind, -0.01, 0, 0);
	i = 0;
	while (projectile.position.y >= 0)
	{
		tick(&projectile, &env, &projectile);
		prj->x[i] = (int)(projectile.position.x * 10.0);
		prj->y[i] = (int)(projectile.position.y * 10.0);
		i++;
	}
	prj->count = i;
}

int	main()
{
	t_canvas	c;
	t_prj		projectile;
	//unsigned int	canvas[HEIGHT][WIDTH];
	int			h;
	int			w;

	new_cavas(c.canvas);
	get_projectile(&projectile);
	set_projectile_on_canvas(&c, &projectile);
	h = 0;
	while (h < HEIGHT)
	{
		w = 0;
		while (w < WIDTH)
		{
			printf("%d ", c.canvas[h][w]);
			w++;
		}
		printf("\n");
		h++;
	}
	
	return (0);
}
