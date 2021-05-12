#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 10

void insertion_sort(int *a, int n) {
    /* Sorting code goes here */
    /* p = position */
    int i, p, key;

    for (p = 1; p < n; p++) {
        key = a[p];
        i = p-1;
        
        while (i >= 0 && a[i] > key){
            a[i+1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}

int main(void) {
    int my_array[ARRAY_MAX];
    int i, count = 0;
    clock_t start, end;
    
    printf("Enter some numbers, then press ctrl+d when done:\n");
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }

    start = clock();
    insertion_sort(my_array, count);
    end = clock();
    
    printf("Sorted arrray:\n");
    for (i = 0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "Count: %d, Time: %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
