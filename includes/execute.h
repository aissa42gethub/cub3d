
#ifndef EXECUTE_H
# define EXECUTE_H
# include "cub3d.h"


// Core execution functions
int		execute(t_cub *cub);
void	set_player_dir(t_cub *cub);
int		game_loop(t_cub *cub);

// Player movement and rotation
void	move_rotate(int key_code, t_cub *cub);
void rotate_player(t_cub *cub, int keycode);
int    mouse_move(int x, int y, t_cub *cub);

// MLX hooks
int		key_hook(int keycode, t_cub *cub);
int		close_win(t_cub *cub);

// Textures 
void    add_texture(t_cub *cub, int x, t_ray *ray);
void    init_textures(t_cub *cub);

// Floor ceiling
void    render_background(t_cub *cub);

// Minimap 
void	render_2d_map(t_cub *cub);
void render_player_and_fov(t_cub *cub);

// Utility functions
void	my_pixel_put(t_mlx *img, int x, int y, int color);

#endif