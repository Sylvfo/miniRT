/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:31:43 by sforster          #+#    #+#             */
/*   Updated: 2024/12/19 16:31:25 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

t_pix	***init_data(void)
{
	t_view 	*global;
	t_pix	***pix;

	global = NULL;
	pix = NULL;
	global = init_global();
	if (global == NULL)
		return (NULL);
	pix = init_pix(pix, global);
	if (pix == NULL)
	{
		free (global);
		return (NULL);
	}
	link_pix_global(pix, global);
	(void) global;
	return (pix);
}

t_pix ***init_pix(t_pix ***pix, t_view *global)
{
    int x;
	int y;

	x = 0;
    pix = (t_pix ***)malloc(global->caneva_width * sizeof(t_pix **));
    if (!pix)
        return NULL;

	while(x < global->caneva_width)
	{
		y = 0; 
		pix[x] = (t_pix **)malloc(global->caneva_height * sizeof(t_pix *));
        if (!pix[x])
			return NULL; //free...
		while (y < global->caneva_height)
		{
			pix[x][y] = (t_pix *)malloc(sizeof(t_pix));
            if (!pix[x][y])
                return NULL;//free...
 //           pix[x][y]->global = global;
			y++;
		}
		x++;
	}

    for (x = 0; x < global->caneva_width; x++)
    {
        pix[x] = (t_pix **)malloc(global->caneva_height * sizeof(t_pix *));
        if (!pix[x])
			return NULL; //free...
        for (y = 0; y < global->caneva_height; y++)
        {
            pix[x][y] = (t_pix *)malloc(sizeof(t_pix));
            if (!pix[x][y])
                return NULL;//free...
			pix[x][y]->D = malloc(sizeof(t_vect3d));
            pix[x][y]->global = global; // Associer chaque pixel à la structure globale
        }
    }
    return pix;
}

t_view	*init_global(void)
{
	t_view *global;


	global = malloc(sizeof(t_view));
	if (!global)
		return (NULL);
//	global->camera = malloc(3 * sizeof(int));
	global->cam = malloc(sizeof(t_3dpoint));
/*	if (!global->camera)
	{
		free (global);
		return (NULL);
	}*/
//	global->camera[0] = 0;
//	global->camera[1] = 0;
//	global->camera[2] = 0;
	global->caneva_width = 1500;
	global->caneva_height = 1000;
	global->view_width = 2000; // ?????
	global->view_height = 1500; // ?????????
	global->scene = malloc(sizeof(t_scene));
	global->Vz = 100;
	global->backgroundcolor = 29565; //1644825;
	global->cam->x = 0;
	global->cam->y = 0;
	global->cam->z = 0;
	global->scene = init_scene();
	return (global);
}

/*	philo = (t_philo **)malloc(ft_atoi(argv[ARGV_NB_PHILO])
			* sizeof(t_philo *));*/

t_scene *init_scene(void)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	scene->sphere = (t_sphere **)malloc(4 * sizeof(t_sphere *));

	scene->sphere[0] = malloc(sizeof(t_sphere));
	scene->sphere[0]->center = malloc(sizeof(t_3dpoint));
	scene->sphere[0]->center->x = 0;
	scene->sphere[0]->center->y = 200;
	scene->sphere[0]->center->z = 200;
	scene->sphere[0]->color = 7536765;
	scene->sphere[0]->radius = 300;

	scene->sphere[1] = malloc(sizeof(t_sphere));
	scene->sphere[1]->center = malloc(sizeof(t_3dpoint));
	scene->sphere[1]->center->x = -120;
	scene->sphere[1]->center->y = 50;
	scene->sphere[1]->center->z = 180;
	scene->sphere[1]->color = 15;
	scene->sphere[1]->radius = 20;

	scene->sphere[2] = malloc(sizeof(t_sphere));
	scene->sphere[2]->center = malloc(sizeof(t_3dpoint));
	scene->sphere[2]->center->x = 120;
	scene->sphere[2]->center->y = 50;
	scene->sphere[2]->center->z = 180;
	scene->sphere[2]->color = 15;
	scene->sphere[2]->radius = 20;

	scene->sphere[3] = malloc(sizeof(t_sphere));
	scene->sphere[3]->center = malloc(sizeof(t_3dpoint));
	scene->sphere[3]->center->x = 0;
	scene->sphere[3]->center->y = 150;
	scene->sphere[3]->center->z = 120;
	scene->sphere[3]->color = 7536700;
	scene->sphere[3]->radius = 25;

	return (scene);
}





void	link_pix_global(t_pix ***pix, t_view *global)
{
	int x;
	int y;

	x = 0;
	while (x < global->caneva_width)
	{
		y = 0;
		while (y < global->caneva_height)
		{
			pix[x][y]->global = global;
			y++;
		}
		x++;
	}
	return;
}

/* POUR LES FREE
t_pix ***init_pix(t_pix ***pix, t_view *global)
{
    int x, y;

    pix = (t_pix ***)malloc(global->caneva_width * sizeof(t_pix **));
    if (!pix)
        return NULL;
    
    for (x = 0; x < global->caneva_width; x++)
    {
        pix[x] = (t_pix **)malloc(global->caneva_height * sizeof(t_pix *));
        if (!pix[x])
        {
            while (x > 0)
            {
                x--;
                free(pix[x]);
            }
            free(pix);
            return NULL;
        }
        for (y = 0; y < global->caneva_height; y++)
        {
            pix[x][y] = (t_pix *)malloc(sizeof(t_pix));
            if (!pix[x][y])
            {
                while (y > 0)
                {
                    y--;
                    free(pix[x][y]);
                }
                while (x > 0)
                {
                    x--;
                    for (y = 0; y < global->caneva_height; y++)
                    {
                        free(pix[x][y]);
                    }
                    free(pix[x]);
                }
                free(pix);
                return NULL;
            }
            pix[x][y]->global = global; // Associer chaque pixel à la structure globale
        }
    }
    return pix;
}
*/