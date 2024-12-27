/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:32:29 by syl               #+#    #+#             */
/*   Updated: 2024/12/21 15:07:49 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

//	color = 256 * 256 * red + 256 * green + blue;
int modify_color(int color, float intensity)
{
	int red;
	int green;
	int blue;
	int colorback;
	
	red = (color >> 16)&255;
	green = (color >> 8)&255;
	blue = color&255;

	colorback = 0;
	red *= intensity;
	green *= intensity;
	blue *=intensity;

	colorback += (red << 16);
	colorback += (green << 8);
	colorback += blue;
	return (colorback);
}

int modify_color_rgb(int color)
{
	color -= 90;
	color += 256 *37;
	color += 256 * 256 * 119; 

	return (color);
}