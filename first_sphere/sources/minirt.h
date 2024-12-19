/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2024/12/19 16:19:07 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//# include "librairies/libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

/*
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;
*/

typedef struct s_3dpoint {
	float	x;
	float	y;
	float   z;
} t_3dpoint;

typedef struct s_vect3d {
	float	x;
	float	y;
	float   z;
} t_vect3d;

typedef struct	s_sphere {
	t_3dpoint		*center;
	int				radius;
	int				color;
}				t_sphere;


typedef struct s_scene {
	t_sphere	**sphere;
	//autres formes
} t_scene;

typedef struct	s_plane {
	t_3dpoint		*point;
	t_vect3d		*directions;
	int				color;
}	t_plane;

typedef struct	s_cyl {
	t_3dpoint		*center;
	t_vect3d		*axis;
	int				height;
	int				diam;
	int				color;
}	t_cyl;

typedef struct	s_view {
//	int		*camera; // x 0 y 0  z 0 O in the book
	t_3dpoint	*cam;
	float	caneva_width;
	float	caneva_height;
	float	view_width;
	float	view_height;
	int		Vz; //dist du viewport de la camera
	t_scene		*scene;
	int 	backgroundcolor;
//	t_sphere *sphere1;
	// calculer rapport en canveva et view??
}				t_view;

// data struc = array of pixels. 
typedef struct	s_pix {
	int			Cx; //axe x sur le canvas
	int			Cy;  //axe y sur la canvas
	t_vect3d	*D; // vecteur entre camera et coordonnes sur viewport
	int			color;
	t_view		*global;
	float		t1;
	float		t2;
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
t_scene *init_scene(void);


//raytracing.c
void	ray_tracing(t_pix ***pix, t_image *ima);
void	CanvasToViewport(float Cx, float Cy, t_pix *pix);
void 	IntersectRaySphere(t_pix *pix, t_sphere *sphere);
void 	TraceRay(t_pix *pix);
void	test_print(t_pix *pix, int x, int y);
void	test(t_pix *pix, int x, int y);

//init_image.c
t_image *init_image(t_view *global);
void	color_image(t_view *global, t_image *ima);
void	my_mlx_pixel_put(t_image *ima, int x, int y, int color);
void 	image_hooks(t_image *ima);
//pixelPut
int	ft_keys(int keycode, t_image *ima);
int	ft_exit(t_image *ima);

//math.c
float dot_product(t_vect3d *va, t_vect3d *vb);


#endif
