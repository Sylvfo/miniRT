/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:49:29 by sforster          #+#    #+#             */
/*   Updated: 2024/12/18 17:19:36 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

/*
void	put_pixels(x, y, int color)
{
	
}



void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!x || !y)
		return ;
	if (x >= 2200)
		return ;
	if (y >= 1300)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
*/

int	ft_keys(int keycode, t_image *ima)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_image(ima->mlx_ptr, ima->img);
		mlx_destroy_window(ima->mlx_ptr, ima->mlx_win);
		printf("ESC pressed.\nWindow closed\n");
//		ft_free_list(&ima->map);
//		free(ima);
		exit(0);
		return (0);
	}
	return (0);
}

int	ft_exit(t_image *ima)
{
	mlx_destroy_image(ima->mlx_ptr, ima->img);
	mlx_destroy_window(ima->mlx_ptr, ima->mlx_win);
	printf("Window closed\n");
//	ft_free_list(&ima->map);
//	free(ima);
	exit(0);
	return (0);
}