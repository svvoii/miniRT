/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/05 18:56:44 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	mtx_identity(t_matrix *m, int i)
{
	while (--i >= 0)
	{
		m->matrix[i][i] = 1;
	}
}

void	mtx_scale(t_matrix *m, double x, double y, double z)
{
	mtx_identity(m, M_MAX);
	m->matrix[0][0] = x;
	m->matrix[1][1] = y;
	m->matrix[2][2] = z;
}

//void	mtx_translate(t_matrix *m, double x, double y, double z)
void	mtx_translate(t_matrix *m, t_tuple *tpl)
{
	mtx_identity(m, M_MAX);
	m->matrix[0][3] = tpl->x;
	m->matrix[1][3] = tpl->y;
	m->matrix[2][3] = tpl->z;
}

void	mtx_multiply(t_matrix *res, t_matrix *m1, t_matrix *m2)
{
	int			h;
	int			w;
	int			i;

	printf("Multiply Matrix:\n");
	//res->h = min(m1->h, m2->h);
	//res->w = min(m1->w, m2->w);
	res->h = M_MAX;
	res->w = M_MAX;
	h = 0;
	while (h < res->h)
	{
		w = 0;
		while (w < res->w)
		{
			i = 0;
			//while (i < m1->w && i < m2->h)
			while (i < M_MAX)
			{
				/* DEBUG */
				printf("\tm1->h [%d], m1->w:[%d], m2->h:[%d], m2->w:[%d]\n", m1->h, m1->w, m2->h, m2->w);
				/* ***** */
				res->matrix[h][w] += m1->matrix[h][i] * m2->matrix[i][w];
				i++;
			}
			w++;
		}
		h++;
	}
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
	res->matrix[0][0] = left->x;
	res->matrix[0][1] = left->y;
	res->matrix[0][2] = left->z;
	res->matrix[1][0] = true_up->x;
	res->matrix[1][1] = true_up->y;
	res->matrix[1][2] = true_up->z;
	res->matrix[2][0] = -1 * forward->x;
	res->matrix[2][1] = -1 * forward->y;
	res->matrix[2][2] = -1 * forward->z;
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
	t_matrix	res;
	t_matrix	mtx;

	substract_tuple(&tmp, to, &cam->from);	
	normalize_tuple(&forward, &tmp);	
	normalize_tuple(&tmp, up);	
	cross_product_tuple(&left, &forward, &tmp);
	negate_tuple(&cam->from);
	cross_product_tuple(&tmp, &left, &forward);
	mtx_combine(&res, &left, &tmp, &forward);
	mtx_translate(&mtx, &cam->from);
	mtx_multiply(&cam->transform, &res, &mtx);
	/* DEBUG 
	//tmp = tuple_substract(to, tuple_copy(from));
	//forward = tuple_normalize(tmp);
	//tmp = tuple_normalize(up);
	//left = tuple_cross_product(forward, tmp);
	//tuple_free(tmp);
	//from = tuple_negate(from);
	//res = vt_combine_matrix(left, tuple_cross_product(left, forward), forward);
	//view_matrix = matrix_multiply(res, matrix_translate(from->x, from->y, from->z));
	tuple_free(from);
	return (view_matrix);
	*/
}
