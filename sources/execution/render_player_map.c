#include "cub3d.h"

void render_single_tile(t_cub *cub, int psx, int psy, int tile, int color)
{
    int i;
    int j;

    i = 0;
    while (i < tile)
    {
        j = 0;
        while (j < tile)
        {
            if (i == 0 || j == 0 || i == tile - 1 || j == tile - 1)
                my_pixel_put(&cub->mlx, psx + j, psy + i, 0x444444);
            else
                my_pixel_put(&cub->mlx, psx + j, psy + i, color);
            j++;
        }
        i++;
    }
}

void choose_color(t_cub *cub, int *color, int mx, int my)
{
    if (cub->map.point[my][mx] == '1')
        *color = 0x0000FF;
    else
        *color = 0x000000;
}

void which_tile(t_cub *cub, int mx, int my, int tile, int psx, int psy)
{
    int color;

    color = 0;
    if (mx >= 0 && mx < cub->map.w && my >= 0 && my < cub->map.h)
    {
        choose_color(cub, &color, mx, my);
        render_single_tile(cub, psx, psy, tile, color);
    }
    else
        render_single_tile(cub, psx, psy, tile, 0x444444);
}

static void render_tiles(t_cub *cub, int px, int py, int tile)
{
    int j;
    int i;
    int mx;
    int my;
    int psx;
    int psy;

    i = -MINIMAP_SIZE / 2;
    while (i < MINIMAP_SIZE / 2)
    {
        j = -MINIMAP_SIZE / 2;
        while (j < MINIMAP_SIZE / 2)
        {
            mx = px + j;
            my = py + i;
            psx = MINIMAP_OFFSET + (j + MINIMAP_SIZE / 2) * tile;
            psy = MINIMAP_OFFSET + (i + MINIMAP_SIZE / 2) * tile;
            which_tile(cub, mx, my, tile, psx, psy);
            j++;
        }
        i++;
    }
}

void render_2d_map(t_cub *cub)
{
    int px;
    int py;

    px = (int)cub->player.x;
    py = (int)cub->player.y;
    render_tiles(cub, px, py, MINIMAP_TILE_SIZE);
    render_player_and_fov(cub);
}
