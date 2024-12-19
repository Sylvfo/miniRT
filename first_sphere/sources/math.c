/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:28:57 by sforster          #+#    #+#             */
/*   Updated: 2024/12/19 13:51:24 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

float dot_product(t_vect3d *va, t_vect3d *vb)
{
	float	dot;

	dot = va->x * vb->x + va->y * vb->y + va->z * vb->z;
	return (dot);
}
