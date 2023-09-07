/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/07 17:42:49 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "../../../includes/minirt.h"

/* handle_matrix.c */
void	mtx_identity(t_matrix *m, int i);
void	mtx_scale(t_matrix *m, double x, double y, double z);
void	mtx_translate(t_matrix *m, t_tuple *tpl);
void	mtx_multiply(t_matrix *res, t_matrix *m1, t_matrix *m2);
void	view_transform(t_camera *cam, t_tuple *to, t_tuple *up);

void	tuple_to_matrix(t_matrix *m, t_tuple *t);

/* matrix_advanced_2.c */
t_tuple	*tuple_apply_trans_matrix(t_matrix *trans_matrix, t_tuple *tup);


/* DEBUG */
void	print_matrix(t_matrix *m);

/*

# define M_MAX 4

typedef struct matrix
{
	double	matrix[M_MAX][M_MAX];
	int		h;
	int		w;
}	t_matrix;

*/

#endif
