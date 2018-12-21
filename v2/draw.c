#include "fdf.h"

void ft_move_to_center(t_mlx *fdf, t_point ***map)
{
    int i;
    int j;
    int preX;
    int preY;
    int preZ;
    
    i = 1;
    while (i < (*map)[0][0].y + 1)
    {
        j = 0;
        while (j < (*map)[0][0].x)
        {
            preX = (*map)[i][j].x;
            preY = (*map)[i][j].y;
            preZ = (*map)[i][j].z;
            
            (*map)[i][j].x = ((preX  - (*map)[i][j].z) * cos(0.523599) + preX) * (fdf->zoom); //fdf->win_size_x / 3 + 
            (*map)[i][j].y =  (preY + (preX + (*map)[i][j].z) * sin(0.523599)) * (fdf->zoom); //fdf->win_size_y / 3 +
            //printf(" i = %d\n", i);
            // map[i][j].x = preX / (1 + map[i][j].z / cam_z);
            // map[i][j].y = preY / (1 + map[i][j].z / cam_z);
            j++;        
        }
        i++;
    }

}

void ft_zoom(t_point ***map,t_mlx *fdf)
{
    int i;
    int j;
   
    i = 1;
    while (i < (*map)[0][0].y + 1)
    {
        j = 0;
        while (j < (*map)[0][0].x)
        {
            (*map)[i][j].x = (*map)[i][j].x * (fdf->zoom);
            (*map)[i][j].y = (*map)[i][j].y * (fdf->zoom);
            j++;        
        }
        i++;
    }
}

void ft_rotation_x(t_point ***map,t_mlx *fdf)
{
    int i;
    int j;
    int preY;
    int preZ;
    
    i = 1;
    while (i < (*map)[0][0].y + 1)
    {
        j = 0;
        while (j < (*map)[0][0].x)
        {
            preY = (*map)[i][j].y;
            preZ = (*map)[i][j].z;
            (*map)[i][j].y = preY * cos(fdf->ang_X) + preZ * sin(fdf->ang_X);
            (*map)[i][j].z = -preY * sin(fdf->ang_X) + preZ * cos(fdf->ang_X);
            j++;        
        }
        i++;
    }
}

void ft_rotation_y(t_point ***map, t_mlx *fdf)
{
    int i;
    int j;
    int preX;
    int preZ;
    
    i = 1;
    while (i < (*map)[0][0].y + 1)
    {
        j = 0;
        while (j < (*map)[0][0].x)
        {
            preX = (*map)[i][j].x;
            preZ = (*map)[i][j].z;
            (*map)[i][j].x = preX * cos(fdf->ang_Y) - preZ * sin(fdf->ang_Y);
            (*map)[i][j].z = preX * sin(fdf->ang_Y) + preZ * cos(fdf->ang_Y);
            j++;        
        }
        i++;
    }
}

void ft_rotation_z(t_point ***map, t_mlx *fdf)
{
    int i;
    int j;
    int preX;
    int preY;
    
    i = 1;
    while (i < (*map)[0][0].y + 1)
    {
        j = 0;
        while (j < (*map)[0][0].x)
        {
            preX = (*map)[i][j].x;
            preY = (*map)[i][j].y;
            (*map)[i][j].x = preX * cos(fdf->ang_Z) + preY * sin(fdf->ang_Z);
            (*map)[i][j].y = -preX * sin(fdf->ang_Z) + preY * cos(fdf->ang_Z);
            j++;        
        }
        i++;
    }
}

void ft_draw_figure(t_point **map, t_mlx *fdf)
{
    int i;
    int j;
        
    i = 1;
    //printf("x_max = %d, y_max = %d\n", map[0][0].x, map[0][0].y);
    while (i < map[0][0].y + 1)
    {
        j = 0;
        while (j < map[0][0].x - 1)
        {
            //printf("a[ %d; %d ], b[ %d; %d ]\n", map[i][j].x, map[i][j].y, map[i][j + 1].x, map[i][j + 1].y);
            line(map[i][j].x, map[i][j].y, map[i][j + 1].x, map[i][j + 1].y, fdf);
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
            line(map[i][j].x, map[i][j].y, map[i + 1][j].x, map[i + 1][j].y, fdf);
            i++;
        }
        j++;
        //printf("\n");
    }
}
