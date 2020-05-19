#include <stdio.h>
#include <stdlib.h>
#include "sandpiles.h"

/**
 * 
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}
/**
 * 
 */
int topple(int grid1[3][3], int i, int j)
{
    switch(i)
    {
        case 0:
        {
            switch(j)
            {
                case 0:
                {
                    if (grid1[0][0] > 3)
                    {
                        grid1[0][1] =+ (grid1[0][0] - 3);
                        grid1[1][0] =+ (grid1[0][0] - 3);
                        grid1[0][0] -= 1;
                        __attribute__ ((fallthrough));
                    }
                    else
                        break;
                }
                case 1:
                {
                    if (grid1[0][1] > 3)
                    {
                        grid1[0][0] =+ (grid1[0][1] - 3);
                        grid1[1][1] =+ (grid1[0][1] - 3);
                        grid1[0][2] =+ (grid1[0][1] - 3);
                        grid1[0][1] -= 1;
                        __attribute__ ((fallthrough));
                    }
                    else
                        break;
                }
                case 2:
                {
                    if (grid1[0][2] > 3)
                    {
                        grid1[0][1] =+ (grid1[0][2] - 3);
                        grid1[1][2] =+ (grid1[0][2] - 3);
                        grid1[0][2] -= 1;
                        __attribute__ ((fallthrough));
                    }
                    else
                        break;
                }
            }
            __attribute__ ((fallthrough));
        }
        case 1:
        {
            switch(j)
            {
                case 0:
                {
                    if (grid1[1][0] > 3)
                    {
                        grid1[0][0] =+ (grid1[1][0] - 3);
                        grid1[1][1] =+ (grid1[1][0] - 3);
                        grid1[2][0] =+ (grid1[1][0] - 3);
                        grid1[1][0] -= 1;
                        __attribute__ ((fallthrough));
                    }
                    else
                        break;
                }
                case 1:
                {
                    if (grid1[1][1] > 3)
                    {
                        grid1[0][1] =+ (grid1[1][1] - 3);
                        grid1[1][2] =+ (grid1[1][1] - 3);
                        grid1[2][1] =+ (grid1[1][1] - 3);
                        grid1[1][0] =+ (grid1[1][1] - 3);
                        grid1[1][1] -= 1;
                        __attribute__ ((fallthrough));
                    }
                    else
                        break;
                }
                case 2:
                {
                    if (grid1[1][2] > 3)
                    {
                        grid1[0][2] =+ (grid1[1][2] - 3);
                        grid1[2][2] =+ (grid1[1][2] - 3);
                        grid1[1][1] =+ (grid1[1][2] - 3);
                        grid1[1][2] -= 1;
                        __attribute__ ((fallthrough));
                    }
                    else
                        break;
                }
            }
            __attribute__ ((fallthrough));
        }
        case 2:
        {
            switch(j)
            {
                case 0:
                {
                    if (grid1[2][0] > 3)
                    {
                        grid1[1][0] =+ (grid1[2][0] - 3);
                        grid1[2][1] =+ (grid1[2][0] - 3);
                        grid1[2][0] -= 1;
                        __attribute__ ((fallthrough));
                    }
                    else
                        break;
                }
                case 1:
                {
                    if (grid1[2][1] > 3)
                    {
                        grid1[2][0] =+ (grid1[2][1] - 3);
                        grid1[1][1] =+ (grid1[2][1] - 3);
                        grid1[2][2] =+ (grid1[2][1] - 3);
                        grid1[2][1] -= 1;
                        __attribute__ ((fallthrough));
                    }
                    else
                        break;
                }
                case 2:
                {
                    if (grid1[2][2] > 3)
                    {
                        grid1[1][2] =+ (grid1[2][2] - 3);
                        grid1[2][1] =+ (grid1[2][2] - 3);
                        grid1[2][2] -= 1;
                        __attribute__ ((fallthrough));;
                    }
                    else
                        break;
                }
            }
            __attribute__ ((fallthrough));
        }
    }
    return (grid1[3][3]);
}
/**
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[3][3] = topple(grid1, i, j);
            print_grid(grid1);
        }
    }
}