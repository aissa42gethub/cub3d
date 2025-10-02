/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aissa <aissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:11:07 by azrulsaleh        #+#    #+#             */
/*   Updated: 2025/10/02 15:38:50 by aaissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "cub3d.h"

typedef struct s_tile
{
	int mx;
	int	my;
	int psx;
	int psy;
}	t_tile;

typedef struct s_minimap
{
	int		player_x;
	int		player_y;
	double	ray_dir_x;
	double	ray_dir_y;
	int		line_start_x;
	int		line_start_y;
	int		line_end_x;
	int		line_end_y;
	int		ray_color;
}	t_minimap;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_v;
	double	side_dist_h;
	double	step_size_x;
	double	step_size_y;
	double	corrected_dist;
	int		step_dir_x;
	int		step_dir_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	char	dir;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		mouse_x;
}	t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_img_tex
{
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
}	t_img_tex;

typedef struct s_bg
{
	int		floor[3];
	int		ceiling[3];
}	t_bg;

typedef struct s_tex
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_tex;

typedef struct s_map
{
	char	**point;
	int		w;
	int		h;
	bool	is_invalid;
}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_cub
{
	t_mlx		mlx;
	t_map		map;
	t_tex		tex;
	t_bg		bg;
	t_img_tex	img_tex;
	t_player	player;
}	t_cub;

//parse
bool	parsing(t_cub *cub, char **av);

//texture
bool	is_line_texture(char *line);
bool	handle_texture_line(t_cub *cub, char *line);

//color
bool	is_line_color(char *line);
bool	handle_color_line(t_cub *cub, char *line);

//map
int		append_map_line(t_cub *cub, char *line);

//validate
int		validate_map(t_cub *cub);

//player
void	set_player_values(t_cub *cub);

//floodfill
bool	validate_closed_map(t_cub *cub, int y, int x);

// free 
void	free_cub(t_cub *cub, int should_cleanup);

#endif
