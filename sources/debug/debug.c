/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aissa <aissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:37:10 by azsaleh           #+#    #+#             */
/*   Updated: 2025/09/02 10:22:16 by aissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//print north, south, west and east texture paths
static void	print_textures(t_cub *cub)
{
	printf("no texture: ");
	printf(GREEN "%s\n" RESET, cub->tex.no);
	printf("so texture: ");
	printf(GREEN "%s\n" RESET, cub->tex.so);
	printf("we texture: ");
	printf(GREEN "%s\n" RESET, cub->tex.we);
	printf("ea texture: ");
	printf(GREEN "%s\n\n" RESET, cub->tex.ea);
}

//print floor and ceiling color values
static void	print_planes(t_cub *cub)
{
	printf("floor: ");
	printf(GREEN "%d,%d,%d\n" RESET,
		cub->bg.floor[0], cub->bg.floor[1], cub->bg.floor[2]);
	printf("ceiling: ");
	printf(GREEN "%d,%d,%d\n\n" RESET,
		cub->bg.ceiling[0], cub->bg.ceiling[1], cub->bg.ceiling[2]);
}

//print player position and direction values
static void	print_player(t_player player)
{
	printf("player position: ");
	printf(GREEN "%d,%d\n" RESET, (int)player.x, (int)player.y);
	printf("player direction: ");
	printf(GREEN "%c\n" RESET, (int)player.dir);
}

//handler to show content to the main struct
void	debug_struct(t_cub *cub)
{
	print_textures(cub);
	print_planes(cub);
	print_map_values(cub->map);
	print_player(cub->player);
	debug_map_optimized(cub->map);
}
