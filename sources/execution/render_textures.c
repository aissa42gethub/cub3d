#include "cub3d.h"

void    load_texture(t_cub *cub, t_img *img, char *path)
{
    img->img = mlx_xpm_file_to_image(cub->mlx.mlx,
            path, &img->width, &img->height);
    if (!img->img)
    {
        printf("Error: failed to load texture %s\n", path);
        exit(1);
    }
    img->addr = mlx_get_data_addr(img->img, &img->bpp,
            &img->line_len, &img->endian);
}

void    init_textures(t_cub *cub)
{
    load_texture(cub, &cub->img_tex.no, cub->tex.no);
    load_texture(cub, &cub->img_tex.so, cub->tex.so);
    load_texture(cub, &cub->img_tex.we, cub->tex.we);
    load_texture(cub, &cub->img_tex.ea, cub->tex.ea);
}

static int get_tex_slice(t_cub *cub, t_ray *ray, t_img *tex)
{
    double wall_x;
    int    tex_slice;

    if (ray->side == 0)
        wall_x = cub->player.y + ray->corrected_dist * ray->ray_dir_y;
    else
        wall_x = cub->player.x + ray->corrected_dist * ray->ray_dir_x;
    wall_x -= floor(wall_x);
    tex_slice = (int)(wall_x * (double)tex->width);
    return (tex_slice);
}


 // --- choose correct wall texture based on ray direction ---
static t_img *choose_wall_texture(t_cub *cub, t_ray *ray)
{
    if (ray->side == 0)
    {
        if (ray->ray_dir_x > 0)
            return (&cub->img_tex.we);
        else
            return (&cub->img_tex.ea);
    }
    else
    {
        if (ray->ray_dir_y > 0)
            return (&cub->img_tex.so);
        else
            return (&cub->img_tex.no);
    }
}

void add_texture(t_cub *cub, int x, t_ray *ray)
{
    t_img   *tex;
    int     tex_slice;
    int     tex_y;
    int     y;
    double  step;
    double  tex_pos;
    char    *color;

    tex = choose_wall_texture(cub, ray);
    tex_slice = get_tex_slice(cub, ray, tex);
    step = (double)tex->height / ray->line_height;
    tex_pos = (ray->draw_start - WIN_HEIGHT / 2
                + ray->line_height / 2) * step; 
    y = ray->draw_start;
    while (y < ray->draw_end)
    {
        tex_y = (int)tex_pos % tex->height;
        tex_pos += step;
        color = tex->addr + (tex_y * tex->line_len + tex_slice * (tex->bpp / 8));
        my_pixel_put(&cub->mlx, x, y, *(unsigned int *)color);
        y++;
    }
}
