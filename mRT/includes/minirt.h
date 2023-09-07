/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:11:07 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/07 17:08:50 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define DOUBLE_PREC 0.0001
# define INSTRUCTION_SET_SIZE 11
# define RES 0
# define AMB 1
# define CAM 2
# define LHT 3
# define SPH 4
# define PLA 5
# define SQU 6
# define CUB 7
# define TRI 8
# define CON 9
# define CYL 10

# define TRUE 1
# define FALSE 0

# include <math.h>
# include <pthread.h>
# include <errno.h>
# include <error.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
//# include <mlx.h>
# include <unistd.h>
# include <stdbool.h>

# include "../lib/libft/libft.h"

/* TUPLE */
typedef enum
{
	VECTOR,
	POINT,
	COLOR
}	e_tuple;

typedef struct tuple
{
	double	x;
	double	y;
	double	z;
	e_tuple	type;
}	t_tuple;

/* ***** */
/* MATRIX */
# define M_MAX 4

typedef struct matrix
{
	double	matrix[M_MAX][M_MAX];
	int		h;
	int		w;
}	t_matrix;

/* ***** */
/* LIGHT */
typedef struct light
{
	t_tuple	position;
	t_tuple	color;
}	t_light;

/* ***** */
/* CAMERA */
typedef struct camera
{
	bool		active;
	t_tuple		from;
	int			h_size;
	int			v_size;
	double		pix_size;
	t_matrix	transform;
	double		half;
	double		half_w;
	double		half_h;
	double		aspect;

}	t_camera;

/* ***** */
/* MATERIAL */
typedef struct matrl
{
	t_tuple	color;
	double	diffuse;
	double	ambient;
	double	specular;
	double	shininess;
}	t_matrl;

/* ***** */
/* SHAPES */
typedef enum
{
	NONE,
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE,
	CONE,
	CUBE
}	e_type;

/*
** Using enum e_type to define the shape type
** void *shape will hold a pointer to a particular 
** shape structure given in e_type and will be 
** initialized to NULL if type is NONE.
*/
typedef struct shape
{
	e_type		type;
	t_matrl		matrl;
	t_matrix	trans;
	void		*shape;
}	t_shape;

typedef struct sphere
{
	bool	active;
	t_tuple	centre;
}	t_sphere;


/* ***** */
/* SCENE */
# define COLOR_CF 0.003921569 //WHY?
//# define SHAPES			1
//# define ALL			2
# define MAX_CAM		4
# define MAX_LIGHT		8
# define MAX_SHAPES		70

# define MAX_SPHERE		10
# define MAX_PLANE		10
# define MAX_SQUARE		10
# define MAX_CYLINDER	10
# define MAX_TRIANGLE	10
# define MAX_CONE		10
# define MAX_CUBE		10

/*
** Setting up fixed max ammount for each shape
** presumably it will allow to run the traycer faster.
** 
** To check the t_plane..
** it seem to be an empty struct
*/
typedef struct s_all_shapes
{
	t_sphere	sphere[MAX_SPHERE];
	/*
	t_plane		plane[MAX_PLANE];
	t_square	square[MAX_SQUARE];
	t_cylinder	cylinder[MAX_CYLINDER];
	t_triangle	triangle[MAX_TRIANGLE];
	t_cone		cone[MAX_CONE];
	t_cube		cube[MAX_CUBE];
	*/
}	t_allshapes;

typedef struct scene
{
	int			resolution_x;
	int			resolution_y;
	double		ambi_ratio;
	t_tuple		ambi_color;
	int			camera_counter;
	t_camera	cameras[MAX_CAM];
	int			light_counter;
	t_light		lights[MAX_LIGHT];
	int			shape_counter;
	t_shape		shapes[MAX_SHAPES];
}	t_scene;

/* ***** */

# include "../src/service/errs/err.h"
# include "../src/service/files/scene.h"
# include "../src/entities/tuple/tuple.h"
# include "../src/entities/camera/camera.h"
# include "../src/entities/matrix/matrix.h"
# include "../src/entities/shapes/sphere/sphere.h"

# include "../src/entities/bmp/bmp.h"
# include "../src/entities/intersection/intersection.h"
# include "../src/service/window/window.h"
# include "../src/entities/light/light.h"
# include "../src/entities/ray/ray.h"

/* */
/*
# include "../src/entities/ray/ray.h"
# include "../src/entities/light/light.h"
# include "../src/entities/color/colors.h"
# include "../src/entities/material/material.h"
# include "../src/entities/shapes/shape.h"
# include "../src/entities/shapes/cone/cone.h"
# include "../src/entities/shapes/cube/cube.h"
# include "../src/entities/shapes/cylinder/cylinder.h"
# include "../src/entities/shapes/plane/plane.h"
# include "../src/entities/shapes/triangle/triangle.h"
# include "../src/entities/shapes/square/square.h"


int		min(int a, int b);
int		max(int a, int b);
double	dmax(double a, double b);
double	dmin(double a, double b);
double	mins(double *a, int length);
double	maxs(double *a, int length);
void	swap(double *x, double *y);
*/

#endif