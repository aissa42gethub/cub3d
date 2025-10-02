#include "cub3d.h"

void draw_ray(t_cub *cub, t_minimap *mm)
{
    double x;
    double y;
    double step_size;
    int    i;
    int    max_len;

    x = mm->line_start_x;
    y = mm->line_start_y;
    step_size = 0.5;
    i = 0;
    max_len = 30;
    while (i < max_len / step_size)
    {
        my_pixel_put(&cub->mlx, (int)x, (int)y, mm->ray_color);
        x += mm->ray_dir_x * step_size;
        y += mm->ray_dir_y * step_size;
        i++;
    }
}

static void cast_fov_rays(t_cub *cub, t_minimap *mm, int steps)
{
    int     i;
    double  t;

    mm->line_start_x = mm->player_x;
    mm->line_start_y = mm->player_y;
    mm->ray_color = 0x00FFFF;
    i = 0;
    while (i <= steps)
    {
        t = (double)i / steps;
        mm->ray_dir_x = cub->player.dir_x - cub->player.plane_x
                        + t * (2 * cub->player.plane_x);
        mm->ray_dir_y = cub->player.dir_y - cub->player.plane_y
                        + t * (2 * cub->player.plane_y);
        draw_ray(cub, mm);
        i++;
    }
}

void render_player_and_fov(t_cub *cub)
{
    t_minimap mm;
    int       x;
    int       y;
    int       steps;

    steps = 60;
    mm.player_x = (MINIMAP_SIZE / 2)
                  * MINIMAP_TILE_SIZE + MINIMAP_TILE_SIZE / 2;
    mm.player_y = (MINIMAP_SIZE / 2)
                  * MINIMAP_TILE_SIZE + MINIMAP_TILE_SIZE / 2;
    y = -3;
    while (y <= 3)
    {
        x = -3;
        while (x <= 3)
            my_pixel_put(&cub->mlx, mm.player_x + x++, mm.player_y + y, 0x00FF00);
        y++;
    }
    cast_fov_rays(cub, &mm, steps);
}
