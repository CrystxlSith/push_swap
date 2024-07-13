/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:59:00 by crystal           #+#    #+#             */
/*   Updated: 2024/07/13 20:05:29 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_map(t_mlx_data *data)
{
	int	rows;
	int	cols;

	cols = 0;
	while (cols < data->cols)
	{
		rows = 0;
		while (rows < data->rows)
		{
			if (data->map[cols][rows] == WALL)
				mlx_put_image_to_window(data->mlx, data->win, data->wall.img, rows * 32, cols * 32);
			else if (data->map[cols][rows] == EXIT)
				mlx_put_image_to_window(data->mlx, data->win, data->exit.img, rows * 32, cols * 32);
			else if (data->map[cols][rows] == COLLECTIBLE)
				mlx_put_image_to_window(data->mlx, data->win, data->collectible.img, rows * 32, cols * 32);
			else if (data->map[cols][rows] == PLAYER)
				mlx_put_image_to_window(data->mlx, data->win, data->player.img, rows * 32, cols * 32);
			else if (data->map[cols][rows] == GROUND)
				mlx_put_image_to_window(data->mlx, data->win, data->ground.img, rows * 32, cols * 32);
			rows++;
		}
		cols++;
	}
}