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
	char *string;

	string = malloc(10 * sizeof(char));
	string = "hye ⅏ ",
	
	pix = init_data();
	ima = init_image(pix[0][0]->global);
	
//	color_image(pix[0][0]->global, ima);
	ray_tracing(pix, ima);
	mlx_string_put(ima->mlx_ptr, ima->mlx_win, 30, 30, 0xffa500, string);
//	mlx_string_put(ima->mlx_ptr, ima->win_ptr, int 20, int 20, int color, char *string)
	image_hooks(ima);
	printf("Hello new thing\n");
}
