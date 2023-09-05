/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/05 15:09:35 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

/*
** Here we malloc an instance of t_camera *cam and initialize ist values.
** Varibles passed as arguments from t_scene (resolution_y, resolution_x)
** stored as t_camera (h_size and v_size) respectively.
** Return from tan() is stored in cam->half as fov (field of view) / 2.
** (fov is passed as a parameter and consists of a number from input * (PI / 180))
** 
** Aspect (cam->aspect) is stored as a division of (h_s / v_s) passed as parameters.
** Based on the value of cam->aspect >= 1 
** values of to (half_w and half_h) composed accordingly.
**
** cam->pix_size is composed as (half_w * 2) / h_size
*/
void	init_camera(t_scene *s, double fov)
{
	t_camera	*cam;

	//cam = (t_camera *)malloc(sizeof(t_camera));
	cam = &s->cameras[s->camera_counter];
	cam->h_size = s->resolution_y;
	cam->v_size = s->resolution_x;
	//cam->transform = NULL;
	cam->half = tan(fov / 2);
	cam->aspect = (double)(s->resolution_y / s->resolution_x);
	if (cam->aspect >= 1)
	{
		cam->half_w = cam->half;
		cam->half_h = cam->half / cam->aspect;
	}
	else
	{
		cam->half_w = cam->half * cam->aspect;
		cam->half_h = cam->half;
	}
	cam->pix_size = (cam->half_w * 2) / cam->h_size;
	//return (cam);
}

/*
t_ray	*ray_for_pix(t_camera *c, int y, int x)
{
	double	xwrld;
	double	ywrld;
	t_tuple	*pixel;
	t_tuple	*origin;
	t_tuple	*direction;

	xwrld = c->half_w - ((double)y + 0.5) * c->pix_size;
	ywrld = c->half_h - ((double)x + 0.5) * c->pix_size;
	pixel = tuple_apply_trans_matrix(
			matrix_invert(c->transform), tuple_point(ywrld, xwrld, -1));
	origin = tuple_apply_trans_matrix(
			matrix_invert(c->transform), tuple_point(0, 0, 0));
	direction = tuple_normalize(tuple_substract(pixel, tuple_copy(origin)));
	return (ray_ray(origin, direction));
}

void	render(t_camera *c, t_world *w, t_canvas *img)
{
	t_ray		*r;
	t_tuple		*color;
	int			y;
	int			x;

	init_canvas(c->v_size, c->h_size, img);
	y = -1;
	while (++y < c->h_size)
	{
		x = -1;
		while (++x < c->v_size)
		{
			r = ray_for_pix(c, y, x);
			color = color_at(w, r);
			ray_free(r);
			img->canvas[y][x] = tuple_to_rgb(color);
		}
	}
}
*/