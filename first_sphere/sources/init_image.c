/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:08:38 by sforster          #+#    #+#             */
/*   Updated: 2024/12/18 17:15:58 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

t_image *init_image(void)
{
	t_image *ima;

	ima = NULL;
	ima = malloc(sizeof(t_image));
	if (!ima)
		return (0);
	ima->mlx_ptr = mlx_init();
	if (ima->mlx_ptr == NULL)
		return (0);
	ima->mlx_win = mlx_new_window(ima->mlx_ptr, 1920, 1080, "Fen fen");
	mlx_hook(ima->mlx_win, 2, 1L << 0, ft_keys, ima);
	mlx_loop(ima->mlx_ptr);
}