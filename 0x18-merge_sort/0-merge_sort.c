#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    printf("Merging...\n");
    printf("[left]: ");
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
        if (i != 0)
        {
            printf(", ");
        }
        printf("%d", L[i]);
    }
    printf("\n");
    printf("[right]: ");
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
        if (j != 0)
        {
            printf(", ");
        }
        printf("%d", R[j]);
    }
    printf("\n");
    i = 0;
    j = 0;
    k = l;
    printf("[Done]: ");
    while (i < n1 && j < n2)
    {
        if (i != 0 || j != 0)
        {
            printf(", ");
        }
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        printf("%d", arr[k]);
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    if (k < r)
        printf("\n");
}


void mergesort(int arr[], int l, int r)
{
    int m;

    if (l < r)
    {
        m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


void merge_sort(int *array, size_t size)
{
    mergesort(array, 0, size - 1);
    printf(", %i\n", array[size - 1]);
}