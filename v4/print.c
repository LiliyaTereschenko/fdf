#include "fdf.h"

void ft_print_map(t_point **map, t_mlx *fdf)
{
    int i;
    int j;

    i = 0;
    //printf("x_max = %d, y_max = %d\n", map[0][0].x, map[0][0].y);
    while (i < fdf->max_Y)
    {
        j = 0;
        while (j < fdf->max_X)
        {
            printf("%d %d %d       ", map[i][j].x, map[i][j].y, map[i][j].z);
            j++;
        }
        i++;
        printf("\n");
    }
}
