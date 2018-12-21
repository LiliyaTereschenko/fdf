#include "fdf.h"

void ft_print_map(t_point **map)
{
    int i;
    int j;

    i = 1;
    printf(">>>>>>>>>>>>>>>\n");
    //printf("x_max = %d, y_max = %d\n", map[0][0].x, map[0][0].y);
    while (i < map[0][0].y + 1)
    {
        j = 0;
        while (j < map[0][0].x)
        {
            printf("%d %d %d       ", map[i][j].x, map[i][j].y, map[i][j].z);
            j++;
        }
        i++;
        printf("\n");
    }
}
