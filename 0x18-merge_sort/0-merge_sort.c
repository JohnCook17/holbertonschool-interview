#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void merge (int *a, int n, int m)
{
    int i, j, k;
    int n1 = m;
    int n2 = n - m;
    int *x = malloc(n * sizeof (int));

    int R[n1], L[n2];

    if (x == NULL)
        return;

    printf("Merging...\n");

    for (i = 0, j = m, k = 0; k < n; k++)
    {
        if (j == n)
        {
            x[k] = a[i];
            L[i] = x[k];
            i++;
        }
        else if (i == m)
        {
            x[k] = a[j];
            R[j] = x[k];
            j++;
        }
        else if (a[j] < a[i])
        {
            x[k] = a[j];
            R[j] = x[k];
            j++;
        }
        else
        {
            x[k] = a[i];
            L[i++] = x[k];
            i++;
        }
        /*
        x[k] = j == n      ? a[i++]
             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             :               a[i++];
        */
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    printf("[left]: ");
    print_array(L, m);
    printf("[right]: ");
    print_array(R, n - m);
    printf("[Done]: ");
    print_array(x, n);
    free(x);
    

}
 
void merge_sort (int *array, size_t size) {
    if (size < 2)
        return;
    int m = size / 2;
    merge_sort(array, m);
    merge_sort(array + m, size - m);
    merge(array, size, m);
}
