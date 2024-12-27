/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:31:47 by syl               #+#    #+#             */
/*   Updated: 2024/12/27 11:10:12 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

t_scene *init_scene(void)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	scene->sphere = (t_sphere **)malloc(4 * sizeof(t_sphere *));

	scene->sphere[0] = malloc(sizeof(t_sphere));
	scene->sphere[0]->center = malloc(sizeof(t_3dpoint));
	scene->sphere[0]->center->x = 450;
	scene->sphere[0]->center->y = 350;
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

	scene->light1 = init_lights();
	
	scene->ambient_light_ratio = 1;
//	scene->ambient_light_color = 0.5;
	return (scene);
}
	
t_spotlight *init_lights(void)
{
	t_spotlight *light1;

	light1 = malloc(sizeof(t_spotlight));
	light1->coord = malloc(sizeof(t_3dpoint));
	light1->ratio = 0.2;
	light1->coord->x = 0;
	light1->coord->y = 5;
	light1->coord->z = 0;
	return (light1);
}
