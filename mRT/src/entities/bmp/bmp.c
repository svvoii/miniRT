/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:08:19 by rokupin           #+#    #+#             */
/*   Updated: 2023/09/07 17:04:25 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	init_canvas(unsigned int w, unsigned int h, t_canvas *c)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	c->h = h;
	c->w = w;
	c->canvas = (unsigned int **)malloc(sizeof(int *) * h);
	while (i < h)
	{
		(c->canvas)[i] = (unsigned int *)malloc(sizeof(int) * w);
		j = 0;
		while (j < w)
		{
			(c->canvas)[i][j] = 0;
			j++;
		}
		i++;
	}
}
/*
void	vw(int fd, void *ptr, size_t len)
{
	int	silencer;

	silencer = write(fd, ptr, len);
	silencer++;
	(void)silencer;
}

void	canvas_free(t_canvas *c)
{
	unsigned int	i;

	i = 0;
	while (i < c->h)
	{
		free(c->canvas[i]);
		i++;
	}
	free(c->canvas);
}

int	init_bmp(int h, int w, int fd)
{
	unsigned int	file_size;
	unsigned int	total_h_size;
	unsigned int	dib_h_size;
	unsigned int	color_planes;
	unsigned int	bits_per_pixel;

	total_h_size = 54;
	file_size = total_h_size + 3 * w * h;
	vw(fd, "BM", 2);
	vw(fd, &file_size, 4);
	vw(fd, "\0\0\0\0", 4);
	vw(fd, &total_h_size, 4);
	dib_h_size = 40;
	color_planes = 1;
	bits_per_pixel = 32;
	vw(fd, &dib_h_size, 4);
	vw(fd, &w, 4);
	vw(fd, &h, 4);
	vw(fd, &color_planes, 2);
	vw(fd, &bits_per_pixel, 2);
	vw(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 24);
	return (fd);
}

void	fill_bmp(int fd, t_canvas *c)
{
	unsigned char	bmp_pad[40];
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < 40)
	{
		bmp_pad[i] = 0;
		i++;
	}
	i = c->h;
	while (i > 0)
	{
		j = 0;
		while (j < c->w)
		{
			vw(fd, &(c->canvas[i - 1][j]), 4);
			j++;
		}
		i--;
	}
	vw(fd, bmp_pad, (4 - (c->w * 3) % 4));
	close(fd);
}
*/
