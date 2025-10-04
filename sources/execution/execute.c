/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aissa <aissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:43:05 by aaissa            #+#    #+#             */
/*   Updated: 2025/10/03 15:14:41 by aissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_win(t_cub *cub)
{
	free_cub(cub, 1);
	exit(0);
}

int	key_hook(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		close_win(cub);
	else
		move_rotate(keycode, cub);
	return (0);
}

void	init_player_dir(t_cub *cub)
{
	cub->player.dir_x = 0;
	cub->player.dir_y = 0;
	cub->player.plane_x = 0;
	cub->player.plane_y = 0;
	cub->player.mouse_x = -1;
}

void	set_player_dir(t_cub *cub)
{
	double	plane_len;

	plane_len = tan((FOV * M_PI / 180) / 2);
	init_player_dir(cub);
	if (cub->player.dir == 'N')
	{
		cub->player.dir_y = -1;
		cub->player.plane_x = plane_len;
	}
	else if (cub->player.dir == 'S')
	{
		cub->player.dir_y = 1;
		cub->player.plane_x = -plane_len;
	}
	else if (cub->player.dir == 'E')
	{
		cub->player.dir_x = 1;
		cub->player.plane_y = plane_len;
	}
	else if (cub->player.dir == 'W')
	{
		cub->player.dir_x = -1;
		cub->player.plane_y = -plane_len;
	}
}

int	execute(t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	if (!cub->mlx.mlx)
		return (print_error("Failed to initialize MLX"), 1);
	cub->mlx.win = mlx_new_window(cub->mlx.mlx,
			WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!cub->mlx.win)
		return (print_error("Failed to create window"), 1);
	cub->mlx.img = mlx_new_image(cub->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!cub->mlx.img)
		return (print_error("Failed to create image"), 1);
	cub->mlx.addr = mlx_get_data_addr(cub->mlx.img,
			&cub->mlx.bits_per_pixel,
			&cub->mlx.line_length, &cub->mlx.endian);
	set_player_dir(cub);
	init_textures(cub);
	mlx_hook(cub->mlx.win, KEY_PRESS, 1L << 0, key_hook, cub);
	mlx_hook(cub->mlx.win, MOUSE_MOVE, 1L << 6, mouse_move, cub);
	mlx_hook(cub->mlx.win, CLOSE, 1L << 1, close_win, cub);
	mlx_loop_hook(cub->mlx.mlx, game_loop, cub);
	mlx_loop(cub->mlx.mlx);
	return (0);
}
