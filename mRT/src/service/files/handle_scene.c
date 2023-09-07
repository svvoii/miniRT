/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/07 14:19:14 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	cleanup(char **values)
{
	int	i;

	i = 0;
	while (values[i])
	{
		free(values[i]);
		i++;
	}
	free(values);
}

/*
** This f() simply handles the resolution from the input file
** and saves it in t_scene respective variables
*/
void	handle_r(char **input, t_scene *s)
{
	int		i;

	i = -1;
	if (s->resolution_x < 0)
	{
		s->resolution_x = ft_atoi(input[1]);
		s->resolution_y = ft_atoi(input[2]);
	}
	else
	{
		while (input[++i])
			free(input[i]);
		free(input);
	}
	cleanup(input);
}
/*
** a line from the input file might look like this:
** line:	"A			0.5		255,255,255"
** values: 	[0]	 		[1]			[2]
** description:		light ratio		RGB
*/
void	handle_a(char **input, t_scene *s)
{
	//t_tuple	*color;

	s->ambi_ratio = ft_atod(input[1]);
	set_tuple(&s->ambi_color, input[2], COLOR);
	scale_tuple(&s->ambi_color, s->ambi_ratio * COLOR_CF);
	//color = get_tuple(input[2], 'c');
	//free(s->ambi_color);
	//s->ambi_color = tuple_scalar_multiply(color, s->ambi_ratio * COLOR_CF);
	cleanup(input);
}

/*
** a line from the input file might look like this:
** line:	"c		0,5,-8		0,0,1			0,1,0		70"
** values: 	[0]		[1]			[2]				[3]			[4]
** description:		view point	norm.vector		cam top		FOV
*/
void	handle_c(char **input, t_scene *s)
{
	t_tuple		dir;
	t_tuple		up;
	t_tuple		to;
	t_camera	*cam;

	/* DEBUG */
	printf("CAMERA\n");
	/* ***** */
	if (input && ft_strequals(input[0], "c"))
	{
		cam = &s->cameras[s->camera_counter];
		//cam = make_camera(s->resolution_y, s->resolution_x,
		//		ft_atoi(input[4]) * (M_PI / 180));
		init_camera(s, ft_atoi(input[4]) * (M_PI / 180));
		set_tuple(&cam->from, input[1], POINT);
		set_tuple(&dir, input[2], VECTOR);
		set_tuple(&up, input[3], VECTOR);
		add_tuples(&to, &cam->from, &dir);	
		view_transform(cam, &to, &up);
		s->camera_counter++;
		/* DEBUG 
		//cam->from = get_tuple(input[1], 'p');
		//dir = get_tuple(input[2], 'v');
		//up = get_tuple(input[3], 'v');
		cam->transform = view_transform(
				tuple_copy(cam->from),
				tuple_add(tuple_copy(cam->from), dir),
				up);
		s->cameras[s->camera_counter] = cam;
		*/
	}
	cleanup(input);
}

/*
** a line from the input file might look like this:
** line:	"l	-10,10,-10		0.8			255,255,255"
** values: 	[0]		[1]			[2]				[3]
** description:	light point		bright ratio	RGB	
*/
void	handle_l(char **input, t_scene *s)
{
	t_tuple	*from;
	t_tuple	*color;
	double	brightness;

	if (input && ft_strequals(input[0], "l"))
	{
		from = &s->lights[s->light_counter].position;
		color = &s->lights[s->light_counter].color;
		brightness = ft_atod(input[2]);
		set_tuple(from, input[1], POINT);
		set_tuple(color, input[3], COLOR);
		scale_tuple(color, brightness * COLOR_CF);
		//from = get_tuple(input[1], 'p');
		//color = tuple_scalar_multiply(get_tuple(input[3], 'c'), brightness * COLOR_CF);
		//s->lights[s->light_counter] = light_make(from, color);
		s->light_counter++;
	}
	cleanup(input);
}

/*
** Checks the first string passed as a parameter in char **input and
** calls respective function to process the input data.
** char **input is a result of the ft_split() by whitespace 
** of each *line from GNL get from input file
*/
void	handle_line(char **input, t_scene *s, t_allshapes *allshapes)
{
	if (ft_strequals(input[0], "R"))
		handle_r(input, s);
	else if (ft_strequals(input[0], "A"))
		handle_a(input, s);
	else if (ft_strequals(input[0], "c"))
		handle_c(input, s);
	else if (ft_strequals(input[0], "l"))
		handle_l(input, s);
	else if (ft_strequals(input[0], "sp"))
		handle_sphere(input, s, allshapes);
	/*
	else if (ft_strequals(input[0], "pl"))
		handle_plane(input, s);
	else if (ft_strequals(input[0], "sq"))
		handle_square(input, s);
	else if (ft_strequals(input[0], "cy"))
		handle_cylinder(input, s);
	else if (ft_strequals(input[0], "tr"))
		handle_triangle(input, s);
	else if (ft_strequals(input[0], "co"))
		handle_cone(input, s);
	else if (ft_strequals(input[0], "cu"))
		handle_cube(input, s);
	*/
}

void	parse_scene(int fd, t_scene *s, t_allshapes *allshapes)
{
	char	line[GNL_BUF_SIZE];
	char	*l;

	//while (get_next_line(fd, &line))
	while ((l = get_next_line(fd, line)) != NULL)
	{
		/* DEBUG */
		//if (line[0] != '\0')
		printf("line:[%s], l @ [%p]\n", line, l);
			//printf("line: %s\n", line);
		/* ***** */
		//if (line && !ft_strequals(line, ""))

		if (l && !ft_strequals(line, ""))
		{
			//printf("OK 1\n");
			handle_line(ft_whitespaces(line), s, allshapes);
			//printf("OK 2\n");
		}
		//free(line);
	}
	//if (line && !ft_strequals(line, ""))
	
	//printf("\tl: [%p], line:[%s]\n", l, line);
	
	if (l && !ft_strequals(line, ""))
		handle_line(ft_whitespaces(line), s, allshapes);
	//free(line);
	//free(counters);
	close(fd);
}