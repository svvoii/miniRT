/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/08 12:46:25 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

/* DEBUG */
void	print_matrix(t_matrix *m)
{
	int	h = 0;
	int	w = 0;

	/* DEBUG */
	printf("\tm->h: [%d], m->w: [%d]\n", m->h, m->w);
	/* ***** */
	while (h < m->h)
	{
		printf("\t[ ");
		w = 0;
		while (w < m->w)
		{
			printf("%.1f ", m->mtx[h][w]);
			w++;
		}
		printf("]\n");
		h++;
	}
}
/* ***** */

int	min_d(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	mtx_identity(t_matrix *m, int i)
{
	while (--i >= 0)
	{
		m->mtx[i][i] = 1;
	}
}

void	mtx_scale(t_matrix *m, double x, double y, double z)
{
	mtx_identity(m, M_MAX);
	m->mtx[0][0] = x;
	m->mtx[1][1] = y;
	m->mtx[2][2] = z;
}

//void	mtx_translate(t_matrix *m, double x, double y, double z)
void	mtx_translate(t_matrix *m, t_tuple *tpl)
{
	mtx_identity(m, M_MAX);
	m->mtx[0][3] = tpl->x;
	m->mtx[1][3] = tpl->y;
	m->mtx[2][3] = tpl->z;
}
/*
** Consider this input file with only one sphere to render:
** R 400 400
** A 0.6						255,255,255
** c	0,5,-8		0,0,1		0,1,0		70
** l	-10,10,-10	0.8			255,255,255	
** sp	0,5,0		5.0			225,25,25*
**
** So, it takes around 18 seconds to render just one sphere and use 
** DEBUG printfs in the function bellow
** ..around 7 seconds to render same setting but without printf DEBUG statements
**
** call from handle_sphere() receive:	m1[4][4] and m2[4][4] so result is res[4][4]
** call from handle_plane() receive:	m1[4][4] and m2[4][4] so result is res[4][4]
** call from handle_square() receive:	m1[4][4] and m2[4][4] so result is res[4][4]
** call from handle_cylinder() receive:	m1[4][4] and m2[4][4] so result is res[4][4]
** call from handle_triangle() receive:	m1[4][4] and m2[4][4] so result is res[4][4]
** call from handle_cone() receive:		m1[4][4] and m2[4][4] so result is res[4][4]
** call from handle_cube() receive:		m1[4][4] and m2[4][4] so result is res[4][4]
**
** However, this also used in rendering logic to produce each pixel of the canvs,
** call from tuple_apply_trans_matrix() receive: m1[4][4] and m2[4][1] 
** so the result is res[4][1]
**
*/
void	mtx_multiply(t_matrix *res, t_matrix *m1, t_matrix *m2)
{
	int			h;
	int			w;
	int			i;
	double		tmp;

	res->h = min_d(m1->h, m2->h);
	res->w = min_d(m1->w, m2->w);
	/* DEBUG */
	printf("Multiply Matrix\n");
	printf(" m1->h: [%d],  m1->w: [%d]\n", m1->h, m1->w);
	printf(" m2->h: [%d],  m2->w: [%d]\n", m2->h, m2->w);
	printf("res->h: [%d], res->w: [%d]\n", res->h, res->w);
	printf("mtx m1:\n");
	print_matrix(m1);	
	printf("mtx m2:\n");
	print_matrix(m2);	
	/* ***** */
	h = 0;
	while (h < res->h)
	{
		w = 0;
		while (w < res->w)
		{
			i = 0;
			tmp = 0.0;
			//while (i < m1->w && i < m2->h)
			while (i < M_MAX)
			{
				tmp += m1->mtx[h][i] * m2->mtx[i][w];
				//res->matrix[h][w] += m1->matrix[h][i] * m2->matrix[i][w];
				/* DEBUG */
				//printf("\ttmp:[%.1f]\tm1[%d][%d]: [%.1f], m2[%d][%d]: [%.1f]\n", tmp, h, i, m1->matrix[h][i], i, w, m1->matrix[i][w]);
				/* ***** */
				i++;
			}
			res->mtx[h][w] = tmp; 
			w++;
		}
		h++;
	}
	/* DEBUG */
	printf("mtx res:\n");
	print_matrix(res);	
	/* ***** */
}

/*
** Creates an instance of t_matrix with matrix_identity() of size 3*3, 
** assigns values to it from given tuples as parameters.
** Frees all 3 tuples passed to it.  
t_matrix	*vt_combine_matrix(t_tuple *left,
*/
void	mtx_combine(t_matrix *res, t_tuple *left,
	t_tuple *true_up, t_tuple *forward)
{
	//t_matrix	*res;

	//res = matrix_identity(4);
	res->mtx[0][0] = left->x;
	res->mtx[0][1] = left->y;
	res->mtx[0][2] = left->z;
	res->mtx[1][0] = true_up->x;
	res->mtx[1][1] = true_up->y;
	res->mtx[1][2] = true_up->z;
	res->mtx[2][0] = -1 * forward->x;
	res->mtx[2][1] = -1 * forward->y;
	res->mtx[2][2] = -1 * forward->z;
	//res->h = M_MAX;
	//res->w = M_MAX;
}

/*
** Here we receive a combination of t_tuples:
** (*from is a tuple_copy() from t_camera instance)
** (*to is composed of a tuple_copy() of *from and *dir(vecotr) from input file)
** (*up is a vector with the data from input)
** Thee more t_tuple (*forward, *left, *tmp)
** and two t_matrix instances are created (*res, *view_matrix) 
** to perform necessary calculations into t_matrix (*view_result) to return.
**
** Starting with substracting tuples (to - from) which is stored in tuple *tmp.
** Then this normalized *tmp is stored in tuple *forward. 
** In the next line we reuse *tmp to store normalized *up tupple to use it
** in tuple_cross_product(forward, tmp) along with *forward.
** The result is stored in *left tuple.
** Then we free *tmp tuple and negate tuple *from. 
**
** In the next step we store is t_matrix *res the return from vt_combine_matrix()
** with arguments of tuples (*left, cross_product(left, forward) and forward)
**		(..the cross_product logic see in tuple_cross_product)
** Last calculstions stored in *transform and performed in matrix_multiply()
** with t_matrix *res and return of matrix_translate(from->x, ..y, ..z) as arguments. 
*/
void	view_transform(t_camera *cam, t_tuple *to, t_tuple *up)
{
	t_tuple		forward;
	t_tuple		left;
	t_tuple		tmp;
	t_matrix	combine;
	t_matrix	translate;

	/* initializing temporaary matrices */
	init_matrix(&combine);
	init_matrix(&translate);

	substract_tuple(&tmp, to, &cam->from);	
	normalize_tuple(&forward, &tmp);	
	normalize_tuple(&tmp, up);	
	cross_product_tuple(&left, &forward, &tmp);
	negate_tuple(&cam->from);
	cross_product_tuple(&tmp, &left, &forward);
	mtx_combine(&combine, &left, &tmp, &forward);
	mtx_translate(&translate, &cam->from);
	mtx_multiply(&cam->transform, &combine, &translate);
	/* DEBUG 
	//tmp = tuple_substract(to, tuple_copy(from));
	//forward = tuple_normalize(tmp);
	//tmp = tuple_normalize(up);
	//left = tuple_cross_product(forward, tmp);
	//tuple_free(tmp);
	//from = tuple_negate(from);
	//combine = vt_combine_matrix(left, tuple_cross_product(left, forward), forward);
	//view_matrix = matrix_multiply(combine, matrix_translate(from->x, from->y, from->z));
	tuple_free(from);
	return (view_matrix);
	*/
}

/*
** This converts the tuple int matrix[4][1] like this:
** [ x ]
** [ y ]
** [ z ]
** [ e_type ]
**
*/
void	tuple_to_matrix(t_matrix *m, t_tuple *t)
{
	//t_matrix	*m;

	//m = matrix_matrix(4, 1);
	m->mtx[0][0] = t->x;
	m->mtx[1][0] = t->y;
	m->mtx[2][0] = t->z;
	m->mtx[3][0] = (double)t->type;
	m->h = 4;
	m->w = 1;
}
