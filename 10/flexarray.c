#include <stdio.h>
#include <stdlib.h>

#include "flexarray.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

void *emalloc(size_t s) {
    void *result = malloc(s);
    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

/* erealloc is the exact same as emalloc except you add int *p as the first parameter before size_t s, and also *result = realloc(p, s) */
void *erealloc(int *p, size_t s) {
    void *result = realloc(p, s);
    if (NULL == result) {
        fprintf(stderr, "Memory reallocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}

void flexarray_append(flexarray f, int num) {
    if (f->itemcount == f->capacity) {
        /* do the old "double the capacity" trick */
        f->capacity += f->capacity;
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }
    /* insert the item in the last free space */
    f->items[f->itemcount++] = num;
}
void flexarray_print(flexarray f) {
    /* a "for" loop to print out each cell of f->items */
    int i;
    for (i = 0; i < f->itemcount; i++){
        printf("%d\n", f->items[i]);
    }
}
void flexarray_print_stderr(flexarray f) {
    /* a "for" loop to print out each cell of f->items */
    int i;
    for (i = 0; i < f->itemcount; i++){
        fprintf(stderr, "%d\n", f->items[i]);
    }
}
void flexarray_sort(flexarray f) {
    /* Quicksort */
    quicksort(f->items, f->itemcount);
}

void quicksort(int *a, int n){
    int i, j, pivot, temp;
    pivot = a[0];
    i = 0; /* First Position */
    j = n; /* Last Position */

    if (n < 2) {
        return;
    }

    if (i<j) {
        while (i<j) {
            while (a[i] <= a[pivot] && i<j)
                i++;
            while (a[j] > a[pivot])
                j--;
            if (i<j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;
        
        quicksort(a, n / 2);
        quicksort(a + (n/2), n - (n/2));

    }
}

void flexarray_free(flexarray f) {
    /* free the memory associated with the flexarray */
    free(f->items);
    free(f);
}
