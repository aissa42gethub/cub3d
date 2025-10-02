/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaissa <aaissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:53:57 by aaissa            #+#    #+#             */
/*   Updated: 2025/10/02 16:02:19 by aaissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_collision(t_cub *cub, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(new_x);
	map_y = (int)(new_y);
	if (map_x < 0 || map_x >= cub->map.w || map_y < 0 || map_y >= cub->map.h)
		return (1);
	if (cub->map.point[map_y][map_x] == '1')
		return (1);
	return (0);
}

void	move_to_dir(int keycode, t_cub *cub, double *move_x, double *move_y)
{
	if (keycode == W)
	{
		*move_x = cub->player.dir_x * MOVE_SPEED;
		*move_y = cub->player.dir_y * MOVE_SPEED;
	}
	else if (keycode == S)
	{
		*move_x = -cub->player.dir_x * MOVE_SPEED;
		*move_y = -cub->player.dir_y * MOVE_SPEED;
	}
	else if (keycode == D)
	{
		*move_x = cub->player.plane_x * MOVE_SPEED;
		*move_y = cub->player.plane_y * MOVE_SPEED;
	}
	else if (keycode == A)
	{
		*move_x = -cub->player.plane_x * MOVE_SPEED;
		*move_y = -cub->player.plane_y * MOVE_SPEED;
	}
}

void	move_player(t_cub *cub, int keycode)
{
	double	move_x;
	double	move_y;
	double	new_x;
	double	new_y;

	move_x = 0;
	move_y = 0;
	new_x = 0;
	new_y = 0;
	move_to_dir(keycode, cub, &move_x, &move_y);
	new_x = cub->player.x + move_x;
	new_y = cub->player.y + move_y;
	if (!check_collision(cub, new_x, cub->player.y))
		cub->player.x = new_x;
	if (!check_collision(cub, cub->player.x, new_y))
		cub->player.y = new_y;
}

void	rotate_player(t_cub *cub, int keycode)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_angle;

	rot_angle = ROT_ANGLE;
	if (keycode == LARROW)
		rot_angle = -ROT_ANGLE;
	else if (keycode == RARROW)
		rot_angle = ROT_ANGLE;
	else
		return ;
	old_dir_x = cub->player.dir_x;
	cub->player.dir_x = cub->player.dir_x * cos(rot_angle)
		- cub->player.dir_y * sin(rot_angle);
	cub->player.dir_y = old_dir_x * sin(rot_angle)
		+ cub->player.dir_y * cos(rot_angle);
	old_plane_x = cub->player.plane_x;
	cub->player.plane_x = cub->player.plane_x * cos(rot_angle)
		- cub->player.plane_y * sin(rot_angle);
	cub->player.plane_y = old_plane_x * sin(rot_angle)
		+ cub->player.plane_y * cos(rot_angle);
}

void	move_rotate(int key_code, t_cub *cub)
{
	if (key_code == LARROW || key_code == RARROW)
		rotate_player(cub, key_code);
	else if (key_code == A || key_code == W || key_code == S || key_code == D)
		move_player(cub, key_code);
}
