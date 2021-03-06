#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "flexarray.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

/* erealloc is the exact same as emalloc except you add int *p as the first parameter before size_t s, and also *result = realloc(p, s) */

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
    }
    /* insert the item in the last free space */
}
void flexarray_print(flexarray f) {
    /* a "for" loop to print out each cell of f->items */
}
void flexarray_sort(flexarray f) {
    /* mergesort would be good */
}
void flexarray_free(flexarray f) {
    /* free the memory associated with the flexarray */
}
