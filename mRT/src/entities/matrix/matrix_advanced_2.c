/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_advanced_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/07 17:46:38 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

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
			cofactors->matrix[i][j] = matrix_cofactor(m, i, j);
	}
	inverted = matrix_transpose(cofactors);
	i = -1;
	while (++i < m->h)
	{
		j = -1;
		while (++j < m->w)
		{
			diag = inverted->matrix[i][j] / determinant;
			inverted->matrix[i][j] = diag;
		}
	}
	return (inverted);
}
*/

t_matrix	*matrix_invert(t_matrix *m)
{
	double		determinant;
	t_matrix	*inverted;

	inverted = NULL;
	determinant = matrix_determinant(m);
	if (determinant)
		inverted = invert(determinant, m, inverted);
	if (!inverted)
		return (NULL);
	return (inverted);
}

t_tuple	*tuple_apply_trans_matrix(t_matrix *trans_matrix, t_tuple *tup)
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
		matrix_multiply(&product, trans_matrix, &source_tuple_converted);
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
