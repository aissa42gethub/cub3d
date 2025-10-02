/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aissa <aissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:37:10 by azsaleh           #+#    #+#             */
/*   Updated: 2025/10/01 15:59:48 by aissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	print_error(char *msg)
{
	printf(RED "Error\n%s\n" RESET, msg);
	return (1);
}

// Initialize cub struct
static void	init_cub(t_cub *cub)
{
	cub->tex.no = NULL;
	cub->tex.so = NULL;
	cub->tex.we = NULL;
	cub->tex.ea = NULL;
	cub->bg.floor[0] = 0;
	cub->bg.floor[1] = 0;
	cub->bg.floor[2] = 0;
	cub->bg.ceiling[0] = 0;
	cub->bg.ceiling[1] = 0;
	cub->bg.ceiling[2] = 0;
	cub->player.x = 0;
	cub->player.y = 0;
	cub->player.dir = '\0';
	cub->map.point = NULL;
	cub->map.w = 0;
	cub->map.h = 0;
	cub->map.is_invalid = 0;
	cub->mlx.mlx = NULL;
	cub->mlx.win = NULL;
}

int cleanup(t_cub *cub)
{
    if (cub->img_tex.no.img)
        mlx_destroy_image(cub->mlx.mlx, cub->img_tex.no.img);
    if (cub->img_tex.so.img)
        mlx_destroy_image(cub->mlx.mlx, cub->img_tex.so.img);
    if (cub->img_tex.we.img)
        mlx_destroy_image(cub->mlx.mlx, cub->img_tex.we.img);
    if (cub->img_tex.ea.img)
        mlx_destroy_image(cub->mlx.mlx, cub->img_tex.ea.img);
    if (cub->mlx.img)
        mlx_destroy_image(cub->mlx.mlx, cub->mlx.img);
    if (cub->mlx.win)
        mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
    if (cub->mlx.mlx)
        mlx_destroy_display(cub->mlx.mlx);
    free(cub->mlx.mlx);
    exit(0);
}

void free_cub(t_cub *cub, int should_cleanup)
{
	if (cub->tex.no)
		free(cub->tex.no);
	if (cub->tex.so)
		free(cub->tex.so);
	if (cub->tex.we)
		free(cub->tex.we);
	if (cub->tex.ea)
		free(cub->tex.ea);
	if (cub->map.point)
		ft_freearray(cub->map.point);
    if(should_cleanup)
        cleanup(cub);
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc != 2)
		return (print_error("Invalid number of arguments"));
	init_cub(&cub);
	if (parsing(&cub, argv))
		return (free_cub(&cub, 0), 1);
	if (execute(&cub))
	{
		free_cub(&cub, 1);
		return (print_error("exec failure"));
	}
	free_cub(&cub, 1);
	return (0);
}