/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2024/12/18 18:20:52 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//# include "librairies/libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_sphere {
	int		*center;
	int		radius;
	int		*color;
}				t_sphere;

typedef struct	s_view {
	int		*camera; // x 0 y 0  z 0 O in the book
	float	caneva_width;
	float	caneva_height;
	float	view_width;
	float	view_height;
	int		Vz; //dist du viewport de la camera
	int 	*backgroundcolor;
	t_sphere *sphere1;
	// calculer rapport en canveva et view??
}				t_view;

// data struc = array of pixels. 
typedef struct	s_pix {
	int		Cx; //axe x sur le canvas
	int		Cy;  //axe y sur la canvas
	int		Vx; // coordonnee x du point sur le viewport 
	int		Vy; // coordonnee y du point sur le viewport 
	int		Vz; // coordonnee z du point sur le viewport
	int		color_r;
	int		color_v;
	int		color_b;
	t_view	*global;
	int		t1;
	int		t2;
} t_pix;

typedef struct s_image {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx_ptr;
	void			*mlx_win;
	t_view			*global;
}	t_image;

//main.c

// init_data.c
void	link_pix_global(t_pix ***pix, t_view *global);
t_view	*init_global(void);
t_pix	***init_pix(t_pix ***pix, t_view *global);
t_pix	***init_data(void);

//raytracing.c
void	test(t_pix *pix, int x, int y);
void	ray_tracing(t_pix ***pix);
void	test_print(t_pix *pix, int x, int y);
void	CanvasToViewport(float Cx, float Cy, t_pix *pix);

//init_image.c
t_image *init_image(t_view *global);
void	color_image(t_view *global, t_image *ima);
void	my_mlx_pixel_put(t_image *ima, int x, int y, int color);

//pixelPut
int	ft_keys(int keycode, t_image *ima);
int	ft_exit(t_image *ima);

#endif
