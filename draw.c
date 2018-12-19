#include "fdf.h"

void ft_draw_figure(t_point **map, t_mlx *param)
{
    int i;
    int j;
    int start;
    int wide;
    i = 1;

    start = 0;
    wide = 10;
    printf("x_max = %d, y_max = %d\n", map[0][0].x, map[0][0].y);
    while (i < map[0][0].y + 1)
    {
        j = 0;
        while (j < map[0][0].x)
        {   
            map[i][j].x = (map[i][j].x) * wide + start;
            map[i][j].y = (map[i][j].y) * wide + start;
            j++;        
        }
        i++;
    }

 /*   i = 1;
    while (i < map[0][0].y + 1)
    {
        j = 0;
        while (j < map[0][0].x)
        {   
            printf("i = %d, j = %d, x = %d, y = %d\n", i,j,map[i][j].x, map[i][j].y);
            //line(map[i][j].x + start, map[i][j].y + start, map[i][j + 1].x + start, map[i][j + 1].y + start, param);
            //line(map[i][j].x, map[i][j].y, map[i + 1][j].x, map[i + 1][j].y, param);
            j++;
           
        }
        i++;
    }
*/
    i = 1;
    
    printf("x_max = %d, y_max = %d\n", map[0][0].x, map[0][0].y);
    while (i < map[0][0].y + 1)
    {
        j = 0;
        while (j < map[0][0].x - 1)
        {
            printf("a[ %d; %d ], b[ %d; %d ]\n", map[i][j].x, map[i][j].y, map[i][j + 1].x, map[i][j + 1].y);
            line(map[i][j].x, map[i][j].y, map[i][j + 1].x, map[i][j + 1].y, param);
            j++;
        }
        i++;
        printf("\n");
    }
    j = 0;
    while (j < map[0][0].x)
    {
        i = 1;
        while (i < map[0][0].y)
        {
            printf("a[ %d; %d ], b[ %d; %d ]\n", map[i][j].x, map[i][j].y, map[i + 1][j].x, map[i + 1][j].y);
            line(map[i][j].x, map[i][j].y, map[i + 1][j].x, map[i + 1][j].y, param);
            i++;
        }
        j++;
        printf("\n");
    }
}
