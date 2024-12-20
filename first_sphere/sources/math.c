/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:28:57 by sforster          #+#    #+#             */
/*   Updated: 2024/12/20 23:08:29 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

float dot_product(t_vect3d *va, t_vect3d *vb)
{
	float	dot;

	dot = va->x * vb->x + va->y * vb->y + va->z * vb->z;
	return (dot);
}

t_vect3d *vect_from_points(t_3dpoint *a, t_3dpoint *b)
{
	t_vect3d *new;

	new->x = a->x - b->x;
	new->y = a->y - b->y;
	new->z = a->z - b->z;
	return (new);
}

float	lenght_vector(t_vect3d *vect)
{
	float	length;

	length = sqrt((vect->x * vect->x) + (vect->y * vect->y) + (vect->z * vect->z));
	return (length);	
}

void normalize_vector(t_vect3d *vect)
{
	float length;

	length = lenght_vector(vect);
	vect->x /= length;
	vect->y /= length;
	vect->z /= length;
}

t_3dpoint *pointonline(t_pix *pix, float closestt)
{
	t_3dpoint *P;
	float D_norm;// pas bien compris vecteur directionnel normalisé
	
	P = malloc(sizeof(t_3dpoint));
	D_norm = sqrt(pix->D->x * pix->D->x + pix->D->y * pix->D->y + pix->D->z * pix->D->z);
	if (D_norm == 0)
	{
		P = pix->global->cam;
		return (P);
	}
	P->x = pix->global->cam->x + closestt * (pix->D->x / D_norm);
	P->y = pix->global->cam->y + closestt * (pix->D->y / D_norm);
	P->z = pix->global->cam->z + closestt * (pix->D->z / D_norm);
}
