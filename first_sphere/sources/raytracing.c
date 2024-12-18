/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:55:44 by sforster          #+#    #+#             */
/*   Updated: 2024/12/18 16:55:54 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

//	int 	*O; // position de la camera DATAS COMMUN
//	int 	Cw; // largeur x du canvas DATAS COMMUN
//	int 	Ch; // hauteur y du canvas DATAS COMMUN
//	int 	D[3]; // coordonnees 3D du viewport. Dans DATAS PIX
//	O = (0, 0, 0);

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

void ray_tracing(t_pix ***pix)
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
			//color = TraceRay(O, D, 1, inf);
			//	canvas.PutPixel(x, y, color);
			y++;
			Cy++;
		}
		Cx++;
		y = 0;
		x++;
	}
	printf("try  %i\n", pix[3][2]->Vx);
	printf("try  %i\n", pix[2][2]->Cx);
}

void	CanvasToViewport(float Cx, float Cy, t_pix *pix)  // mettre data dedans Cx et Cy c est les points x y sur le canvas
{
	if (!pix)
        return;
	pix->Cx = Cx; // a faire au debut??
	pix->Cy = Cy; // a faire au debut???
	pix->Vx = Cx * (pix->global->view_width / pix->global->caneva_width); // Vw / Cw a calculer une fois pour tous???
	pix->Vy = Cy * (pix->global->view_height / pix->global->caneva_height); // a calculer une fois pour tous???
	pix->Vz = pix->global->Vz;
	return;
}

/*
// 0 c est la camera, D c est le point sur le caneva 
//color = TraceRay(O, D, 1, inf)

void TraceRay(t_pix *pix)
{
	tout ca c est D
	pix->Vx;
	pix->Vy;
	pix->Vz;

	camera
	pix->global->camera;

//return
	pix->color_r = 
	pix->color_v = 
	pix->color_b = 
}


void IntersectRaySphere(t_pix *pix)
{
	float discriminant;
	float CO;
	float a;
	float b;
	float c;

	a = dot(D, D)
	

	CO = ????
	

	r = pix->global->sphere->radius
	

	


	a = 

	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
	{
		pix->t1 = INT_MAX;
		pix->t2 = INT_MAX;
		return;
	}

// return
	pix->t1 =(-b + sqrt(discriminant)) / (2*a);
	pix->t2 = (-b - sqrt(discriminant)) / (2*a);

}

*/
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

*/

/*
ignore solution with t < 0 (derriere la camera)
ignore also solutions with t < 1 (entre ecran et camera)

t + c est les points le long de la ligne
il faut voir si ces points touchent la sphrere. 
*/

/*
void ray_tracing(t_pix ***pix)
{
	float 	Cx; // axe x sur le canvas -> ici
	float	Cy; // axe y sur la canvas -> ici
	int		x;
	int		y;

	x = 0;
	y = 0;
	Cx = (pix[0][0]->global->caneva_width / 2) * -1;
//	Cy = -pix[0][0]->global->caneva_height / 2;
	while (x < pix[0][0]->global->caneva_width)
	{
		Cy = -pix[0][0]->global->caneva_height / 2;
		while (y < pix[0][0]->global->caneva_height) // pour chaque point sur le canvas
		{
			CanvasToViewport(Cx, Cy, pix[x][y]); // trouver le view port
			//color = TraceRay(O, D, 1, inf);
			//	canvas.PutPixel(x, y, color);
			Cy++;
			y++;
		}
		printf("aaa\n");
		y = 0;
		x++;
		Cx++;
	}
	printf("try  %i\n", pix[5][20]->Vx);
}

	x = 0;
	y = 0;
	while (x < pix[0][0]->global->caneva_width)
	{
		while (y < pix[0][0]->global->caneva_height) // pour chaque point sur le canvas
		{
			test_print(pix[x][y], x, y);
			
			y++;
		}
		y = 0;
		x++;
	}

*/