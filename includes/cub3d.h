
#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
#include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <time.h>
# include "mlx.h"
# include "parse.h"
# include "execute.h"
# include "debug.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

//defines
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define PINK	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define GREY	"\033[0;37m"
# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

// PI and FOV
# define M_PI 3.14159265358979323846
# define FOV 60

// Window dimensions
# define WIN_WIDTH 1024
# define WIN_HEIGHT 768

// Minimap 
#define MINIMAP_SIZE       8
#define MINIMAP_TILE_SIZE  20
#define MINIMAP_OFFSET   5

// Movement constants
# define MOVE_SPEED 0.09
# define ROT_ANGLE 0.0524


// WASD and left/right arrows key codes
# define LARROW 65361
# define RARROW 65363

# define W      119
# define S    	115
# define A    	97
# define D   	100
# define ESC    65307

// MLX events
# define KEY_PRESS 2
# define MOUSE_MOVE 6
# define CLOSE 17

// Event masks
# define KEY_PRESS_MASK (1L<<0)
# define CLOSE_MASK (1L<<17)
# define MOUSE_MASK (1L<<6)

bool	print_error(char *msg);

#endif