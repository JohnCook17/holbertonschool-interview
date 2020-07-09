#ifndef MENGER_H
#define MENGER_H

/**
 * struct Grid - the grid to print and use
 * @base: the base of the grid
 * @xb: x begin
 * @xe: x end
 * @yb: y begin
 * @ye: y end
 *
 * Description: a grid to use and print
*/
typedef struct Grid
{
	char **base;
	int xb, xe, yb, ye;
} grid;

void hollow(grid g);
void carpet(grid g, int iter);
int my_pow(int base, int expo);
int allocate_g(char ***g, int n, const char sep);
void menger(int level);

#endif /* MENGER_H */
