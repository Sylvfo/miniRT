/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:55:44 by sforster          #+#    #+#             */
/*   Updated: 2024/12/25 17:26:53 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

//	int 	*O; // position de la camera DATAS COMMUN
//	int 	Cw; // largeur x du canvas DATAS COMMUN
//	int 	Ch; // hauteur y du canvas DATAS COMMUN
//	int 	D[3]; // coordonnees 3D du viewport. Dans DATAS PIX
//	O = (0, 0, 0);

void ray_tracing(t_pix ***pix, t_image *ima)
{
	float 	Cx; // axe x sur le canvas -> ici
	float	Cy; // axe y sur la canvas -> ici
	int		x;
	int		y;

	x = 0;
	y = 0;
	Cx = (pix[0][0]->global->caneva_width / 2) * -1;
	while (x < pix[0][0]->global->caneva_width)
	{
		Cy = (pix[0][0]->global->caneva_height / 2) *-1;
		while (y < pix[0][0]->global->caneva_height) // pour chaque point sur le canvas
		{
			CanvasToViewport(Cx, Cy, pix[x][y]); // trouver le view port
			TraceRay(pix[x][y]); // trouver la couleur des points.
			mlx_pixel_put(ima->mlx_ptr, ima->mlx_win, x, y, pix[x][y]->color);
			y++;
			Cy++;
		}
		Cx++;
		y = 0;
		x++;
	}
}

void	CanvasToViewport(float Cx, float Cy, t_pix *pix)  // mettre data dedans Cx et Cy c est les points x y sur le canvas
{
	if (!pix)
        return;
	pix->Cx = Cx; // a faire au debut??
	pix->Cy = Cy; // a faire au debut???
	pix->D->x = Cx * (pix->global->view_width / pix->global->caneva_width); // Vw / Cw a calculer une fois pour tous???
	pix->D->y = Cy * (pix->global->view_height / pix->global->caneva_height); // a calculer une fois pour tous???
	pix->D->z = pix->global->Vz;
	return;
}

void TraceRay(t_pix *pix)
{
	float closestt = INT_MAX;
	t_sphere *closest_sphere; // data struc or malloc?? non c est un pointeur
	int i = 0;

	closest_sphere = NULL;
//rajouter pour plusieures spheres
	while (i < 4)
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
//		ComputeLighting(pix, closestt, closest_sphere);
		
		pix->color = closest_sphere->color;
		i++;
	}
}

void IntersectRaySphere(t_pix *pix, t_sphere *sphere)
{
	float discriminant;
	float a;
	float b;
	float c;
	t_vect3d *CO;

	CO = malloc(sizeof(t_vect3d));
	CO->x = -sphere->center->x;
	CO->y = -sphere->center->y;
	CO->z = -sphere->center->z;
	a = dot_product(pix->D, pix->D);
	b = 2 * dot_product(CO, pix->D);
	c = dot_product(CO, CO) - (sphere->radius * sphere->radius);

	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
	{
		pix->t1 = INT_MAX;
		pix->t2 = INT_MAX;
		return;
	}
	pix->t1 =(-b + sqrt(discriminant)) / (2*a);
	pix->t2 = (-b - sqrt(discriminant)) / (2*a);
	free (CO);
}


	// CO = O - sphere.center  do product of the ray with himself
	// Dot Product: The dot product of a vector with itself is computed by 
	//⟨P−C,P−C⟩=(Px−Cx)2+(Py−Cy)2+(Pz−Cz)2⟨P−C,P−C⟩
	// Square of rr: The right-hand side of the equation is r2r2, which is just a scalar valu

void	test(t_pix *pix, int x, int y)
{
	printf("test x %i y %i\n", x, y);
	pix->Cx = x;
	pix->Cy = y;
}

void	test_print(t_pix *pix, int x, int y)
{
	printf("test x %i y %i\n", x, y);
	printf("test2 x%i y %i \n", pix->Cx, pix->Cy);
}

/*

DATAS:
communs:
int 	*O; // position de la camera DATAS
int 	Cw; // largeur x du canvas DATAS
int 	Ch; // hauteur y du canvas DATAS
s

pour chaque pixel:
DATA PIX
	int 	Cx; // axe x sur le canvas -> ici
	int 	Cy; // axe y sur la canvas -> ici
	int 	D[3]; // coordonnees 3D du viewport. Dans DATAS?




ignore solution with t < 0 (derriere la camera)
ignore also solutions with t < 1 (entre ecran et camera)

t + c est les points le long de la ligne
il faut voir si ces points touchent la sphrere. 
*/