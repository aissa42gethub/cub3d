/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaissa <aaissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:02:40 by aaissa            #+#    #+#             */
/*   Updated: 2025/10/02 16:18:14 by aaissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	detect_collision(t_cub *cub, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_v < ray->side_dist_h)
		{
			ray->side_dist_v += ray->step_size_x;
			ray->map_x += ray->step_dir_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_h += ray->step_size_y;
			ray->map_y += ray->step_dir_y;
			ray->side = 1;
		}
		if (cub->map.point[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

static void	set_step_direction(t_cub *cub, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_dir_x = -1;
		ray->side_dist_v = (cub->player.x - ray->map_x) * ray->step_size_x;
	}
	else
	{
		ray->step_dir_x = 1;
		ray->side_dist_v = (ray->map_x + 1 - cub->player.x) * ray->step_size_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_dir_y = -1;
		ray->side_dist_h = (cub->player.y - ray->map_y) * ray->step_size_y;
	}
	else
	{
		ray->step_dir_y = 1;
		ray->side_dist_h = (ray->map_y + 1 - cub->player.y) * ray->step_size_y;
	}
}

static void	render_walls(t_cub *cub, int x, t_ray *ray)
{
	set_step_direction(cub, ray);
	detect_collision(cub, ray);
	if (ray->side == 0)
		ray->corrected_dist = (ray->map_x - cub->player.x
				+ (1 - ray->step_dir_x) / 2) / ray->ray_dir_x;
	else
		ray->corrected_dist = (ray->map_y - cub->player.y
				+ (1 - ray->step_dir_y) / 2) / ray->ray_dir_y;
	if (ray->corrected_dist <= 0)
		ray->corrected_dist = 0.010;
	ray->line_height = (int)(WIN_HEIGHT / ray->corrected_dist);
	ray->draw_start = (-ray->line_height / 2) + (WIN_HEIGHT / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height / 2) + (WIN_HEIGHT / 2);
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
	add_texture(cub, x, ray);
}

void	set_ray(t_cub *cub, t_ray *ray, double camera_x)
{
	ray->camera_x = camera_x;
	ray->ray_dir_x = cub->player.dir_x
		+ cub->player.plane_x * ray->camera_x;
	ray->ray_dir_y = cub->player.dir_y
		+ cub->player.plane_y * ray->camera_x;
	ray->map_x = (int)cub->player.x;
	ray->map_y = (int)cub->player.y;
	if (ray->ray_dir_x == 0)
		ray->step_size_x = (double)INT_MAX;
	else
		ray->step_size_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->step_size_y = (double)INT_MAX;
	else
		ray->step_size_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

int	game_loop(t_cub *cub)
{
	int		x;
	t_ray	ray;
	double	camera_x;

	render_background(cub);
	x = 0;
	while (x < WIN_WIDTH)
	{
		camera_x = (2.0 / WIN_WIDTH) * x - 1;
		set_ray(cub, &ray, camera_x);
		render_walls(cub, x, &ray);
		x++;
	}
	render_2d_map(cub);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img, 0, 0);
	return (0);
}
