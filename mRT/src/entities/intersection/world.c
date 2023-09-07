/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/07 17:06:13 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	init_world(t_world *w, t_shape *shapes, t_light *lights, int l_count)
{
	w->shapes = shapes;
	w->lights = lights;
	w->lights_counter = l_count;
	//w->ambienace = NULL;
}

void	world_set_ambience(t_light *w_amb, t_tuple *from, t_tuple *ambi_color)
{
	copy_tuple(&w_amb->position, from);
	copy_tuple(&w_amb->color, ambi_color);
}

/*
void	init_world(t_world *w, t_shape **shapes, t_light **lights,
			int lights_counter)
{
	w->shapes = shapes;
	w->lights = lights;
	w->lights_counter = lights_counter;
	w->ambienace = NULL;
}
void	world_set_ambience(t_world *w, t_tuple *from, t_tuple *color)
{
	if (w->ambienace)
		light_free(w->ambienace);
	w->ambienace = light_make(tuple_point(from->x, from->y, from->z),
			tuple_color(color->x, color->y, color->z));
}
*/