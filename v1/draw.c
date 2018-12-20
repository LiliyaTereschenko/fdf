#include "fdf.h"

void ft_draw_figure(t_point **map, t_mlx *param, t_rotation ang)
{
    int i;
    int j;
    int preX;
    int preY;
    int preZ;
    //int k = 3;
    int k = 10;
    int start = 100;
    
    i = 1;
    //printf("x_max = %d, y_max = %d\n", map[0][0].x, map[0][0].y);
    while (i < map[0][0].y + 1)
    {
        j = 0;
        while (j < map[0][0].x)
        {
            preX = map[i][j].x;
            preY = map[i][j].y;
            preZ = map[i][j].z;
            
            //povorot po osi x
            //ang.alpha = 1 * M_PI / 180;

            map[i][j].y = preY * cos(ang.alpha) + preZ * sin(ang.alpha);
            map[i][j].z = -preY * sin(ang.alpha) + preZ * cos(ang.alpha);

            //proekciya
            map[i][j].x = start + ((preX  - map[i][j].z) * cos(0.523599) + preX) * k ;
            map[i][j].y = start + (preY + (preX + map[i][j].z) * sin(0.523599)) * k ;

            // map[i][j].x = preX / (1 + map[i][j].z / cam_z);
            // map[i][j].y = preY / (1 + map[i][j].z / cam_z);

            //povorot na 30 grad
            // map[i][j].x = preX * cos(0.523599) - preY * sin(0.523599);
            // map[i][j].y = preX * sin(0.523599) + preY * cos(0.523599);
            j++;        
        }
        i++;
    }

    
    i = 1;
    //printf("x_max = %d, y_max = %d\n", map[0][0].x, map[0][0].y);
    while (i < map[0][0].y + 1)
    {
        j = 0;
        while (j < map[0][0].x - 1)
        {
            //printf("a[ %d; %d ], b[ %d; %d ]\n", map[i][j].x, map[i][j].y, map[i][j + 1].x, map[i][j + 1].y);
            line(map[i][j].x, map[i][j].y, map[i][j + 1].x, map[i][j + 1].y, param);
            j++;
        }
        i++;
        //printf("\n");
    }
    j = 0;
    while (j < map[0][0].x)
    {
        i = 1;
        while (i < map[0][0].y)
        {
            //printf("a[ %d; %d ], b[ %d; %d ]\n", map[i][j].x, map[i][j].y, map[i + 1][j].x, map[i + 1][j].y);
            line(map[i][j].x, map[i][j].y, map[i + 1][j].x, map[i + 1][j].y, param);
            i++;
        }
        j++;
        //printf("\n");
    }
}
