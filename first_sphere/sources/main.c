/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:38:19 by sforster          #+#    #+#             */
/*   Updated: 2024/12/19 16:19:08 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

int main(void)
{
	t_pix	***pix;// points a calculer
	t_image *ima;
	
	pix = init_data();
	ima = init_image(pix[0][0]->global);
	
//	color_image(pix[0][0]->global, ima);
	ray_tracing(pix, ima);
	image_hooks(ima);
	printf("Hello new thing\n");
}

