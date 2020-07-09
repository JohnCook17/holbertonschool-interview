#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menger.h"

/**
 * hollow - makes holes in the grid
 * @g: the grid struck to add holes to
 * Return: Null
 */
void hollow(grid g)
{
	int len = g.xe - g.xb + 1;
	int unit = len / 3;
	int i, j;

	for (i = g.xb + unit; i < g.xb + 2 * unit; i++)
	{
		for (j = g.yb + unit; j < g.yb + 2 * unit; j++)
		{
			g.base[j][i] = ' ';
		}
	}
}
/**
 * carpet - makes a carpet
 * @g: the grid carpet to make
 * @iter: controlls the flow of recursion
 * Return: returns when iter is 0
 */
void carpet(grid g, int iter)
{
	int i, j;
	int length;
	int unit;
	grid q;

	if (iter == 0)
	{
		return;
	}
	if (iter == 1)
	{
		hollow(g);
		carpet(g, 0);
	}
	hollow(g);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			length = g.xe - g.xb + 1;
			unit = length / 3;
			q.base = g.base;
			q.xb = g.xb + i * unit;
			q.xe = g.xb + (i + 1) * unit - 1;
			q.yb = g.yb + j * unit;
			q.ye = g.yb + (j + 1) * unit - 1;
			carpet(q, iter - 1);
		}
	}
}
/**
 * my_pow - UNLIMITED POWER! or at least exponets
 * @base: the base number
 * @expo: the exponent to use
 * Return: the base to the power
 */
int my_pow(int base, int expo)
{
	if (expo == 0)
		return (1);
	return (base * my_pow(base, expo - 1));
}
/**
 * allocate_g - allocates memory for the grid
 * @g: the triple pointer to grid
 * @n: the level
 * @sep: the char to use
 * Return: -1 on failure else size of grid
 */
int allocate_g(char ***g, int n, const char sep)
{
	int i, j;
	int size = my_pow(3, n);

	*g = (char **)calloc(size, sizeof(char *));
		if (*g == NULL)
			return (-1);

	for (i = 0; i < size; i++)
	{
		(*g)[i] = (char *)calloc(size, sizeof(char));
		if ((*g)[i] == NULL)
			return (-1);
		for (j = 0; j < size; j++)
		{
			(*g)[i][j] = sep;
		}
	}
	return (size);
}
/**
 * menger - calls functions and prints the grid
 * @level: how big to make the square
 * Return: exits if error or early exit required
 */
void menger(int level)
{
	char **base_grid;
	int size = allocate_g(&base_grid, level, '#');
	int i;
	grid b;

	if (level < 0)
		return;
	if (level == 0)
	{
		printf("#\n");
		return;
	}
	if (size == -1)
		return;
	b.base = base_grid;
	b.xb = 0;
	b.xe = size - 1;
	b.yb = 0;
	b.ye = size - 1;
	carpet(b, level);
	for (i = 0; i < size; i++)
	{
		printf("%s\n", base_grid[i]);
	}
	free(base_grid);

}
