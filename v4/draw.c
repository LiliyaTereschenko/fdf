#include "fdf.h"

// void ft_iso(t_mlx *fdf)
// {
//     int i;
//     int j;
//     int x;
//     int y;
       
//     i = 0;
//     while (i < fdf->max_Y)
//     {
//         j = 0;
//         while (j < fdf->max_X)
//         {
//             x = (fdf->map)[i][j].x;
//             y = (fdf->map)[i][j].y;
//             (fdf->map)[i][j].x = ((x  - (fdf->map)[i][j].z) * cos(fdf->ang_X) + x) * (fdf->zoom);
//             (fdf->map)[i][j].y =  (y + (x + (fdf->map)[i][j].z) * sin(fdf->ang_Y)) * (fdf->zoom);
//             (fdf->map)[i][j].z =   (fdf->map)[i][j].z * (fdf->zoom);
//             j++;        
//         }
//         i++;
//     }

// }

void ft_change_matrix(t_mlx *fdf)
{
    int i;
    int j;
    int x;
    int y;
    int z;

    i = 0;
    while (i < fdf->max_Y)
    {
        j = 0;
        while (j < fdf->max_X)
        {
            x = (fdf->map)[i][j].x;
            y = (fdf->map)[i][j].y;
            z = (fdf->map)[i][j].z;
            (fdf->map_tmp)[i][j].x = (x * cos(fdf->ang_Y) * cos(fdf->ang_Z) -\
                        y * cos(fdf->ang_Y) * sin(fdf->ang_Z) + z * sin(fdf->ang_Y)) * (fdf->zoom) + fdf->start_X;
            (fdf->map_tmp)[i][j].y = (x * (sin(fdf->ang_X) * sin(fdf->ang_Y) * cos(fdf->ang_Z) +
                        cos(fdf->ang_X) * sin(fdf->ang_Z)) +\
                        y * (cos(fdf->ang_X) * cos(fdf->ang_Z) - sin(fdf->ang_X) * sin(fdf->ang_Y) * sin(fdf->ang_Z)) -\
                        z *  cos(fdf->ang_Y) * sin(fdf->ang_X)) * (fdf->zoom) + fdf->start_Y;
            (fdf->map_tmp)[i][j].z = (x * (sin(fdf->ang_X) * sin(fdf->ang_Z) - cos(fdf->ang_X) * sin(fdf->ang_Y) * cos(fdf->ang_Z)) +\
                        y * (cos(fdf->ang_X) * sin(fdf->ang_Y) * sin(fdf->ang_Z) + sin(fdf->ang_X) * cos(fdf->ang_Z) ) +\
                        z *  cos(fdf->ang_X) * cos(fdf->ang_Y)) * (fdf->zoom);
            j++;        
        }
        i++;
    }
}

void ft_draw_figure(t_point **map, t_mlx *fdf)
{
    int i;
    int j;
        
    i = 0;
    while (i < fdf->max_Y)
    {
        j = 0;
        while (j < fdf->max_X - 1)
        {
            line(map[i][j].x, map[i][j].y, map[i][j + 1].x, map[i][j + 1].y, fdf);
            j++;
        }
        i++;
    }
    j = 0;
    while (j < fdf->max_X)
    {
        i = 0;
        while (i < fdf->max_Y - 1)
        {
            line(map[i][j].x, map[i][j].y, map[i + 1][j].x, map[i + 1][j].y, fdf);
            i++;
        }
        j++;
    }
}
