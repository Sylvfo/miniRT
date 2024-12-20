/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:26:51 by syl               #+#    #+#             */
/*   Updated: 2024/12/20 23:17:58 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"
/*
void TraceRay(t_pix *pix)
{
	float closestt = INT_MAX;
	t_sphere *closest_sphere; // data struc or malloc?? non c est un pointeur
	int i = 0;

	closest_sphere = NULL;
//rajouter pour plusieures spheres
	while (i < 4)// nb_spheres
	{
		IntersectRaySphere(pix, pix->global->scene->sphere[i]);
		if (pix->t1 < closestt && pix->t1 > 1)
		{
			closestt = pix->t1;
			closest_sphere = pix->global->scene->sphere[i];
		}
		if (pix->t2 < closestt && pix->t2 > 1)
		{
			closestt = pix->t2;
			closest_sphere = pix->global->scene->sphere[i];
		}
		if (closest_sphere == NULL)
		{
			pix->color = pix->global->backgroundcolor;
			return ;
		}
		// ici ajouter pour calculer la lumiere....
		pix->color = closest_sphere->color;
		i++;
	}
}*/

float ComputeLighting(t_pix *pix, float closestt, t_sphere *closest_sphere)
{
	int color;
	t_3dpoint *P;
	t_vect3d *N;

	P = malloc(sizeof(t_3dpoint));
	P = pointonline(pix, closestt);
	N = malloc(sizeof(t_vect3d));
	N = vect_from_points(P, closest_sphere->center);
	// Compute sphere normal at intersection
	normalize_vector(N);// faire formule pour ca aussi...
	color = closest_sphere->color * light_intensity(P, N, pix);
	free (P);
	free (N);
	return (color);
}

float light_intensity(t_3dpoint *P, t_vect3d *N, t_pix *pix)
{
	float i;
	float n_dot_l;

	i = 0.0;
	//boucle while pour différents 
	i += compute_ambient(pix);// ok
	i += compute_spotlight(P, N, pix, pix->scene->light1);
//	i += computre_directionlight 
	return (i);
}

float 	compute_spotlight(t_3dpoint *P, t_vect3d *N, t_pix *pix, t_spotlight *light)
{
	t_vect3d *L;
	float n_dot_l;
	float i;

	i = 0.0;

	L = malloc(sizeof(t_vect3d));
	L = vect_from_points(light->coord, P);// TROUVER P
	n_dot_l =  dot_product(N, L);// TROUVER N
	if (n_dot_l > 0) 
	{
		i = light->ratio* n_dot_l/(lenght_vector(N) * lenght_vector(L));
	}
	free (L);
	return (i);
}

float 	compute_ambient(t_pix *pix)
{
	float i;

	i = pix->scene->ambiant_light_ratio;
	return (i);
}

