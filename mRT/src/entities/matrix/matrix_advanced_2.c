/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_advanced_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/13 19:09:16 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

/* DEBUG */
/*
** ..to check the calculations in this function
*/
void	invert(t_matrix *cofactors, double determinant, t_matrix *m, t_matrix *inverted)
{
	int			i;
	int			j;
	//t_matrix	*cofactors;
	double		diag;
	t_matrix	sub;

	i = -1;
	//cofactors = matrix_matrix(m->h, m->w);
	matrix_matrix(cofactors, m->h, m->w);
	while (++i < m->h)
	{
		j = -1;
		while (++j < m->w)
			cofactors->mtx[i][j] = matrix_cofactor(&sub, m, i, j);
			//cofactors->mtx[i][j] = matrix_cofactor(m, i, j);
	}
	//inverted = matrix_transpose(cofactors);
	matrix_transpose(inverted, cofactors);
	i = -1;
	while (++i < m->h)
	{
		j = -1;
		while (++j < m->w)
		{
			diag = inverted->mtx[i][j] / determinant;
			inverted->mtx[i][j] = diag;
		}
	}
	//return (inverted);
}

void	mtx_invert(t_matrix *inverted, t_matrix *m)
{
	double		determinant;
	//t_matrix	*inverted;

	//inverted = NULL;
	determinant = matrix_determinant(m);
	if (determinant)
		invert(inverted, determinant, m, inverted);
	/*
		inverted = invert(determinant, m, inverted);
	if (!inverted)
		return (NULL);
	return (inverted);
	*/
}

void	tuple_apply_trans_matrix(t_tuple *resut, t_matrix *invtd, t_tuple *tup)
{
	t_matrix	source_tuple_converted;
	t_matrix	product;
	t_tuple		*res;
	int			need_free;

	/* DEBUG */
	printf("tuple_apply_trans_matrix\n");
	/* ***** */
	tuple_to_matrix(&source_tuple_converted, tup);
	/* DEBUG */
	//source_tuple_converted = tuple_to_matrix(tup);
	need_free = 1;
	if (trans_matrix)
	{
		mtx_multiply(&product, trans_matrix, &source_tuple_converted);
		need_free = 0;
	}
	else
		product = source_tuple_converted;
	res = tuple_point(product->matrix[0][0],
			product->matrix[1][0], product->matrix[2][0]);
	if (tuple_is_vector(tup))
		res->type = IS_VECTOR;
	if (need_free)
		matrix_free(trans_matrix);
	matrix_free(product);
	free(tup);
	return (res);
}
/*
t_matrix	*invert(double determinant, t_matrix *m, t_matrix *inverted)
{
	int			i;
	int			j;
	t_matrix	*cofactors;
	double		diag;

	i = -1;
	cofactors = matrix_matrix(m->h, m->w);
	while (++i < m->h)
	{
		j = -1;
		while (++j < m->w)
			cofactors->mtx[i][j] = matrix_cofactor(m, i, j);
	}
	inverted = matrix_transpose(cofactors);
	i = -1;
	while (++i < m->h)
	{
		j = -1;
		while (++j < m->w)
		{
			diag = inverted->mtx[i][j] / determinant;
			inverted->mtx[i][j] = diag;
		}
	}
	return (inverted);
}

t_matrix	*matrix_invert(t_matrix *m)
{
	double		determinant;
	//t_matrix	*inverted;

	//inverted = NULL;
	determinant = matrix_determinant(m);
	if (determinant)
		inverted = invert(determinant, m, inverted);
	if (!inverted)
		return (NULL);
	return (inverted);
}

void	tuple_apply_trans_matrix(t_tuple *resut, t_matrix *invtd, t_tuple *tup)
{
	t_matrix	source_tuple_converted;
	t_matrix	product;
	t_tuple		*res;
	int			need_free;

	// DEBUG /
	printf("tuple_apply_trans_matrix\n");
	//
	tuple_to_matrix(&source_tuple_converted, tup);
	// DEBUG 
	//source_tuple_converted = tuple_to_matrix(tup);
	need_free = 1;
	if (trans_matrix)
	{
		mtx_multiply(&product, trans_matrix, &source_tuple_converted);
		need_free = 0;
	}
	else
		product = source_tuple_converted;
	res = tuple_point(product->matrix[0][0],
			product->matrix[1][0], product->matrix[2][0]);
	if (tuple_is_vector(tup))
		res->type = IS_VECTOR;
	if (need_free)
		matrix_free(trans_matrix);
	matrix_free(product);
	free(tup);
	return (res);
}

*/