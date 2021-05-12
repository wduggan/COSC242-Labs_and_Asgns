#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 10

void selection_sort(int *a, int n) {
    /* Sorting code goes here */
    /* p = position */
    int i, p, smallest, temp; 
  
    /* One by one move boundary of unsorted subarray */
    for (p = 0; p < n-1; p++) 
        { 
            /* Find the smallest element in unsorted array */ 
            smallest = p; 
            for (i = p+1; i < n; i++) {
                if (a[i] < a[smallest]) { 
                    smallest = i;
                }
            }
  
            /* Swap the found minimum element with the first element */
            temp = a[p];
            a[p] = a[smallest];
            a[smallest] = temp;
            /* swap(&arr[smallest], &arr[i]); */ 
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
    selection_sort(my_array, count);
    end = clock();
    
    printf("Sorted arrray:\n");
    for (i = 0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "Count: %d, time: %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
