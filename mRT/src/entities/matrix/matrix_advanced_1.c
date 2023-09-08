/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_advanced_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/08 12:29:09 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

/*
t_matrix	*matrix_transpose(t_matrix *m)
{
	t_matrix	*res;
	int			i;
	int			j;

	res = matrix_matrix(m->h, m->w);
	i = 0;
	while (i < res->h)
	{
		j = 0;
		while (j < res->w)
		{
			res->matrix[i][j] = m->matrix[j][i];
			j++;
		}
		i++;
	}
	matrix_free(m);
	return (res);
}

t_matrix	*matrix_copy(t_matrix *m)
{
	t_matrix	*ret;
	int			i;
	int			j;

	ret = matrix_matrix(m->h, m->w);
	i = -1;
	while (++i < ret->h)
	{
		j = -1;
		while (++j < ret->w)
			ret->matrix[i][j] = m->matrix[i][j];
	}
	return (ret);
}
*/

//t_matrix	*matrix_sub(t_matrix *m, int column, int row)
void	matrix_sub(t_matrix *sub, t_matrix *m, int column, int row)
{
	//t_matrix	*sub;
	int			i;
	int			j;
	int			i_skip;
	int			j_skip;

	//sub = matrix_matrix(m->h - 1, m->w - 1);
	i = 0;
	i_skip = 0;
	while (i < m->h && !(i == column && column == m->h - 1))
	{
		j = 0;
		j_skip = 0;
		if (i == column && ++i)
			i_skip = 1;
		while (j < m->w && !(j == row && row == m->w - 1))
		{
			if (j == row && ++j)
				j_skip = 1;
			sub->mtx[i - i_skip][j - j_skip] = m->mtx[i][j];
			j++;
		}
		i++;
	}
	//return (sub);
}

double	matrix_minor(t_matrix *sub, t_matrix *m, int from, int to)
{
	//t_matrix	*sub;
	double		res;

	matrix_sub(sub, m, from, to);
	res = matrix_determinant(sub);
	//matrix_free(sub);
	return (res);
}

// changed ?!
double	matrix_cofactor(t_matrix *m, int from, int to)
{
	t_matrix	sub;
	double		minor;

	init_sub_matrix(&sub, m->h - 1, m->w - 1);
	minor = matrix_minor(&sub, m, from, to);
	if ((from + to) % 2)
		return (minor * -1);
	return (minor);
}

double	matrix_determinant(t_matrix *m)
{
	double		determinant;
	int			column;

	determinant = 0;
	column = -1;
	if (m->h == 2 && m->w == 2)
	{
		determinant = m->mtx[0][0] * m->mtx[1][1] - m->mtx[0][1] * m->mtx[1][0];
	}
	else
	{
		while (++column < m->w)
		{
			determinant += m->mtx[0][column] * matrix_cofactor(m, 0, column);
		}
	}
	return (determinant);
}
