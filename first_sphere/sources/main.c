/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:38:19 by sforster          #+#    #+#             */
/*   Updated: 2024/12/18 17:26:42 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

int main(void)
{
	t_pix	***pix;// points a calculer
	t_image *ima;
	
	pix = init_data();
	ima = init_image();
//	ray_tracing(pix);
	printf("Hello new thing\n");
}

/*
int	main(int argc, char **argv)
{
	t_map	*map;
	t_data	*ima;

	ima = malloc(sizeof(t_data));

	
	ima->mlx_win = mlx_new_window(ima->mlx_ptr, 2200, 1300, "fenfen");
	ima->map = map;
	drawings(ima);
	mlx_hook(ima->mlx_win, 17, 0, ft_exit, ima);
	mlx_hook(ima->mlx_win, 2, 1L << 0, ft_keys, ima);
	mlx_loop(ima->mlx_ptr);
	free (map);
	return (0);
}*/
