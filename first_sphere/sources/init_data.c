/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:31:43 by sforster          #+#    #+#             */
/*   Updated: 2024/12/18 16:39:51 by sforster         ###   ########.fr       */
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
	global->camera = malloc(3 * sizeof(int));
	global->backgroundcolor = malloc(3 * sizeof(int));
	if (!global->camera)
	{
		free (global);
		return (NULL);
	}
	global->sphere1 = malloc(sizeof(t_sphere));
	global->sphere1->center = malloc(3 * sizeof(int));
	global->sphere1->color = malloc(3 * sizeof(int));
	global->camera[0] = 0;
	global->camera[1] = 0;
	global->camera[2] = 0;
	global->caneva_width = 5;
	global->caneva_height = 5;
	global->view_width = 2000; // ?????
	global->view_height = 1500; // ?????????
	global->Vz = 100;
	global->backgroundcolor[0] = 120;
	global->backgroundcolor[1] = 120;
	global->backgroundcolor[2] = 120;
	global->sphere1->center[0] = 200;
	global->sphere1->center[1] = 200;
	global->sphere1->center[2] = 200;
	global->sphere1->color[0] = 10;
	global->sphere1->color[1] = 10;
	global->sphere1->color[2] = 200;
	global->sphere1->radius = 150;
	return (global);
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