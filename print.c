#include "fdf.h"

void ft_print_map(char **map)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (i < map[0][1])
    {
        j = 0;
        while (j < map[0][0])
        {
            ft_putnbr(ft_atoi(&map[i][j]));
            ft_putchar(' ');
            j++;

        }
        i++;
        ft_putchar('\n');
    }
}