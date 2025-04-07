
#include "../so_long.h"


void end_game(mlx_game *var)
{
    free_map(var);
    mlx_close_window(var->mlx_init);  
}